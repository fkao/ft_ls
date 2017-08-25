/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 17:34:54 by fkao              #+#    #+#             */
/*   Updated: 2017/03/09 11:01:25 by fkao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	new = ft_strnew(ft_strlen(s));
	if (new == '\0')
		return (NULL);
	while (s[i])
	{
		new[i] = f(s[i]);
		i++;
	}
	return (new);
}
