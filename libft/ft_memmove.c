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

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char			*d;
	const char		*s;
	char			*lasts;
	char			*lastd;

	d = dest;
	s = src;
	lasts = (char *)s + (n - 1);
	lastd = (char *)d + (n - 1);
	if (!dest && !src)
		return (NULL);
	if (d < s)
		while (n--)
			*d++ = *s++;
	else
		while (n--)
			*lastd-- = *lasts--;
	return (dest);
}
