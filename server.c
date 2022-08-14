/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspar- <mgaspar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 10:42:29 by mgaspar-          #+#    #+#             */
/*   Updated: 2022/08/14 11:51:17 by mgaspar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"./minitalk.h"

void	signal_handler(int sig)
{
	write(1, "got it!\n", sizeof("got it!\n"));
}

int	main(void)
{
	int	pid;

	signal(SIGUSR1, signal_handler);
	pid = getpid();
	write(1, "Server pid: ", sizeof("Server pid: "));
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	sleep(60);
	return (0);
}
