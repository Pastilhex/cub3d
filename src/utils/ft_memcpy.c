/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:35:50 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/05 18:42:25 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*adest;
	char	*asrc;

	if ((dest == src) || n == 0)
		return (dest);
	if (!dest && !src)
		return (0);
	adest = (char *)dest;
	asrc = (char *)src;
	while (n--)
		adest[n] = asrc[n];
	return (dest);
}