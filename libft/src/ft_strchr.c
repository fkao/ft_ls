/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 13:50:17 by fkao              #+#    #+#             */
/*   Updated: 2017/03/09 11:44:44 by fkao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	if (c == '\0')
		return ((char*)str + ft_strlen(str));
	while (*str != '\0')
	{
		if (*str == (char)c)
			return ((char*)str);
		str++;
	}
	return (NULL);
}
