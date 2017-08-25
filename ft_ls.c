/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkao <fkao@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 11:40:28 by fkao              #+#    #+#             */
/*   Updated: 2017/08/24 12:22:30 by fkao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_flag	g_flag;
int		(*g_sort)() = &sort_alpha;
int		g_total = 0;
int		g_link = 0;
int		g_size = 0;
int		g_xattr = 0;

void	ls_free_lst(void *node, size_t size)
{
	t_ftls	*stat;

	(void)size;
	stat = (t_ftls*)node;
	if (stat)
	{
		if (stat->name)
			free(stat->name);
		if (stat->full)
			free(stat->full);
		if (stat->buf)
			free(stat->buf);
		free(stat);
	}
}

void	ls_recurse(t_list *file)
{
	t_ftls	*stat;

	if (g_flag.rec)
		while (file)
		{
			stat = (t_ftls*)(file->content);
			if ((stat->buf->st_mode & S_IFMT) == S_IFDIR \
				&& ft_strcmp(stat->name, ".") && ft_strcmp(stat->name, ".."))
			{
				ft_printf("\n%s:\n", stat->full);
				ft_ls(stat->full);
			}
			file = file->next;
		}
}

void	ls_print_all(t_list *file)
{
	t_ftls	*stat;

	if (g_flag.l)
		ft_printf("total %d\n", g_total);
	while (file)
	{
		stat = (t_ftls*)(file->content);
		ls_print(stat);
		file = file->next;
	}
}

void	ft_ls(char *arg)
{
	t_list	*file;
	t_dir	*dir;
	t_entr	*entry;
	char	*path;

	file = NULL;
	if (!(dir = opendir(arg)))
		return (ls_error(arg, 2));
	path = (ft_strcmp(arg, "/")) ? ft_strjoin(arg, "/") : ft_strdup(arg);
	ls_reset_len();
	while ((entry = readdir(dir)))
		if (g_flag.a || entry->d_name[0] != '.' || (g_flag.alm &&
		ft_strcmp(entry->d_name, ".") && ft_strcmp(entry->d_name, "..")))
			ls_store(&file, entry->d_name, path);
	closedir(dir);
	ls_mergesort(&file, g_sort);
	if (g_flag.r)
		ft_lstrev(&file);
	ls_print_all(file);
	ls_recurse(file);
	ft_lstdel(&file, &ls_free_lst);
	ft_strdel(&path);
}

int		main(int ac, char **av)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		if (ft_strcmp(av[i], "--") == 0)
		{
			i++;
			break ;
		}
		else if (av[i][0] == '-' && ft_strlen(av[i]) != 1)
			ls_flag(av[i]);
		else
			break ;
		i++;
	}
	if (i == ac)
		ft_ls(".");
	else
		ls_build_arg(ac - i, av + i);
	return (0);
}
