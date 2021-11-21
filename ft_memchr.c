/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cskipjac <cskipjac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:27:02 by cskipjac          #+#    #+#             */
/*   Updated: 2021/10/18 20:43:35 by cskipjac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	ch;

	i = 0;
	a = (unsigned char *)s;
	ch = (unsigned char)c;
	while (i != n)
	{
		if (a[i] == ch)
			return ((void *)(a + i));
		i++;
	}
	return (NULL);
}
