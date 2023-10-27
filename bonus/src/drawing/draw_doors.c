/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_doors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:53:04 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/27 16:08:24 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	calc_door2(t_data *data)
{
	if (data->ray_dir_x < 0)
	{
		data->step_x = -1;
		data->side_dist_x = (data->pos_x - data->map_x) * data->delta_dist_x;
	}
	else
	{
		data->step_x = 1;
		data->side_dist_x = (data->map_x + 1.0 - data->pos_x)
			* data->delta_dist_x;
	}
	if (data->ray_dir_y < 0)
	{
		data->step_y = -1;
		data->side_dist_y = (data->pos_y - data->map_y) * data->delta_dist_y;
	}
	else
	{
		data->step_y = 1;
		data->side_dist_y = (data->map_y + 1.0 - data->pos_y)
			* data->delta_dist_y;
	}
}

void	calc_doors(t_data *data, int *x)
{
	data->camera_x = 2 * *x / (double)SCREENWIDTH - 1;
	data->ray_dir_x = data->dir_x + data->plane_x * data->camera_x;
	data->ray_dir_y = data->dir_y + data->plane_y * data->camera_x;
	data->map_x = (int)data->pos_x;
	data->map_y = (int)data->pos_y;
	if (data->ray_dir_x == 0)
		data->delta_dist_x = 1e30;
	else
		data->delta_dist_x = fabs(1.0 / data->ray_dir_x);
	if (data->ray_dir_y == 0)
		data->delta_dist_y = 1e30;
	else
		data->delta_dist_y = fabs(1.0 / data->ray_dir_y);
	data->hit = 0;
	data->wallXOffset = 0;
	data->wallYOffset = 0;
	calc_door2(data);
}

void	check_hit_doors(t_data *data)
{
	while (data->hit == 0)
	{
		if (data->side_dist_x < data->side_dist_y)
		{
			data->side_dist_x += data->delta_dist_x;
			data->map_x += data->step_x;
			data->side = 0;
		}
		else
		{
			data->side_dist_y += data->delta_dist_y;
			data->map_y += data->step_y;
			data->side = 1;
		}
		if (data->map_ptr->world_map[data->map_x][data->map_y] != '0')
			data->hit = 1;
	}
}

void	door_animation(t_data *d)
{
	d->map_ptr->current_time = get_actual_time();
	if (d->open_door < 20 && d->close_door == 0)
	{
		if (d->map_ptr->current_time - d->map_ptr->start_time_door > 10)
		{
			draw_wall(d, '9', &d->txt_door[d->open_door],
				&d->txt_door[d->open_door]);
			d->map_ptr->start_time_door = get_actual_time();
			d->open_door++;
		}
		draw_wall(d, '9', &d->txt_door[d->open_door],
			&d->txt_door[d->open_door]);
	}
	else
	{
		draw_wall(d, '9', &d->txt_door[d->open_door],
			&d->txt_door[d->open_door]);
		d->close_door = 1;
	}
}
void	draw_doors(t_data *d, int *x)
{
	if (d->ray_dir_y < 0)
	{
		d->step_y = -1;
		d->side_dist_y = (d->pos_y - d->map_y) * d->delta_dist_y;
	}
	else
	{
		d->step_y = 1;
		d->side_dist_y = (d->map_y + 1.0 - d->pos_y) * \
			d->delta_dist_y;
	}
	if (d->map_x && d->map_y)
		check_hit_doors(d);
	if (d->map_ptr->world_map[d->map_x][d->map_y] == '9')
		check_side(d);
	calculate_cols(d);
	draw_doors_cols(d, x);
}
