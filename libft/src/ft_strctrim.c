/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strctrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 11:43:39 by fkao              #+#    #+#             */
/*   Updated: 2017/03/16 11:50:43 by fkao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strctrim(char const *s, char c)
{
	char	*start;
	char	*end;

	if (!s)
		return (NULL);
	start = (char*)s;
	end = (char*)s + ft_strlen(s) - 1;
	while (*start == c)
		start++;
	while (*end == c && end > start)
		end--;
	return (ft_strsub(start, 0, end - start + 1));
}
