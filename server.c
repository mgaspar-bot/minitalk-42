/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspar- <mgaspar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 10:42:29 by mgaspar-          #+#    #+#             */
/*   Updated: 2022/08/15 12:48:23 by mgaspar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

static int bit_counter = 0;
static unsigned char current_char = 0;

int ft_power(int base, int power)
{
	int result;
	
	if (power < 0)
		return (0);
	result = 1;
	while (power)
	{
		result *= base;
		power--;
	}
	return (result);
}

void	signal_handler1(int sig)
{
	if (sig != SIGUSR1)
	{
		write(1, "wrong handler1 :(\n", sizeof("wrong handler1 :(\n"));
		return;
	}
	//write(1,"0",1);
	current_char += 0*ft_power(2, bit_counter);
	bit_counter++;
	if (bit_counter == 8)
	{
		write(1, &current_char, 1);
		bit_counter = 0;
		current_char = 0;
	}
}

void signal_handler2(int sig)
{
	if (sig != SIGUSR2)
	{
		write(1, "wrong handler2 :(\n", sizeof("wrong handler1 :(\n"));
		return;
	}
	//write(1,"1",1);
	current_char += 1*ft_power(2, bit_counter);
	bit_counter++;
	if (bit_counter == 8)
	{
		write(1, &current_char, 1);
		bit_counter = 0;
		current_char = 0;
	}
}

int	main(void)
{
	int	pid;

	signal(SIGUSR1, signal_handler1);
	signal(SIGUSR2, signal_handler2);
	pid = getpid();
	write(1, "Server pid: ", sizeof("Server pid: "));
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	while (1)
	{
		//write(1, "Server pid: ", sizeof("Server pid: "));
		//ft_putnbr_fd(pid, 1);
		//write(1, "\n", 1);
		sleep(9);
		//write(1, "im waiting\n", sizeof("im waiting\n"));
	}
	return (0);
}
