/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_build.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkao <fkao@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 12:53:13 by fkao              #+#    #+#             */
/*   Updated: 2017/08/01 14:57:03 by fkao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <dirent.h>
#include <sys/stat.h>

void	ls_get_rwx(char *tmp, char **ptr)
{
	while (*tmp)
	{
		(*tmp == '0') ? ft_strcpy(*ptr, "---") : 0;
		(*tmp == '1') ? ft_strcpy(*ptr, "--x") : 0;
		(*tmp == '2') ? ft_strcpy(*ptr, "-w-") : 0;
		(*tmp == '3') ? ft_strcpy(*ptr, "-wx") : 0;
		(*tmp == '4') ? ft_strcpy(*ptr, "r--") : 0;
		(*tmp == '5') ? ft_strcpy(*ptr, "r-x") : 0;
		(*tmp == '6') ? ft_strcpy(*ptr, "rw-") : 0;
		(*tmp == '7') ? ft_strcpy(*ptr, "rwx") : 0;
		tmp++;
		*ptr += 3;
	}
}

char	*ls_int_mode(char *tmp)
{
	char	*new;
	char	*ptr;

	new = (char*)ft_memalloc((sizeof(char)) * 11);
	ptr = new;
	if (*tmp == '4')
	{
		*ptr = 'd';
		tmp += 2;
		ptr++;
	}
	else if (*tmp == '1')
	{
		*ptr = '-';
		tmp += 3;
		ptr++;
	}
	ls_get_rwx(tmp, &ptr);
	return (new);
}

char	**ls_mode_stack(char *path, char **name, int count)
{
	struct stat	*buf;
	char		**mode;
	char		*tmp;
	int			i;

	mode = (char**)ft_memalloc(sizeof(char*) * (count + 1));
	i = 0;
	buf = malloc(sizeof(struct stat));
	while (i < count)
	{
		tmp = ft_strjoin(path, name[i]);
		stat(tmp, buf);
		ft_strdel(&tmp);
		tmp = ft_itoa_base(buf->st_mode, 8);
		mode[i] = ls_int_mode(tmp);
		ft_strdel(&tmp);
		i++;
	}
	free(buf);
	return (mode);
}

char	**ls_file_stack(char *path, int count)
{
	DIR				*dir;
	struct dirent	*entry;
	char			**name;
	int				i;

	name = (char**)ft_memalloc(sizeof(char*) * (count + 1));
	dir = opendir(path);
	entry = readdir(dir);
	i = 0;
	while (entry)
	{
		name[i++] = entry->d_name;
		entry = readdir(dir);
	}
	closedir(dir);
	return (name);
}

int		ls_dir_len(char *path)
{
	DIR				*dir;
	struct dirent	*entry;
	int				count;

	dir = opendir(path);
	entry = readdir(dir);
	count = 0;
	while (entry)
	{
		count++;
		entry = readdir(dir);
	}
	closedir(dir);
	return (count);
}
