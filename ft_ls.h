/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkao <fkao@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 16:49:57 by fkao              #+#    #+#             */
/*   Updated: 2017/08/15 16:19:24 by fkao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft.h"
# include <stdlib.h>
# include <dirent.h>
# include <sys/stat.h>

# include <stdio.h>
# include <unistd.h>

typedef DIR				t_dir;
typedef struct dirent	t_entr;
typedef struct stat		t_stat;
typedef struct			s_flag
{
	int					l;
	int					R;
	int					a;
	int					r;
	int					t;
}						t_flag;

typedef struct			s_ftls
{
	char				*name;
	t_entr				*entry;
	t_stat				*buf;
	int					err;
	char				*mode;
	char				type;
}						t_ftls;

void					ft_ls(char *direct);
extern	t_flag			g_flag;
void					ls_file(t_list **lst, char *path);
int						ls_flag(char *arg);
void					ls_parse_arg(char **av, int count);
void					ls_type(t_ftls *file);
void					ls_mode(t_ftls *file);
#endif
