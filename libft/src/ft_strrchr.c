/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 14:36:04 by fkao              #+#    #+#             */
/*   Updated: 2017/03/09 11:45:00 by fkao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*ptr;

	ptr = (char*)str + ft_strlen(str);
	while (ptr >= str)
	{
		if (*ptr == (char)c)
			return (ptr);
		ptr--;
	}
	return (NULL);
}
