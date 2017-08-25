/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:05:45 by fkao              #+#    #+#             */
/*   Updated: 2017/03/09 10:33:50 by fkao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*cstr;

	cstr = (unsigned char*)str;
	while (n > 0)
	{
		if (*cstr == (unsigned char)c)
			return ((void*)cstr);
		cstr++;
		n--;
	}
	return (NULL);
}
