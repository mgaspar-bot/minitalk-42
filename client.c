/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspar- <mgaspar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 10:52:48 by mgaspar-          #+#    #+#             */
/*   Updated: 2023/09/11 14:22:04 by mgaspar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	send_correct_signal(char current_char, int s_pid)
{
	if (current_char % 2 == 0)
		kill(s_pid, SIGUSR1);
	else
		kill(s_pid, SIGUSR2);
	return (current_char / 2);
}

void	setvars(char *message, char **msg, int server_pid, int *s_pid)
{
	if (!(*msg))
		*msg = message;
	if (*s_pid == -1)
		*s_pid = server_pid;
}

int	send_bit(int server_pid, char *message)
{
	static char		*msg = NULL;
	static int		s_pid = -1;
	static char		current_char;
	static int		bit_counter = 0;

	setvars(message, &msg, server_pid, &s_pid);
	if (bit_counter == 8)
	{
		bit_counter = 0;
		msg++;
	}
	if (bit_counter == 0)
		current_char = *msg;
	if (*msg)
	{
		current_char = send_correct_signal(current_char, s_pid);
		bit_counter++;
	}
	else
	{
		kill(s_pid, SIGUSR1);
		if (++bit_counter == 8)
			return (1);
	}
	return (0);
}

void	handler(int signum)
{
	int	done;

	(void)signum;
	done = send_bit(0, 0);
	usleep(50);
	if (done)
		exit(0);
}

int	main(int argc, char **argv)
{
	struct sigaction	sigaction_struct;
	sigset_t			block_mask;

	if (argc != 3)
		return (-1);
	sigemptyset(&block_mask);
	sigaddset(&block_mask, SIGINT);
	sigaddset(&block_mask, SIGQUIT);
	sigaddset(&block_mask, SIGUSR1);
	sigaction_struct.sa_mask = block_mask;
	sigaction_struct.sa_handler = handler;
	sigaction(SIGUSR1, &sigaction_struct, NULL);
	send_bit(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}
