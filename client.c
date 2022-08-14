/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspar- <mgaspar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 10:52:48 by mgaspar-          #+#    #+#             */
/*   Updated: 2022/08/14 11:49:09 by mgaspar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

int	main(int argc, char **argv)
{
	int	server_pid;

	if (argc != 3)
		return (-1);
	server_pid = ft_atoi(argv[1]);
	kill(server_pid, SIGUSR1);
	return (0);
}
