/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkao <fkao@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 09:50:03 by fkao              #+#    #+#             */
/*   Updated: 2017/08/15 16:50:25 by fkao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ls_isflag(int c)
{
	return (c == 'l' || c == 'R' || c == 'a' || c == 'r' || c == 't');
}

int		ls_flag(char *arg)
{
	while (*(++arg))
	{
		if (ls_isflag(*arg))
		{
			g_flag.l = (*arg == 'l') ? 1 : g_flag.l;
			g_flag.R = (*arg == 'R') ? 1 : g_flag.R;
			g_flag.a = (*arg == 'a') ? 1 : g_flag.a;
			g_flag.r = (*arg == 'r') ? 1 : g_flag.r;
			g_flag.t = (*arg == 't') ? 1 : g_flag.t;
		}
		if (!ls_isflag(*arg))
		{
			ft_putstr("./ft_ls: illegal option -- ");
			ft_putendl(&*arg);
			ft_putendl("usage: ./ft_ls [-Ralrt] [file ...]");
			return (0);
		}
	}
	return (1);
}

void	ls_sort_alpha(t_ftls **file, int count)
{
	int		i;
	t_ftls	*tmp;

	i = 0;
	while (i < count - 1)
	{
		if (ft_strcmp(file[i]->name, file[i + 1]->name) > 0)
		{
			tmp = file[i];
			file[i] = file[i + 1];
			file[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
}

void	ls_stat(t_ftls **arg, char **av, int count)
{
	char	*tmp;
	int		i;

	i = 0;
	while (i < count)
	{
		arg[i] = (t_ftls*)ft_memalloc(sizeof(t_ftls));
		arg[i]->name = av[i];
		arg[i]->buf = malloc(sizeof(struct stat));
		tmp = ft_strjoin("./", arg[i]->name);
		arg[i]->err = lstat(tmp, arg[i]->buf);
		ft_strdel(&tmp);
		if (!arg[i]->err)
		{
			ls_type(arg[i]);
			ls_mode(arg[i]);
		}
		i++;
	}
}

void	ls_parse_arg(char **av, int count)
{
	t_ftls	**arg;
	int		i;
	int		nl;

	arg = (t_ftls**)ft_memalloc(sizeof(*arg) * count + 1);
	ls_stat(arg, av, count);
	ls_sort_alpha(arg, count);
	nl = 0;
	i = -1;
	while (++i < count)
		if (arg[i]->err)
			nl = printf("ls: %s: No such file or directory\n", arg[i]->name);
	i = -1;
	while (++i < count)
		if (arg[i]->type && arg[i]->type != 'd')
			nl = printf("%c%s  %s\n", arg[i]->type, arg[i]->mode, arg[i]->name);
	i = -1;
	while (++i < count)
		if (arg[i]->type == 'd')
		{
			(i) ? write(1, "\n", 1) : 0;
			(count != 1) ? printf("%s:\n", arg[i]->name) : 0;
			ft_ls(arg[i]->name);
		}
}
