/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspar- <mgaspar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 10:42:29 by mgaspar-          #+#    #+#             */
/*   Updated: 2022/08/17 11:45:49 by mgaspar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

int	ft_power(int base, int power)
{
	int	result;

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

void	signal_handler(int sig)
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
		if (current_char == 0)
			write(1, "\n", 1);
		write(1, &current_char, 1);
		bit_counter = 0;
		current_char = 0;
	}
}

int	main(void)
{
	int	pid;

	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	pid = getpid();
	write(1, "Server pid: ", sizeof("Server pid: "));
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	while (1)
		sleep(9);
	return (0);
}
