/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkao <fkao@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 12:30:42 by fkao              #+#    #+#             */
/*   Updated: 2017/08/15 17:02:15 by fkao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_flag	g_flag;

void	ls_sort(t_list **lst)
{
	t_list	*ptr;
	t_list	*tmp;
	t_ftls	*a;
	t_ftls	*b;

	ptr = *lst;
	while (ptr->next)
	{
		a = (t_ftls*)(ptr->content);
		b = (t_ftls*)(ptr->next->content);
		if (ft_strcmp(a->entry->d_name, b->entry->d_name) > 0)
		{
			tmp->content = ptr->content;
			ptr->content = ptr->next->content;
			ptr->next->content = tmp->content;
			ptr = *lst;
		}
		else
			ptr = ptr->next;
	}
}

void	ls_print(t_list *lst)
{
	t_list	*tmp;
	t_ftls	*file;

	tmp = lst;
	if (!g_flag.a)
		while (tmp)
		{
			file = (t_ftls*)(tmp->content);
			if (*file->entry->d_name == '.')
				lst = lst->next;
			tmp = tmp->next;
		}
	while (lst)
	{
		file = (t_ftls*)(lst->content);
		printf("%s\n", file->entry->d_name);
		lst = lst->next;
	}
}

void	ft_ls(char *path)
{
	t_list	*lst;
	t_ftls	*file;
	char	*str;

	path = ft_strjoin(path, "/");
	lst = 0;
	ls_file(&lst, path);
	ls_sort(&lst);
	ls_print(lst);
	while (lst && g_flag.R)
	{
		file = (t_ftls*)(lst->content);
		if (file->type == 'd' && ft_strcmp(file->entry->d_name, ".")
			&& ft_strcmp(file->entry->d_name, ".."))
		{
			str = ft_strjoin(path, file->entry->d_name);
			printf("\n%s:\n", str);
			ft_ls(str);
		}
		lst = lst->next;
	}
}

int		main(int ac, char **av)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '-' && ft_strlen(av[i]) != 1)
		{
			if (!ls_flag(av[i]))
				return (0);
		}
		else
			break ;
		i++;
	}
	if (i == ac)
		ft_ls(".");
	else
		ls_parse_arg(av + i, ac - i);
	// sleep	(50);
	return (0);
}
