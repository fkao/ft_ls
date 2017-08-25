/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_build.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkao <fkao@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 16:24:33 by fkao              #+#    #+#             */
/*   Updated: 2017/08/24 12:50:12 by fkao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_reset_len(void)
{
	g_total = 0;
	g_link = 0;
	g_size = 0;
}

void	ls_get_len(t_stat *buf)
{
	g_total += buf->st_blocks;
	if ((int)ft_intlen(buf->st_nlink) > g_link)
		g_link = ft_intlen(buf->st_nlink);
	if ((int)ft_intlen(buf->st_size) > g_size)
		g_size = ft_intlen(buf->st_size);
}

void	ls_store(t_list **file, char *name, char *path)
{
	t_ftls	*stat;

	stat = (t_ftls*)ft_memalloc(sizeof(*stat));
	stat->name = ft_strdup(name);
	stat->buf = malloc(sizeof(t_stat));
	stat->full = (path) ? ft_strjoin(path, stat->name) : ft_strdup(name);
	stat->err = lstat(stat->full, stat->buf);
	if (g_flag.l)
		ls_get_len(stat->buf);
	ft_lstadd(file, ft_lstnew(stat, sizeof(*stat)));
	ft_memdel((void**)&stat);
}

void	ls_error(char *arg, int i)
{
	if (i == 1)
	{
		ft_putstr_fd("./ft_ls: illegal option -- ", 2);
		ft_putendl_fd(&*arg, 2);
		ft_putendl_fd("usage: ./ft_ls [-ARTafglort1] [file ...]", 2);
		exit(1);
	}
	if (i == 2)
	{
		ft_printf("ls: %s: Permission denied\n", \
			(ft_strrchr(arg, '/')) ? ft_strrchr(arg, '/') + 1 : arg);
	}
}
