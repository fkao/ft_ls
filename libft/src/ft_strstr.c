/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:10:47 by fkao              #+#    #+#             */
/*   Updated: 2017/03/09 12:01:26 by fkao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *big, const char *little)
{
	int	i;
	int	j;

	i = 0;
	if (little[i] == '\0')
		return ((char*)big);
	while (big[i] != '\0')
	{
		j = 0;
		while (little[j] == big[i + j])
		{
			if (little[j + 1] == '\0')
				return ((char*)big + i);
			j++;
		}
		i++;
	}
	return (0);
}
