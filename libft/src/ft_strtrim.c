/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 18:32:58 by fkao              #+#    #+#             */
/*   Updated: 2017/03/16 11:54:15 by fkao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*start;
	char	*end;

	if (!s)
		return (NULL);
	start = (char*)s;
	end = (char*)s + ft_strlen(s) - 1;
	while (ft_isspace(*start))
		start++;
	while (ft_isspace(*end) && end > start)
		end--;
	return (ft_strsub(start, 0, end - start + 1));
}
