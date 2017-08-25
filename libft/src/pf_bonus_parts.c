/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_bonus_parts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkao <fkao@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 11:53:25 by fkao              #+#    #+#             */
/*   Updated: 2017/06/05 16:30:58 by fkao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_handle_wild(va_list ap)
{
	g_at.width = va_arg(ap, int);
	if (g_at.width < 0)
	{
		g_at.dash = 1;
		g_at.width *= -1;
	}
}

void	pf_wild_precision(va_list ap)
{
	g_at.prec = va_arg(ap, int);
	g_at.dot = (g_at.prec) ? 0 : 1;
	if (g_at.prec < 0)
		g_at.prec = g_at.prec / 10 % 10;
}
