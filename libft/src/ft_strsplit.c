/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 19:13:28 by fkao              #+#    #+#             */
/*   Updated: 2017/03/15 13:35:45 by fkao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	row;
	char	**t;

	if (!s || !(t = (char**)ft_memalloc(sizeof(*t) * (ft_countstr(s, c) + 1))))
		return (NULL);
	row = 0;
	while (*s)
	{
		i = 0;
		while (*s == c)
			s++;
		while (s[i] != c && s[i])
			i++;
		if (i)
			t[row++] = ft_strsub(s, 0, i);
		s += i;
	}
	t[row] = 0;
	return (t);
}
