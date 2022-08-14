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

void	fillarray(const char *s, char c, char **array, int count)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < count - 1)
	{
		while (s[i] == c)
			i++;
		if (s[i] != c)
		{
			array[j++] = ft_substr(s + i, 0, ft_strchr(s + i, c) - (s + i));
			while (s[i] != c)
				i++;
		}
	}
	while (s[i] == c)
		i++;
	if (ft_strchr(s + i, c))
		array[count - 1] = ft_substr(s + i, 0, ft_strchr(s + i, c) - (s + i));
	else
		array[count - 1] = ft_substr(s + i, 0, ft_strlen(s + i));
}

int	wordcount(char const *s, char c)
{
	int	i;
	int	count;
	int	onsoc;

	i = 0;
	count = 0;
	onsoc = 0;
	while (s[i])
	{
		if (onsoc == 0 && s[i] != c)
		{
			count++;
			onsoc = 1;
		}
		else if (onsoc == 1 && s[i] == c)
			onsoc = 0;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		i;
	int		j;
	int		count;

	i = 0;
	j = 0;
	count = wordcount(s, c);
	if (!s)
		return (NULL);
	array = (char **)malloc((count + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	array[count] = NULL;
	if (count == 0)
		return (array);
	fillarray(s, c, array, count);
	return (array);
}
