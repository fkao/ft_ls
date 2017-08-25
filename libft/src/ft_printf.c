/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkao <fkao@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 11:12:30 by fkao              #+#    #+#             */
/*   Updated: 2017/08/22 14:56:38 by fkao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_attr	g_at;

void	pf_reset_attr(void)
{
	g_at.spec = 0;
	g_at.width = 0;
	g_at.space = 0;
	g_at.zero = 0;
	g_at.cross = 0;
	g_at.dash = 0;
	g_at.hash = 0;
	g_at.dot = 0;
	g_at.prec = 0;
	g_at.length = 0;
	g_at.count = 0;
	g_at.caps = 0;
	g_at.nbr = 0;
	g_at.unlo = 0;
}

void	pf_branch_specifiers(va_list ap)
{
	pf_get_args(ap);
	if (g_at.spec == 's')
	{
		if (g_at.length != 'l')
			pf_print_unsigned(ap);
		if (g_at.length == 'l')
			pf_wide_characters(ap);
	}
	if (g_at.spec == 'd')
	{
		g_at.count = (g_at.dot && !g_at.nbr) ? 0 :
			(int)pf_ullen_base(ft_absl(g_at.nbr), 10);
		pf_width_correction();
		if (!g_at.dot || g_at.nbr)
			retint_putnbrul(ft_absl(g_at.nbr));
		pf_put_left();
	}
	if (g_at.spec == '%' || g_at.spec == 'c')
		pf_print_singlechar(ap);
	if (g_at.spec == 'u' || g_at.spec == 'o' || g_at.spec == 'x' ||
		g_at.spec == 'p')
	{
		pf_print_unsigned(ap);
		ft_strdel(&g_at.out);
	}
}

void	pf_print_nospec(char *fmt, va_list ap)
{
	char	c;
	int		i;

	pf_organize_length(fmt, ap);
	if (!g_at.spec)
	{
		c = (g_at.zero) ? '0' : ' ';
		while (*fmt)
		{
			if (!pf_ismodifier(*fmt))
				break ;
			fmt++;
		}
		i = 0;
		if ((g_at.width > 0) && !g_at.dash)
			while (i++ < (g_at.width - 1))
				retint_putchar(c);
		retint_putchar(*fmt);
		if ((g_at.width > 0) && g_at.dash)
			while (i++ < (g_at.width - 1))
				retint_putchar(' ');
	}
	else
		pf_branch_specifiers(ap);
}

void	pf_brake_format(const char *fmt, va_list ap)
{
	size_t	index;
	char	*tmp;

	while (*fmt)
	{
		if (*fmt == '%')
		{
			pf_reset_attr();
			index = 1;
			while (pf_ismodifier(fmt[index]))
				index++;
			tmp = ft_strsub(fmt, 1, index);
			if (!*tmp || (!ft_isprint(*(fmt + index))))
			{
				ft_strdel(&tmp);
				return ;
			}
			pf_print_nospec(tmp, ap);
			ft_strdel(&tmp);
			fmt += index;
		}
		else
			retint_putchar(*fmt);
		fmt++;
	}
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	g_at.ret = 0;
	pf_brake_format(format, ap);
	va_end(ap);
	return ((int)g_at.ret);
}
