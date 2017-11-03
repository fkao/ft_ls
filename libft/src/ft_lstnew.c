/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 17:06:30 by fkao              #+#    #+#             */
/*   Updated: 2017/03/06 17:56:29 by fkao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lst;

	lst = malloc(sizeof(*lst));
	if (lst)
	{
		if (!content)
		{
			lst->content_size = 0;
			lst->content = NULL;
		}
		else
		{
			lst->content_size = content_size;
			lst->content = ft_memalloc(content_size);
			if (!lst->content)
				return (NULL);
			ft_memmove(lst->content, content, content_size);
		}
		lst->next = NULL;
	}
	return (lst);
}
