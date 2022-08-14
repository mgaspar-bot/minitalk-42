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

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*little == 0)
		return ((char *)big);
	if (len == 0 || ft_strlen(little) > ft_strlen(big))
		return (NULL);
	if (len == 1)
		return (ft_strchr(big, *little));
	while (big[i] && i < len - 1)
	{
		if (big[i] == *little)
		{
			while (big [i + j] == little[j] && little[j] && i + j < len)
				j++;
			if (little[j] == 0)
				return ((char *)big + i);
			else
				j = 0;
		}
		i++;
	}
	return (NULL);
}

/*If	little is an empty string, big is returned; if little occurs nowhere
	 in	big, NULL is returned; otherwise a pointer to the first	character of
	 the first occurrence of little is returned.*/
