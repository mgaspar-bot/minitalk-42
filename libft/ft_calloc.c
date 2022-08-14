/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspar- <mgaspar-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:29:37 by mgaspar-          #+#    #+#             */
/*   Updated: 2022/03/05 22:38:09 by mgaspar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	unsigned char	*c;
	size_t			i;

	i = 0;
	ptr = malloc(nmemb * size * sizeof(char));
	if (!ptr)
		return (NULL);
	c = ptr;
	while (i < nmemb * size)
	{
		c[i] = 0;
		i++;
	}
	return (ptr);
}
