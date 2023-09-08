/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspar- <mgaspar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 10:42:29 by mgaspar-          #+#    #+#             */
/*   Updated: 2023/09/08 20:55:17 by mgaspar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int g_finished = 0;

void	print8bits(int sig)
{
	static int				bit_counter = 0;
	static unsigned char	current_char = 0;

	if (sig == SIGUSR1)
		current_char += 0 * ft_power(2, bit_counter);
	else if (sig == SIGUSR2)
		current_char += 1 * ft_power(2, bit_counter);
	bit_counter++;
	//ft_putnbr(bit_counter);
	if (bit_counter == 8)
	{
		if (current_char == 0)
		{
			write(1, "\n", 1);
			write(1, "done with this message\n", 23);
			g_finished = 1;
		}
		else
		{
			write(1, &current_char, 1);
			bit_counter = 0;
			current_char = 0;
		}
	}
}

void	sigaction_handler(int signum, siginfo_t *info, void *context)
{
	static int	sender_pid = -1;

	(void)context;
	if (sender_pid == -1)
		sender_pid = info->si_pid;
	else if (sender_pid != info->si_pid)
		return ;
	print8bits(signum);
	//ft_putnbr(g_finished);
	if (!g_finished)
	{
		kill(sender_pid, SIGUSR1);
		sender_pid = -1;
	}
}
/**
 * Only talk to the first sender that sent you a message
*/

int	main(void)
{
	int					pid;
	struct sigaction	sigaction_struct;

	sigaction_struct.sa_flags = SA_SIGINFO;
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
