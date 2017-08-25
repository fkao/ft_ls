/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_put_retint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkao <fkao@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 13:45:40 by fkao              #+#    #+#             */
/*   Updated: 2017/05/31 18:05:46 by fkao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	retint_putchar(char c)
{
	write(1, &c, 1);
	g_at.ret += 1;
}

void	retint_putstr(char *s)
{
	write(1, s, ft_strlen(s));
	g_at.ret += ft_strlen(s);
}

void	retint_putwchar(wchar_t chr)
{
	if (chr <= 0x7F)
		retint_putchar(chr);
	else if (chr <= 0x7FF)
	{
		retint_putchar((chr >> 6) + 0xC0);
		retint_putchar((chr & 0x3F) + 0x80);
	}
	else if (chr <= 0xFFFF)
	{
		retint_putchar((chr >> 12) + 0xE0);
		retint_putchar(((chr >> 6) & 0x3F) + 0x80);
		retint_putchar((chr & 0x3F) + 0x80);
	}
	else if (chr <= 0x10FFFF)
	{
		retint_putchar((chr >> 18) + 0xF0);
		retint_putchar(((chr >> 12) & 0x3F) + 0x80);
		retint_putchar(((chr >> 6) & 0x3F) + 0x80);
		retint_putchar((chr & 0x3F) + 0x80);
	}
}

void	retint_putwstr(wchar_t *str, size_t len)
{
	size_t	i;

	i = 0;
	while (*str && i < len)
	{
		if (*str <= 0x7F)
			i++;
		else if (*str <= 0x7FF)
			i += 2;
		else if (*str <= 0xFFFF)
			i += 3;
		else if (*str <= 0x10FFFF)
			i += 4;
		if (i <= len)
			retint_putwchar(*str++);
	}
}

void	retint_putnbrul(unsigned long n)
{
	if (n > 9)
	{
		retint_putnbrul(n / 10);
		retint_putnbrul(n % 10);
	}
	else
		retint_putchar(n + '0');
}
