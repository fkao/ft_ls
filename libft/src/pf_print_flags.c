/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkao <fkao@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 10:20:45 by fkao              #+#    #+#             */
/*   Updated: 2017/06/05 18:03:16 by fkao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	pf_put_sign(void)
{
	if (g_at.zero || g_at.width <= 0 || (g_at.prec >= g_at.width))
	{
		if (g_at.nbr < 0)
			retint_putchar('-');
		else if (g_at.nbr >= 0)
		{
			if (g_at.cross)
				retint_putchar('+');
			else if (g_at.space)
				retint_putchar(' ');
		}
		pf_put_width();
		pf_put_dot();
	}
	else
	{
		pf_put_width();
		if (g_at.nbr < 0)
			retint_putchar('-');
		else if (g_at.nbr >= 0 && g_at.cross)
			retint_putchar('+');
		pf_put_dot();
	}
}

void	pf_put_hash(void)
{
	if ((g_at.hash || g_at.spec == 'p') && g_at.zero)
	{
		if (g_at.spec == 'o' && (g_at.unlo > 0 || g_at.dot))
			retint_putchar('0');
		if ((g_at.spec == 'x' && g_at.unlo > 0) || g_at.spec == 'p')
		{
			if (g_at.caps)
				retint_putstr("0X");
			else
				retint_putstr("0x");
		}
	}
	pf_put_width();
	if ((g_at.hash || g_at.spec == 'p') && !g_at.zero)
	{
		if (g_at.spec == 'o' && (g_at.unlo > 0 || g_at.dot))
			retint_putchar('0');
		else if (g_at.caps && g_at.unlo > 0)
			retint_putstr("0X");
		else if (g_at.spec == 'p' || g_at.unlo > 0)
			retint_putstr("0x");
	}
	pf_put_dot();
}

void	pf_put_width(void)
{
	int		i;
	char	c;

	i = 0;
	c = ' ';
	if (g_at.zero && (!g_at.dot || g_at.spec == 'c' || g_at.spec == 's' ||
		g_at.spec == '%'))
		c = '0';
	if (!g_at.dash && (g_at.width > g_at.prec))
	{
		if (g_at.prec > g_at.count)
			while (i++ < (g_at.width - g_at.prec))
				retint_putchar(c);
		if (g_at.prec <= g_at.count)
			while (i++ < (g_at.width - g_at.count))
				retint_putchar(c);
	}
}

void	pf_put_dot(void)
{
	int	i;

	i = 0;
	while (i++ < (g_at.prec - g_at.count))
		retint_putchar('0');
}

void	pf_put_left(void)
{
	int	i;

	i = 0;
	if (g_at.prec > g_at.count)
		g_at.prec -= g_at.count;
	else if (g_at.prec <= g_at.count)
		g_at.prec = 0;
	if ((g_at.width > 0) && g_at.dash)
		while (i++ < (g_at.width - g_at.count - g_at.prec))
			retint_putchar(' ');
}
