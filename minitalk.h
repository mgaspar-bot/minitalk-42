/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspar- <mgaspar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 11:44:25 by mgaspar-          #+#    #+#             */
/*   Updated: 2023/09/11 12:14:29 by mgaspar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>

void	ft_putnbr(int n);
int		ft_power(int base, int power);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *nptr);
char	*ft_stradd(char *str, char c);

#endif
