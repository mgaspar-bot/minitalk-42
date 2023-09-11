/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspar- <mgaspar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:03:27 by mgaspar-          #+#    #+#             */
/*   Updated: 2023/09/11 12:14:34 by mgaspar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr(int n)
{
	char	c;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n < 10)
	{
		c = n + '0';
		write(1, &c, 1);
		return ;
	}
	else if (n >= 10 && n <= 2147483647)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

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

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	num = 0;
	sign = 1;
	while (nptr[i] == ' ' || (9 <= nptr[i] && nptr[i] <= 13))
	{
		i++;
	}
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (48 <= nptr[i] && nptr[i] <= 57)
	{
		num = num * 10;
		num = num + (nptr[i] - 48);
		i++;
	}
	return (num * sign);
}

char	*ft_stradd(char *str, char c)
{
	char	*nstr;
	int		i;

	if (!str)
	{
		nstr = (char *)malloc(2 * sizeof(char));
		if (nstr == NULL)
			return (NULL);
		nstr[0] = c;
		nstr[1] = 0;
		return (nstr);
	}
	nstr = (char *)malloc((ft_strlen(str) + 2) * sizeof(char));
	if (nstr == NULL)
		return (NULL);
	*(nstr + ft_strlen(str) + 1) = 0;
	i = 0;
	while (str[i])
	{
		nstr[i] = str[i];
		i++;
	}
	nstr[i] = c;
	free(str);
	return (nstr);
}
