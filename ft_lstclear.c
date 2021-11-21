/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cskipjac <cskipjac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 17:24:57 by cskipjac          #+#    #+#             */
/*   Updated: 2021/10/27 18:51:39 by cskipjac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*e;

	if (lst && del)
	{
		while (*lst)
		{
			e = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = e;
		}
	}
}
