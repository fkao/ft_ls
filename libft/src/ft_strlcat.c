/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 13:08:10 by fkao              #+#    #+#             */
/*   Updated: 2017/03/07 10:31:41 by fkao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	ld;
	char	*ptrd;

	ld = ft_strlen(dst);
	ptrd = dst + ld;
	if (n > ld)
	{
		ft_bzero(ptrd, n - ld);
		ft_memcpy(ptrd, src, n - ld - 1);
		return (ld + ft_strlen(src));
	}
	else
		return (n + ft_strlen(src));
}
