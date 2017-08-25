/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkao <fkao@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 11:17:02 by fkao              #+#    #+#             */
/*   Updated: 2017/08/22 13:33:12 by fkao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int n, size_t base)
{
	char		*str;
	char		*ptr;
	size_t		len;
	const char	*t = "0123456789ABCDEF";
	long		nbr;

	if (base < 2 || base > 16)
		return (0);
	len = ft_intlen_base(n, base);
	str = ft_strnew(len);
	if (str)
	{
		if (n == 0)
			*str = '0';
		if (n < 0 && base == 10)
			*str = '-';
		nbr = (n < 0) ? (long)n * -1 : (long)n;
		ptr = str + len - 1;
		while (nbr)
		{
			*ptr-- = t[nbr % (long)base];
			nbr /= (long)base;
		}
	}
	return (str);
}
