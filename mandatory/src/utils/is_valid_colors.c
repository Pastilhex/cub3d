/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:11:47 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/09 15:52:33 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	is_valid_colors(t_rgb *colors)
{
	if (colors->r < 0 || colors->g < 0 || colors->b < 0)
		return (false);
	if (colors->r > 255 || colors->g > 255 || colors->b > 255)
		return (false);
	return (true);
}
