/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkao <fkao@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 15:18:32 by fkao              #+#    #+#             */
/*   Updated: 2017/08/01 15:08:20 by fkao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_recurse_sd(char *path, char **name, char **mode, int count)
{
	int		i;
	char	*tmp;

	i = 0;
	while (i < count)
	{
		if (name[i][0] != '.' && mode[i][0] == 'd')
		{
			write(1, "\n", 1);
			tmp = ft_strjoin(path, name[i]);
			ft_ls(tmp);
			ft_strdel(&tmp);
		}
		i++;
	}
}
