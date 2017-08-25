/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkao <fkao@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 17:55:53 by fkao              #+#    #+#             */
/*   Updated: 2017/08/24 12:52:09 by fkao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_bonus_flags(char arg)
{
	if (arg == 'A')
		g_flag.alm = 1;
	if (arg == 'T')
		g_flag.tim = 1;
	if (arg == 'f')
	{
		g_sort = 0;
		g_flag.a = 1;
		g_flag.r = 1;
	}
	if (arg == 'g')
	{
		g_flag.g = 1;
		g_flag.l = 1;
	}
	if (arg == 'o')
	{
		g_flag.o = 1;
		g_flag.l = 1;
	}
	if (arg == '1')
		g_flag.l = 0;
}

int		ls_flag(char *arg)
{
	while (*(++arg))
	{
		if (*arg == 'A' || *arg == 'R' || *arg == 'T' || *arg == 'a' ||
			*arg == 'f' || *arg == 'g' || *arg == 'l' || *arg == 'o' ||
			*arg == 'r' || *arg == 't' || *arg == '1')
		{
			if (*arg == 'R')
				g_flag.rec = 1;
			if (*arg == 'a')
				g_flag.a = 1;
			if (*arg == 'l')
				g_flag.l = 1;
			if (*arg == 'r')
				g_flag.r = 1;
			if (*arg == 't')
				g_sort = &sort_time;
			ls_bonus_flags(*arg);
		}
		else
			ls_error(arg, 1);
	}
	return (1);
}

void	ls_not_file(t_list *file)
{
	t_ftls	*stat;

	while (file)
	{
		stat = (t_ftls*)(file->content);
		if (stat->err)
			ft_printf("ls: %s: No such file or directory\n", stat->name);
		file = file->next;
	}
}

int		ls_parse_file(t_list *file)
{
	t_ftls	*stat;
	char	link[PATH_MAX];
	int		i;

	i = 0;
	while (file)
	{
		stat = (t_ftls*)(file->content);
		if ((stat->buf->st_mode & S_IFMT) == S_IFLNK)
		{
			link[readlink(stat->full, link, PATH_MAX)] = '\0';
			stat->err = lstat(link, stat->buf);
		}
		if (stat->buf->st_mode && (stat->buf->st_mode & S_IFMT) != S_IFDIR)
		{
			ls_print(stat);
			i = 1;
		}
		file = file->next;
	}
	return (i);
}

void	ls_build_arg(int ac, char **av)
{
	t_list	*file;
	t_ftls	*stat;
	int		i;

	file = NULL;
	i = 0;
	while (i < ac)
		ls_store(&file, av[i++], 0);
	ls_mergesort(&file, sort_alpha);
	ls_not_file(file);
	ls_mergesort(&file, g_sort);
	(g_flag.r) ? ft_lstrev(&file) : 0;
	i = ls_parse_file(file);
	while (file)
	{
		stat = (t_ftls*)(file->content);
		if ((stat->buf->st_mode & S_IFMT) == S_IFDIR)
		{
			(i) ? write(1, "\n", 1) : 0;
			(ac != 1) ? ft_printf("%s:\n", stat->name) : 0;
			ft_ls(stat->name);
			i = 1;
		}
		file = file->next;
	}
}
