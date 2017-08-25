/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkao <fkao@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 17:13:35 by fkao              #+#    #+#             */
/*   Updated: 2017/08/24 12:52:21 by fkao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <pwd.h>
#include <grp.h>
#include <time.h>

char	ls_type(mode_t st_mode)
{
	if ((st_mode & S_IFMT) == S_IFBLK)
		return ('b');
	else if ((st_mode & S_IFMT) == S_IFCHR)
		return ('c');
	else if ((st_mode & S_IFMT) == S_IFDIR)
		return ('d');
	else if ((st_mode & S_IFMT) == S_IFIFO)
		return ('p');
	else if ((st_mode & S_IFMT) == S_IFLNK)
		return ('l');
	else if ((st_mode & S_IFMT) == S_IFSOCK)
		return ('s');
	else
		return ('-');
}

char	*ls_mode(mode_t st_mode)
{
	char	*mode;

	mode = (char*)ft_memalloc(sizeof(char) * 10);
	mode[0] = (st_mode & S_IRUSR) ? 'r' : '-';
	mode[1] = (st_mode & S_IWUSR) ? 'w' : '-';
	mode[2] = (st_mode & S_IXUSR) ? 'x' : '-';
	mode[3] = (st_mode & S_IRGRP) ? 'r' : '-';
	mode[4] = (st_mode & S_IWGRP) ? 'w' : '-';
	mode[5] = (st_mode & S_IXGRP) ? 'x' : '-';
	mode[6] = (st_mode & S_IROTH) ? 'r' : '-';
	mode[7] = (st_mode & S_IWOTH) ? 'w' : '-';
	mode[8] = (st_mode & S_IXOTH) ? 'x' : '-';
	if (st_mode & S_ISUID)
		mode[2] = (st_mode & S_IXUSR) ? 's' : 'S';
	if (st_mode & S_ISGID)
		mode[5] = (st_mode & S_IXGRP) ? 's' : 'S';
	if (st_mode & S_ISVTX)
		mode[8] = (st_mode & S_IXOTH) ? 't' : 'T';
	return (mode);
}

void	ls_time(t_stat *buf)
{
	char	**date;
	time_t	now;

	date = ft_strsplit(ctime(&buf->st_mtime), ' ');
	date[4][4] = '\0';
	if (!g_flag.tim)
	{
		time(&now);
		now -= buf->st_mtime;
		now *= (now < 0) ? -1 : 1;
		ft_printf("%s%3s%6.5s ", date[1], date[2], (now > 15768000) ? date[4] :
			date[3]);
	}
	else
		ft_printf("%s%3s %s %s ", date[1], date[2], date[3], date[4]);
	ft_strdel(&date[0]);
	ft_strdel(&date[1]);
	ft_strdel(&date[2]);
	ft_strdel(&date[3]);
	ft_strdel(&date[4]);
	free(date);
}

void	ls_long(t_stat *buf)
{
	char	type;
	char	*mode;
	t_pwd	*pwd;
	t_grd	*grd;

	type = ls_type(buf->st_mode);
	mode = ls_mode(buf->st_mode);
	pwd = getpwuid(buf->st_uid);
	grd = getgrgid(buf->st_gid);
	ft_printf("%c%s  %*d ", type, mode, g_link, buf->st_nlink);
	if (!g_flag.g)
		ft_printf("%s  ", pwd->pw_name);
	if (!g_flag.o)
		ft_printf("%s  ", grd->gr_name);
	if (g_flag.g && g_flag.o)
		ft_printf("  ");
	ft_printf("%*lld ", g_size, buf->st_size);
	ls_time(buf);
	ft_strdel(&mode);
}

void	ls_print(t_ftls *stat)
{
	char	link[PATH_MAX];

	if (g_flag.l)
		ls_long(stat->buf);
	if (g_flag.l && (stat->buf->st_mode & S_IFMT) == S_IFLNK)
	{
		link[readlink(stat->full, link, PATH_MAX)] = '\0';
		ft_printf("%s -> %s\n", stat->name, link);
	}
	else
		ft_printf("%s\n", stat->name);
}
