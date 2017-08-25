/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkao <fkao@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 18:29:15 by fkao              #+#    #+#             */
/*   Updated: 2017/06/21 18:48:09 by fkao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_isspecifier(int c)
{
	return (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' ||
		c == 'X' || c == 'D' || c == 'O' || c == 'U' || c == 's' || c == 'S' ||
		c == 'c' || c == 'C' || c == 'p' || c == '%' || c == 'e' || c == 'E' ||
		c == 'f' || c == 'F' || c == 'a' || c == 'A' || c == 'g' || c == 'G' ||
		c == 'n');
}

int		pf_ismodifier(int c)
{
	return (ft_isdigit(c) || c == ' ' || c == '+' || c == '-' || c == '#' ||
		c == '.' || c == 'h' || c == 'l' || c == 'j' || c == 'z' || c == '*');
}

size_t	pf_ullen_base(unsigned long nbr, size_t base)
{
	size_t	i;

	i = 0;
	if (nbr == 0)
		i++;
	while (nbr)
	{
		i++;
		nbr /= base;
	}
	return (i);
}

char	*pf_ultoa_base(unsigned long value, size_t base)
{
	char		*str;
	char		*ptr;
	int			len;
	const char	*t = "0123456789abcdef";
	const char	*u = "0123456789ABCDEF";

	len = pf_ullen_base(value, base);
	str = ft_strnew(len);
	if (value == 0)
		*str = '0';
	ptr = str + len;
	*ptr-- = '\0';
	while (value)
	{
		*ptr = (g_at.caps) ? u[value % base] : t[value % base];
		value /= base;
		ptr--;
	}
	return (str);
}

size_t	pf_wstrlen(wchar_t *str)
{
	size_t	len;

	len = 0;
	while (*str)
	{
		if (*str <= 0x7F)
			len += 1;
		else if (*str <= 0x7FF)
			len += 2;
		else if (*str <= 0xFFFF)
			len += 3;
		else if (*str <= 0x10FFFF)
			len += 4;
		str++;
	}
	return (len);
}
