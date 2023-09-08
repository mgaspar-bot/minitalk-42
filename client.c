/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspar- <mgaspar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 10:52:48 by mgaspar-          #+#    #+#             */
/*   Updated: 2023/09/08 21:01:17 by mgaspar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int g_next_bit_requested;

void	raise_flag(int signum)
{
	//write(1, "F", 1);
	if (signum == SIGUSR1)
		g_next_bit_requested = 1;
}

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
		current_char /= 2;
		//ft_putnbr(current_char);
		while (!g_next_bit_requested)
		{
			usleep(0);
		}
		g_next_bit_requested = 0;
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
	send_next_byte(0, server_pid);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (-1);
	signal(SIGUSR1, raise_flag);
	sender(ft_atoi(argv[1]), argv[2]);
	return (0);
}
