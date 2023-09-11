/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspar- <mgaspar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 10:42:29 by mgaspar-          #+#    #+#             */
/*   Updated: 2023/09/11 14:22:39 by mgaspar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	print8bits(int sig)
{
	static int				bit_counter = 0;
	static unsigned char	current_char = 0;

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
			write(1, "\n", 1);
			return (1);
		}
		else
		{
			write(1, &current_char, 1);
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
	if (!finished)
		kill(sender_pid, SIGUSR1);
	else
		sender_pid = -1;
}

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
