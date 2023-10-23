/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_hands.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:21:48 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/23 20:50:28 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	trigger(t_data *data)
{
	data->map_ptr->current_time = get_actual_time();
	if (data->press_space == 1)
	{
		if (data->map_ptr->current_time - data->map_ptr->start_time > 100)
		{
			data->swap_hands++;
			if (data->swap_hands == 3)
			{
				data->swap_hands = 0;
				data->press_space = 0;
			}
			data->map_ptr->start_time = get_actual_time();
		}
	}
}

void	draw_hands(t_data *data)
{
	t_aux	var;

	var.i = SCREENWIDTH * 0.4;
	var.a = 128.0 / ((double)SCREENWIDTH / 5);
	var.b = (128.0 / ((double)SCREENHEIGHT / 3.75));
	var.begin_i = (SCREENWIDTH * 0.4);
	var.begin_j = (SCREENHEIGHT - (SCREENHEIGHT / 6.0 + SCREENHEIGHT / 3.75));
	trigger(data);
	while (var.i < SCREENWIDTH * 0.6)
	{
		var.j = SCREENHEIGHT - (SCREENHEIGHT / 6.0 + SCREENHEIGHT / 3.75);
		while (var.j < SCREENHEIGHT - (SCREENHEIGHT / 6.0))
		{
			ft_pixel_put(data->m_ptr, var.i, var.j,
				(unsigned int)ft_pixel_get(&data->txt_hands[data->swap_hands],
					(int)((var.i - var.begin_i) * var.a), \
					(int)((var.j - var.begin_j) * var.b)));
			var.j++;
		}
		var.i++;
	}
}
