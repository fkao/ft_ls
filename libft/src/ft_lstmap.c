/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 18:35:46 by fkao              #+#    #+#             */
/*   Updated: 2017/03/06 18:59:29 by fkao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;

	if (lst->next)
	{
		new = ft_lstmap(lst->next, f);
		ft_lstadd(&new, f(lst));
	}
	else
		new = f(lst);
	return (new);
}
