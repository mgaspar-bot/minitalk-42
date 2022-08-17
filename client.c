/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspar- <mgaspar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 10:52:48 by mgaspar-          #+#    #+#             */
/*   Updated: 2022/08/17 11:53:04 by mgaspar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

void	sender(int server_pid, char *str)
{
	int		i;
	char	current_char;

	if (ft_strlen(str) == 0)
		return ;
	i = 0;
	while (*str)
	{
		current_char = (unsigned char)(*str);
		while (i < 8)
		{
			if (current_char % 2 == 0)
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			current_char /= 2;
			i++;
			usleep(100);
		}
		i = 0;
		str++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (-1);
	sender(ft_atoi(argv[1]), argv[2]);
	return (0);
}
