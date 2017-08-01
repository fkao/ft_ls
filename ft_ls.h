/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkao <fkao@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 16:49:57 by fkao              #+#    #+#             */
/*   Updated: 2017/08/01 15:08:44 by fkao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_attr
{
	int			l;
	int			R;
	int			a;
	int			r;
	int			t;
	int			start;
}				t_attr;

typedef struct	s_ftls
{
	char		*path;
	int			count;
	char		**name;
	char		**mode;
}				t_ftls;

void			ft_ls(char *file);
extern t_attr	g_attr;
int				ls_dir_len(char *path);
char			**ls_file_stack(char *path, int count);
char			**ls_mode_stack(char *path, char **name, int count);
void			ls_recurse_sd(char *path, char **name, char **mode, int count);
#endif
