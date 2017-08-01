/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkao <fkao@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 12:30:42 by fkao              #+#    #+#             */
/*   Updated: 2017/08/01 15:09:18 by fkao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

t_attr	g_attr;

void	ls_sort_alpha(char **name, int count)
{
	int		i;
	char	*tmp;

	i = 0;
	while (i < count - 1)
	{
		if (ft_strcmp(name[i], name[i + 1]) > 0)
		{
			ft_strswap(&name[i], &name[i + 1]);
			i = -1;
		}
		i++;
	}
}

void	ft_ls(char *direct)
{
	int		i;
	t_ftls	*e;

	e = (t_ftls*)ft_memalloc(sizeof(*e));
	e->path = ft_strjoin(direct, "/");
	e->count = ls_dir_len(e->path);
	e->name = ls_file_stack(e->path, e->count);
	ls_sort_alpha(e->name, e->count);
	e->mode = ls_mode_stack(e->path, e->name, e->count);
	i = 0;
	if (ft_strcmp(direct, "."))
	{
		ft_putstr(direct);
		ft_putendl(":");
	}
	while (i < e->count)
	{
		if (e->name[i][0] != '.')
			ft_putendl(e->name[i]);
		i++;
	}
	if (g_attr.R)
		ls_recurse_sd(e->path, e->name, e->mode, e->count);
	ft_strdel(&e->path);
	ft_vecdel((void**)e->mode, e->count);
	free(e->name);
	free(e);
}

int		ftls_isoption(int c)
{
	return (c == 'l' || c == 'R' || c == 'a' || c == 'r' || c == 't');
}

int		ls_parse_options(char *arg)
{
	while (*(++arg))
	{
		if (ftls_isoption(*arg))
		{
			g_attr.l = (*arg == 'l') ? 1 : g_attr.l;
			g_attr.R = (*arg == 'R') ? 1 : g_attr.R;
			g_attr.a = (*arg == 'a') ? 1 : g_attr.a;
			g_attr.r = (*arg == 'r') ? 1 : g_attr.r;
			g_attr.t = (*arg == 't') ? 1 : g_attr.t;
		}
		if (!ftls_isoption(*arg))
		{
			ft_putstr("./ft_ls: illegal option -- ");
			ft_putendl(&*arg);
			ft_putendl("usage: ./ft_ls [-Ralrt] [file ...]");
			return (0);
		}
	}
	return (1);
}

int		main(int ac, char **av)
{
	int	i;
	int	j;
	int	count;
	char	**name;
	char	**mode;

	i = 1;
	j = 0;
	while (i < ac)
	{
		if (av[i][0] == '-' && ft_strlen(av[i]) != 1 && !g_attr.start)
		{
			if (!ls_parse_options(av[i]))
				return (0);
		}
		else
		{
			if (!g_attr.start)
				name = (char**)ft_memalloc(sizeof(char*) * (ac - i + 1));
			g_attr.start = 1;
			name[j++] = av[i];
			count++;
		}
		i++;
	}
	if (!g_attr.start)
		ft_ls(".");
	else
	{
		ls_sort_alpha(name, count);
		mode = ls_mode_stack("./", name, count);
		i = 0;
		while (i < count)
		{
			if (open(name[i], O_RDONLY) == -1)
			{
				ft_putstr("ls: ");
				ft_putstr(name[i]);
				ft_putendl(": No such file or directory");
				name[i] = 0;
			}
			i++;
		}
		i = 0;
		while (i < count)
		{
			if (name[i] && mode[i][0] == '-')
			{
				ft_putstr(mode[i]);
				write(1, "\t", 1);
				ft_putendl(name[i]);
				name[i] = 0;
			}
			i++;
		}
		write(1, "\n", 1);
		i = 0;
		while (i < count)
		{
			if (name[i])
			{
				ft_ls(name[i]);
				name[i] = 0;
			}
			i++;
		}
	}
	// sleep(60);
	return (0);
}
