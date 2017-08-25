/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 13:25:09 by fkao              #+#    #+#             */
/*   Updated: 2017/03/02 16:50:36 by fkao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*cdst;
	char	*csrc;

	cdst = (char*)dst;
	csrc = (char*)src;
	while (n > 0)
	{
		*cdst++ = *csrc++;
		n--;
	}
	return (dst);
}
