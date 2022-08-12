/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prova.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspar- <mgaspar-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 12:55:35 by mgaspar-          #+#    #+#             */
/*   Updated: 2022/08/12 14:17:59 by mgaspar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<signal.h>
#include<stdio.h>

int main (int argc, char **argv) 
{
	if (argc != 2)
	{
		write(1,"i need 1 arg", sizeof("i need 1 arg"));
		return -1;
	}
	execl("./client", argv[1]); 
	/*
	 *Exec functions substitute the current program with their parameter
	 so the pid is the same, but i can't send signals with that.
	 Plus exec is not allowed in the subject so this is not the way xD
	 */

	return 0;
}
