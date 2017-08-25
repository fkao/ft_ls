/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:17:53 by fkao              #+#    #+#             */
/*   Updated: 2017/03/09 12:40:37 by fkao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	size_t	j;
	int		count;

	i = 0;
	if (!*little)
		return ((char*)big);
	while (big[i] && i < n)
	{
		j = 0;
		if (big[i] == little[j])
		{
			count = 1;
			while (big[i + j] && little[j] && (i + j) < n && count)
			{
				if (big[i + j] != little[j])
					count = 0;
				j++;
			}
			if (count && little[j] == '\0')
				return ((char*)big + i);
		}
		i++;
	}
	return (NULL);
}
