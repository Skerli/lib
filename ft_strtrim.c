/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cskipjac <cskipjac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:48:57 by cskipjac          #+#    #+#             */
/*   Updated: 2021/10/20 17:49:27 by cskipjac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	le(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	q;

	i = 0;
	while (s1[i])
	{
		j = 0;
		q = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				q = 1;
				break ;
			}
			j++;
		}
		if (q != 1)
			return (i);
		i++;
	}
	return (-1);
}

static int	ri(char const *s1, char const *set)
{
	size_t	iq;
	int		j;
	int		q;
	int		i;

	iq = ft_strlen(s1);
	i = iq;
	i--;
	while (i != -1)
	{
		j = 0;
		q = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				q = 1;
			if (s1[i] == set[j])
				break ;
			j++;
		}
		if (q == 0)
			return (i);
		i--;
	}
	return (-1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		l;
	int		r;

	if (!s1 || !set)
		return (NULL);
	l = le(s1, set);
	r = ri(s1, set);
	str = malloc(sizeof(char) * (ri(s1, set) - le(s1, set) + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (l != (r + 1))
		str[i++] = s1[l++];
	str[i] = '\0';
	return (str);
}
