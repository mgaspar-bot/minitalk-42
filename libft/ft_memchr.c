/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspar- <mgaspar-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:53:12 by mgaspar-          #+#    #+#             */
/*   Updated: 2022/03/05 22:55:54 by mgaspar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*cs;

	i = 0;
	cs = (unsigned char *)s;
	if (n == 0)
		return (NULL);
	while (cs[i] != (unsigned char)c && i + 1 < n)
		i++;
	if (cs[i] == (unsigned char)c)
		return ((void *)cs + i);
	else
		return (NULL);
}
