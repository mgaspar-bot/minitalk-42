/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspar- <mgaspar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 10:52:48 by mgaspar-          #+#    #+#             */
/*   Updated: 2023/09/09 20:44:09 by mgaspar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	raise_flag(int signum)
{
	static int	messages = 0;

	(void)signum;
	messages++;
	ft_putnbr(messages);
	if (messages == 8)
	{
		write(1, "\n", 1);
		messages = 0;
	}
}

void	send_last_byte(int server_pid)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		kill(server_pid, SIGUSR1);
		pause();
		i++;
	}
	kill(server_pid, SIGUSR1);
}

/**
 * El problema esta quan la senyal de raise flag del server arriba ENTRE 
 * l'execucio de les linies 36 i 37 o 57/59 i 60
 * osigui entre que li diem al server aqui va un bit i ens posem a esperar
 * la resposta 
 * **/

void	send_next_byte(unsigned char current_char, int server_pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (current_char % 2 == 0)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		pause();
		current_char /= 2;
		i++;
	}
}

void	sender(int server_pid, char *str)
{
	char	current_char;

	if (ft_strlen(str) == 0)
		return ;
	while (*str)
	{
		current_char = (unsigned char)(*str);
		send_next_byte(current_char, server_pid);
		str++;
	}
	send_last_byte(server_pid);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (-1);
	signal(SIGUSR1, raise_flag);
	sender(ft_atoi(argv[1]), argv[2]);
	return (0);
}
