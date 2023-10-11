/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:37:44 by ialves-m          #+#    #+#             */
/*   Updated: 2023/10/11 14:09:52 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	slen;
	unsigned int	i;

	slen = ft_strlen((char *)src);
	i = 0;
	if ((int)size > 0)
	{
		while ((src[i] != '\0') && (i < size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
		return (slen);
	}
	return (slen);
}
