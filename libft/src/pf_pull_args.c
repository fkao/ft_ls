/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_pull_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkao <fkao@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 14:19:29 by fkao              #+#    #+#             */
/*   Updated: 2017/06/21 17:07:13 by fkao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

void	pf_signed_conversions(va_list ap)
{
	short	shrt;
	char	hhd;

	if (g_at.spec == 'd')
	{
		if (g_at.length == 'l')
			g_at.nbr = va_arg(ap, long);
		else if (g_at.length == 'h')
		{
			shrt = (short)va_arg(ap, int);
			g_at.nbr = (long)shrt;
		}
		else if (g_at.length == 'H')
		{
			hhd = (char)va_arg(ap, int);
			g_at.nbr = (long)hhd;
		}
		else if (!g_at.length)
			g_at.nbr = (long)va_arg(ap, int);
	}
}

void	pf_get_args(va_list ap)
{
	unsigned short	unsh;
	unsigned char	uchr;

	pf_signed_conversions(ap);
	if (g_at.spec == 'o' || g_at.spec == 'u' || g_at.spec == 'x')
	{
		if (g_at.length == 'l')
			g_at.unlo = (unsigned long)va_arg(ap, unsigned long);
		else if (g_at.length == 'h')
		{
			unsh = (unsigned short)va_arg(ap, unsigned int);
			g_at.unlo = (unsigned long)unsh;
		}
		else if (g_at.length == 'H')
		{
			uchr = (unsigned char)va_arg(ap, unsigned int);
			g_at.unlo = (unsigned long)uchr;
		}
		else if (!g_at.length)
			g_at.unlo = (unsigned long)va_arg(ap, unsigned int);
	}
	if (g_at.spec == 'p')
		g_at.unlo = (unsigned long)va_arg(ap, void*);
}

void	pf_wide_characters(va_list ap)
{
	wchar_t	*wstr;

	wstr = va_arg(ap, wchar_t*);
	if (wstr == NULL)
	{
		g_at.count = 5;
		pf_width_correction();
		retint_putstr("(null)");
		pf_put_left();
		return ;
	}
	g_at.count = pf_wstrlen(wstr);
	pf_width_correction();
	retint_putwstr(wstr, g_at.count);
	pf_put_left();
}

void	pf_print_unsigned(va_list ap)
{
	if (g_at.spec == 'u')
		g_at.out = pf_ultoa_base(g_at.unlo, 10);
	if (g_at.spec == 'o')
		g_at.out = pf_ultoa_base(g_at.unlo, 8);
	if (g_at.spec == 'x' || g_at.spec == 'p')
		g_at.out = pf_ultoa_base(g_at.unlo, 16);
	if (g_at.spec == 's')
	{
		g_at.out = (va_arg(ap, char*));
		if (g_at.out == NULL)
			g_at.out = "(null)";
		else if (g_at.out == NULL && g_at.dot)
			g_at.out = "0";
	}
	g_at.count = (g_at.dot && !g_at.unlo && g_at.spec != 's')
		? 0 : ft_strlen(g_at.out);
	pf_width_correction();
	if (!g_at.dot || g_at.unlo || g_at.spec == 's')
		retint_putstr(g_at.out);
	pf_put_left();
}

void	pf_print_singlechar(va_list ap)
{
	wchar_t	wchr;

	if (g_at.length == 'l' && g_at.spec == 'c' && MB_CUR_MAX != 1)
	{
		wchr = (wchar_t)va_arg(ap, wint_t);
		if (wchr <= 0x7F)
			g_at.count = 1;
		else if (wchr <= 0x7FF)
			g_at.count = 2;
		else if (wchr <= 0xFFFF)
			g_at.count = 3;
		else if (wchr <= 0x10FFFF)
			g_at.count = 4;
	}
	else
	{
		wchr = (g_at.spec == 'c') ? (char)va_arg(ap, int) : '%';
		g_at.count = 1;
	}
	g_at.prec = 0;
	pf_put_width();
	retint_putwchar(wchr);
	pf_put_left();
}
