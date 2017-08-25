/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 10:28:58 by fkao              #+#    #+#             */
/*   Updated: 2017/03/10 12:14:59 by fkao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*ptrd;
	unsigned char	*ptrs;

	ptrd = (unsigned char*)dst + n - 1;
	ptrs = (unsigned char*)src + n - 1;
	if (dst < src)
		return (ft_memcpy(dst, src, n));
	while (n > 0)
	{
		*ptrd-- = *ptrs--;
		n--;
	}
	return (dst);
}
