/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspar- <mgaspar-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:43:03 by mgaspar-          #+#    #+#             */
/*   Updated: 2022/03/05 22:52:35 by mgaspar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

/*
quantes xifres?
reserva memoria
escriu
*/

void	putstr(int n, char *str)
{
	int	magn;
	int	i;

	magn = 1;
	i = 0;
	while (n > magn)
	{
		magn *= 10;
		if (magn == 1000000000)
			break ;
	}
	if (n < magn)
		magn = magn / 10;
	while (magn)
	{
		str[i] = (n / magn) + 48;
		n = n % magn;
		magn = magn / 10;
		i++;
	}
}

int	xifres(int n)
{
	int	magn;
	int	xifres;

	magn = 1;
	xifres = 1;
	if (n >= 1000000000)
		return (10);
	while (n > magn)
	{
		magn *= 10;
		xifres++;
	}
	if (n < magn)
		xifres--;
	return (xifres);
}

int	calculate_sign(int n)
{
	int	sign;

	sign = 0;
	if (n < 0)
	{
		sign = 1;
	}
	return (sign);
}

char	*ft_itoa(int n)
{
	int		sign;
	char	*str;

	sign = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	sign = calculate_sign(n);
	if (n < 0)
		n = -n;
	if (sign)
	{
		str = (char *)malloc((xifres(n) + 2) * sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '-';
	}
	else
		str = (char *)malloc((xifres(n) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[xifres(n) + sign] = 0;
	putstr(n, str + sign);
	return (str);
}

/* int main(){
  //  printf("\n%d", xifres(1995));
	printf("\n%s ", ft_itoa(-10000));
	return(0);
} */

/* Reserva con malloc(3) y devuelve una string que representa el número 
dado como argumento.
 Los números negativos deben gestionarse correctamente. */