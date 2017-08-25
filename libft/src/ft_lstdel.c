/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 17:59:20 by fkao              #+#    #+#             */
/*   Updated: 2017/03/06 18:35:32 by fkao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*node;
	t_list	*tmp;

	node = *alst;
	while (node)
	{
		tmp = node->next;
		del(node->content, node->content_size);
		free(node);
		node = tmp;
	}
	*alst = NULL;
}
