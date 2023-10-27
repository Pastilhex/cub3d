/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_doors2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:01:44 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/27 17:26:21 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_around_on(t_data *data)
{
	if (data->door_state == 0 && (data->mini_map_ptr->big_map[(int)data->pos_x
				- 2 + 5][(int)data->pos_y + 10] == '9'
		|| data->mini_map_ptr->big_map[(int)data->pos_x - 1
			+ 5][(int)data->pos_y + 10] == '9'
			|| data->mini_map_ptr->big_map[(int)data->pos_x
			+ 5][(int)data->pos_y + 10] == '9'
			|| data->mini_map_ptr->big_map[(int)data->pos_x + 1
			+ 5][(int)data->pos_y + 10] == '9'
			|| data->mini_map_ptr->big_map[(int)data->pos_x + 2
			+ 5][(int)data->pos_y + 10] == '9'))
	{
		data->door_state = 1;
	}
}

void	check_around_off(t_data *data)
{
	if ((data->mini_map_ptr->big_map[(int)data->pos_x - 2 + 5]
			[(int)data->pos_y + 10] != '9'
			&& data->mini_map_ptr->big_map[(int)data->pos_x - 1 + 5]
			[(int)data->pos_y + 10] != '9'
			&& data->mini_map_ptr->big_map[(int)data->pos_x + 5]
			[(int)data->pos_y + 10] != '9'
			&& data->mini_map_ptr->big_map[(int)data->pos_x + 1 + 5]
			[(int)data->pos_y + 10] != '9'
			&& data->mini_map_ptr->big_map[(int)data->pos_x + 2 + 5]
			[(int)data->pos_y + 10] != '9'))
	{
		data->door_state = 0;
		data->close_door = 0;
		data->open_door = 0;
	}
}

void	draw_doors_cols(t_data *data, int *x)
{
	t_draw	draw;

	data->draw_ptr = &draw;
	draw.x = x;
	draw.y = 0;
	draw.tex_y = 0;
	draw.y = data->draw_start;
	check_around_on(data);
	check_around_off(data);
	while (draw.y <= data->draw_end)
	{
		draw.tex_y = (int)data->map_ptr->tex_pos & (TEXHEIGHT - 1);
		data->map_ptr->tex_pos += data->map_ptr->step;
		if (data->door_state == 1)
			door_animation(data);
		else
			draw_wall(data, '9', &data->txt_door[0], &data->txt_door[0]);
		draw.y++;
	}
}

void	check_side2(t_data *d)
{
	d->wall_x_offset = 0.5 * d->step_x;
	d->perp_wall_dist = (d->map_x - d->pos_x
			+ d->wall_x_offset + (1.0 - d->step_x) / 2)
		/ d->ray_dir_x;
	d->map_ptr->wall_x = d->pos_y + d->perp_wall_dist * d->ray_dir_y;
	d->map_ptr->wall_x -= floor(d->map_ptr->wall_x);
	if (d->side_dist_x - (d->delta_dist_x / 2) < d->side_dist_y)
		d->hit = 0;
	else
	{
		d->map_y += d->step_y;
		d->side = 1;
	}
	d->wall_x_offset = 0;
}

void	check_side(t_data *d)
{
	if (d->side == 1)
	{
		d->wall_y_offset = 0.5 * d->step_y;
		d->perp_wall_dist = (d->map_y - d->pos_y + d->wall_y_offset + (1.0
					- d->step_y) / 2) - d->ray_dir_y;
		d->map_ptr->wall_x = d->pos_x + d->perp_wall_dist * d->ray_dir_x;
		d->map_ptr->wall_x -= floor(d->map_ptr->wall_x);
		if (d->side_dist_y - (d->delta_dist_y / 2) < d->side_dist_x)
			d->hit = 0;
		else
		{
			d->map_x += d->step_x;
			d->side = 0;
		}
		d->wall_y_offset = 0;
	}
	else
		check_side2(d);
}
