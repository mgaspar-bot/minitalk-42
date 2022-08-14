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

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lastelement;

	while (*lst)
	{
		lastelement = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(lastelement, del);
	}
	lst = NULL;
}
