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

char	*ft_strrchr(const char *s, int c)
{
	char	*ppi;

	ppi = (char *)s;
	while (*s)
		s++;
	while (s >= ppi)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s--;
	}
	return (NULL);
}
