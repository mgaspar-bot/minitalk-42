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

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*nova;
	size_t	talla;
	size_t	i;

	talla = (ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	nova = (char *)malloc(talla * sizeof(char));
	if (!nova)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		nova[i] = s1[i];
		i++;
	}
	while (i < talla - 1)
	{
		nova[i] = *s2;
		i++;
		s2++;
	}
	nova[i] = 0;
	return (nova);
}
