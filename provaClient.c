/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   provaClient.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspar- <mgaspar-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 13:52:23 by mgaspar-          #+#    #+#             */
/*   Updated: 2022/08/12 14:18:03 by mgaspar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>
#include<signal.h>

void sig_handler(int sig)
{
	if (sig == SIGSTOP)
	{
		write(1, "i don't want to stop\n", sizeof("i don't want to stop\n"));
	}
}

int main()
{
	write(1,"i'm the client\n",sizeof("i'm the client\n"));
	signal(SIGSTOP, sig_handler);

	return (0);
}
