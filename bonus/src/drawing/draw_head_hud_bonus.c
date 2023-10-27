/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_head_hud.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:29:28 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/26 13:34:26 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_hud(t_data *data)
{
	int		i;
	int		j;
	double	j_correction;
	double	i_correction;
	int		k;

	i = 0;
	j = SCREENHEIGHT - (SCREENHEIGHT / 6);
	j_correction = 80.0 / ((double)SCREENHEIGHT / 6.0);
	i_correction = (640.0 / (double)SCREENWIDTH);
	k = 0;
	while (i < SCREENWIDTH)
	{
		j = SCREENHEIGHT - (SCREENHEIGHT / 6);
		while (j < SCREENHEIGHT)
		{
			ft_pixel_put(data->m_ptr, i, j, (unsigned int)
				ft_pixel_get(&data->txt_ptr[hud], i * i_correction,
					(int)(80 - ((SCREENHEIGHT - j) * j_correction))));
			j++;
			k++;
		}
		k = 0;
		i++;
	}
}

static void	head_timing(t_data *data)
{
	data->map_ptr->current_time = get_actual_time();
	if (data->map_ptr->current_time - data->map_ptr->start_time_head > 1000)
	{
		data->swap_img++;
		if (data->swap_img == 3)
			data->swap_img = 0;
		data->map_ptr->start_time_head = get_actual_time();
	}
}

void	draw_head_hud(t_data *data)
{
	t_aux	var;

	var.a = 47.0 / ((double)SCREENWIDTH / 13.617021277);
	var.b = (62.0 / ((double)SCREENHEIGHT / 7.741935484));
	var.begin_i = (SCREENWIDTH * 0.4265625);
	var.begin_j = (SCREENHEIGHT * 0.85);
	var.i = SCREENWIDTH * 0.4265625;
	var.j = SCREENHEIGHT * 0.855;
	head_timing(data);
	while (var.i < SCREENWIDTH * 0.5)
	{
		var.j = SCREENHEIGHT * 0.855;
		while (var.j < SCREENHEIGHT * 0.972916667)
		{
			ft_pixel_put(data->m_ptr, var.i, var.j,
				(unsigned int)ft_pixel_get(&data->txt_head[data->swap_img],
					(int)((var.i - var.begin_i) * var.a), (int)((var.j
							- var.begin_j) * var.b)));
			var.j++;
		}
		var.i++;
	}
}
