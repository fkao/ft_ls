/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 10:45:39 by fkao              #+#    #+#             */
/*   Updated: 2017/03/02 17:06:23 by fkao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*cstr;

	cstr = (unsigned char*)str;
	while (n > 0)
	{
		*cstr = (unsigned char)c;
		cstr++;
		n--;
	}
	return (str);
}
