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

char	*ft_strtrim(char const *s1, char const *set)
{
	int	ppi;
	int	final;
	int	len;

	ppi = 0;
	final = ft_strlen(s1);
	if (!(*s1))
		return (ft_calloc(1, 1));
	while (ft_strchr(set, s1[ppi]))
		ppi++;
	while (ft_strchr(set, s1[final]))
		final--;
	len = final - ppi + 1;
	return (ft_substr(s1, ppi, len));
}
