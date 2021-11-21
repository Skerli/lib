/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cskipjac <cskipjac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:53:53 by cskipjac          #+#    #+#             */
/*   Updated: 2021/10/27 18:55:25 by cskipjac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*e;
	t_list	*new_t_list;

	new_t_list = NULL;
	if (lst && f)
	{
		while (lst)
		{
			e = ft_lstnew((*f)(lst->content));
			if (!e)
			{
				while (new_t_list)
				{
					e = new_t_list->next;
					(*del)(new_t_list->content);
					free(new_t_list);
					new_t_list = e;
				}
			}
			ft_lstadd_back(&new_t_list, e);
			lst = lst->next;
		}
	}
	return (new_t_list);
}
