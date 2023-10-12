/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_get.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:30:46 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/10 14:38:32 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_pixel_get(t_texture *txt, int x, int y)
{
	return (*(unsigned int *)((txt->addr + (y * txt->line_length) + \
		(x * txt->bits_per_pixel / 8))));
}
