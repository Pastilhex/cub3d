/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:17:47 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/27 17:05:40 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	fps(t_data *data)
{
	data->old_time = data->time;
	data->time = get_actual_time();
	data->frame_time = (data->time - data->old_time) / 1000.0;
	if (data->tps <= 1.0)
	{
		data->fps++;
		data->tps += data->frame_time;
	}
	else
	{
		data->fps = 0;
		data->tps = 0.0;
	}
}

int	get_rgb(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}
