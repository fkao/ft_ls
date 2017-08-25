/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 15:50:06 by fkao              #+#    #+#             */
/*   Updated: 2017/03/03 18:16:33 by fkao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*cdst;
	unsigned char	*csrc;

	cdst = (unsigned char*)dst;
	csrc = (unsigned char*)src;
	while (n > 0)
	{
		*cdst = *csrc;
		cdst++;
		if (*csrc == (unsigned char)c)
			return ((void*)cdst);
		csrc++;
		n--;
	}
	return (NULL);
}
