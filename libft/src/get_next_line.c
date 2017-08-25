/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkao <fkao@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 14:21:14 by fkao              #+#    #+#             */
/*   Updated: 2017/06/21 17:45:24 by fkao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

t_gnl	*gnl_locate_fd(t_list **lst, int fd)
{
	t_gnl	*stack;
	t_list	*tmp;

	tmp = *lst;
	while (tmp)
	{
		stack = (t_gnl*)(tmp->content);
		if (stack->fd == fd)
			return (stack);
		tmp = tmp->next;
	}
	stack = (t_gnl*)ft_memalloc(sizeof(*stack));
	stack->fd = fd;
	tmp = ft_lstnew(stack, sizeof(*stack));
	ft_lstadd(lst, tmp);
	ft_memdel((void**)&stack);
	return ((t_gnl*)(tmp->content));
}

void	gnl_strjoin(char **buf, char **str)
{
	char	*tmp;

	tmp = *buf;
	*buf = ft_strjoin(*buf, *str);
	ft_strdel(&*str);
	ft_strdel(&tmp);
}

int		gnl_parse_line(char **buf, char **line)
{
	char	*ptr;

	if ((ptr = ft_strchr(*buf, '\n')))
	{
		*ptr = '\0';
		*line = ft_strdup(*buf);
		ft_memmove(*buf, ptr + 1, ft_strlen(ptr + 1) + 1);
		return (1);
	}
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	static t_list	*lst;
	t_gnl			*stack;

	if (!line || fd == -1)
		return (-1);
	stack = gnl_locate_fd(&lst, fd);
	stack->len = 1;
	if (!stack->buf)
		stack->buf = ft_strnew(0);
	while (stack->len > 0)
	{
		if ((gnl_parse_line(&stack->buf, line)))
			return (1);
		stack->tmp = ft_strnew(BUFF_SIZE + 1);
		stack->len = read(fd, stack->tmp, BUFF_SIZE);
		stack->tmp[stack->len] = '\0';
		gnl_strjoin(&stack->buf, &stack->tmp);
	}
	if (*stack->buf && !stack->len)
	{
		*line = ft_strdup(stack->buf);
		stack->buf = NULL;
		return (1);
	}
	return (stack->len);
}
