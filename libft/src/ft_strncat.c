/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 12:21:35 by fkao              #+#    #+#             */
/*   Updated: 2017/03/03 13:07:37 by fkao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	l2;
	char	*ptr1;

	l2 = ft_strlen(s2);
	ptr1 = s1 + ft_strlen(s1);
	if (n > l2)
	{
		ft_memcpy(ptr1, s2, l2 + 1);
		*(ptr1 + l2) = '\0';
	}
	else
	{
		ft_memcpy(ptr1, s2, n);
		*(ptr1 + n) = '\0';
	}
	return (s1);
}
