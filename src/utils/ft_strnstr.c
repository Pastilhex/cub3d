/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:34:10 by ialves-m          #+#    #+#             */
/*   Updated: 2023/09/29 11:35:13 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (len == 0 && !little)
		return (NULL);
	if (little[0] == '\0')
		return ((char *)big);
	while (i < len)
	{
		while (little[i] == big[j] && j < len)
		{
			i++;
			j++;
			if (little[i] == '\0')
				return ((char *)big + j - i);
		}
		i = 0;
		if (little[i] != big[j] && j < len)
			j++;
		if (j == len)
			return (NULL);
	}
	return (0);
}
