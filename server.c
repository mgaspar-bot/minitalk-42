/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspar- <mgaspar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 10:42:29 by mgaspar-          #+#    #+#             */
/*   Updated: 2023/09/11 13:21:48 by mgaspar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	print8bits(int sig)
{
	static int				bit_counter = 0;
	static unsigned char	current_char = 0;
	//static char				*buffer = NULL;

	if (sig == SIGUSR1)
		current_char += 0 * ft_power(2, bit_counter);
	else if (sig == SIGUSR2)
		current_char += 1 * ft_power(2, bit_counter);
	bit_counter++;
	if (bit_counter == 8)
	{
		bit_counter = 0;
		if (current_char == 0)
		{
			//write(1, buffer, ft_strlen(buffer));
			//free(buffer);
			//buffer = NULL;
			write(1, "\n", 1);
			write(1, "done with this message\n", 23);
			return (1);
		}
		else
		{
			write(1, &current_char, 1);
			//buffer = ft_stradd(buffer, current_char);
			//if (!buffer)
				//return (-1);
			current_char = 0;
			return (0);
		}
	}
	return (0);
}

void	sigaction_handler(int signum, siginfo_t *info, void *context)
{
	static int	sender_pid = -1;
	int			finished;

	(void)context;
	if (sender_pid == -1)
		sender_pid = info->si_pid;
	else if (sender_pid != info->si_pid)
	{
		return ;
	}
	finished = print8bits(signum);
	
	/**
	 * El problema segueix sent que aquesta senyal de vegades s'envia
	 * ABANS que el client s'hagi pausat, de manera que el client es queda esperant
	 * una senyal que ja ha handlejat.
	 * Si poso un usleep molt baix, es queden atrapats molt aviat.
	 * Si poso un usleep molt alt (20000 p.ex.) el server triga molt escrivint
	 * i despres d'una bona estona segueix passant el mateix...
	 * 
	 *  Com collons ho soluciono?
	 * **/
	if (!finished)
		kill(sender_pid, SIGUSR1);
	else
		sender_pid = -1;
}
/**
 * Only talk to the first sender that sent you a message until you are 
 * done with that message
*/

int	main(void)
{
	int					pid;
	struct sigaction	sigaction_struct;
	sigset_t			block_mask;

	sigemptyset(&block_mask);
	sigaddset(&block_mask, SIGINT);
	sigaddset(&block_mask, SIGQUIT); 
	sigaction_struct.sa_handler = 0;
	sigaction_struct.sa_flags = SA_SIGINFO;
	sigaction_struct.sa_mask = block_mask;
	sigaction_struct.sa_sigaction = sigaction_handler;
	sigaction(SIGUSR1, &sigaction_struct, NULL);
	sigaction(SIGUSR2, &sigaction_struct, NULL);
	pid = getpid();
	write(1, "Server pid: ", sizeof("Server pid: "));
	ft_putnbr(pid);
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
