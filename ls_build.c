/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_build.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkao <fkao@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 12:53:13 by fkao              #+#    #+#             */
/*   Updated: 2017/08/15 14:56:01 by fkao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/stat.h>

void	ls_mode(t_ftls *file)
{
	file->mode = (char*)ft_memalloc(sizeof(char) * 10);
	file->mode[0] = (file->buf->st_mode & S_IRUSR) ? 'r' : '-';
	file->mode[1] = (file->buf->st_mode & S_IWUSR) ? 'w' : '-';
	file->mode[2] = (file->buf->st_mode & S_IXUSR) ? 'x' : '-';
	file->mode[3] = (file->buf->st_mode & S_IRGRP) ? 'r' : '-';
	file->mode[4] = (file->buf->st_mode & S_IWGRP) ? 'w' : '-';
	file->mode[5] = (file->buf->st_mode & S_IXGRP) ? 'x' : '-';
	file->mode[6] = (file->buf->st_mode & S_IROTH) ? 'r' : '-';
	file->mode[7] = (file->buf->st_mode & S_IWOTH) ? 'w' : '-';
	file->mode[8] = (file->buf->st_mode & S_IXOTH) ? 'x' : '-';
}

void	ls_type(t_ftls *file)
{
	if ((file->buf->st_mode & S_IFMT) == S_IFBLK)
		file->type = 'b';
	else if ((file->buf->st_mode & S_IFMT) == S_IFCHR)
		file->type = 'c';
	else if ((file->buf->st_mode & S_IFMT) == S_IFDIR)
		file->type = 'd';
	else if ((file->buf->st_mode & S_IFMT) == S_IFIFO)
		file->type = 'p';
	else if ((file->buf->st_mode & S_IFMT) == S_IFLNK)
		file->type = 'l';
	else if ((file->buf->st_mode & S_IFMT) == S_IFREG)
		file->type = '-';
	else if ((file->buf->st_mode & S_IFMT) == S_IFSOCK)
		file->type = 's';
}

void	ls_file(t_list **lst, char *path)
{
	t_dir	*dir;
	t_entr	*entry;
	t_ftls	*file;
	char	*tmp;

	dir = opendir(path);
	entry = readdir(dir);
	while (entry)
	{
		file = (t_ftls*)ft_memalloc(sizeof(*file));
		file->entry = entry;
		file->buf = malloc(sizeof(t_stat));
		tmp = ft_strjoin(path, file->entry->d_name);
		if (!(file->err = lstat(tmp, file->buf)))
		{
			ls_mode(file);
			ls_type(file);
		}
		ft_strdel(&tmp);
		ft_lstadd(lst, ft_lstnew(file, sizeof(*file)));
		entry = readdir(dir);
	}
}
