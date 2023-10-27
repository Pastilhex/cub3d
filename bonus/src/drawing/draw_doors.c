/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_doors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:53:04 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/27 10:44:54 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

static void	check_hit_doors(t_data *data)
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

static void	draw_doors_cols(t_data *data, int *x)
{
	t_draw	draw;

	data->draw_ptr = &draw;
	draw.x = x;
	draw.y = 0;
	draw.tex_y = 0;
	draw.y = data->draw_start;
    if (data->door_state == 0
		&& (data->mini_map_ptr->big_map[(int)data->pos_x - 2 + 5][(int)data->pos_y + 10] == '9'
		 || data->mini_map_ptr->big_map[(int)data->pos_x - 1 + 5][(int)data->pos_y + 10] == '9'
		 || data->mini_map_ptr->big_map[(int)data->pos_x + 5][(int)data->pos_y + 10] == '9'
		 || data->mini_map_ptr->big_map[(int)data->pos_x + 1 + 5][(int)data->pos_y + 10] == '9'
		 || data->mini_map_ptr->big_map[(int)data->pos_x + 2 + 5][(int)data->pos_y + 10] == '9'))
	{
		data->door_state = 1;
	}
	else if ((data->mini_map_ptr->big_map[(int)data->pos_x - 2 + 5][(int)data->pos_y + 10] != '9'
		   && data->mini_map_ptr->big_map[(int)data->pos_x - 1 + 5][(int)data->pos_y + 10] != '9'
		   && data->mini_map_ptr->big_map[(int)data->pos_x + 5][(int)data->pos_y + 10] != '9'
		   && data->mini_map_ptr->big_map[(int)data->pos_x + 1 + 5][(int)data->pos_y + 10] != '9'
		   && data->mini_map_ptr->big_map[(int)data->pos_x + 2 + 5][(int)data->pos_y + 10] != '9'))
	{
		data->door_state = 0;
		data->close_door = 0;
		data->open_door = 0;
	}
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
	if (d->map_ptr->world_map[d->map_x][d->map_y] == '9') //Closed, opening, or closing doors
		{
			if (d->side == 1)	// Door (WE)
			{
				d->wallYOffset = 0.5 * d->step_y;
				d->perp_wall_dist = (d->map_y - d->pos_y + d->wallYOffset + (1.0 - d->step_y) / 2) - d->ray_dir_y;
				d->map_ptr->wall_x = d->pos_x + d->perp_wall_dist * d->ray_dir_x;
				d->map_ptr->wall_x -= floor(d->map_ptr->wall_x);
				if (d->side_dist_y - (d->delta_dist_y / 2) < d->side_dist_x) //If ray hits offset wall
						d->hit = 0; //Continue raycast for open/opening doors
				else
				{
					d->map_x += d->step_x;
					d->side = 0;
				}
				d->wallYOffset = 0; 
			}
			else	// Door (NS)
			{
				d->wallXOffset = 0.5 * d->step_x;
				d->perp_wall_dist  = (d->map_x - d->pos_x + d->wallXOffset + (1.0 - d->step_x) / 2) / d->ray_dir_x;
				d->map_ptr->wall_x = d->pos_y + d->perp_wall_dist * d->ray_dir_y;
				d->map_ptr->wall_x -= floor(d->map_ptr->wall_x);
				if (d->side_dist_x - (d->delta_dist_x / 2) < d->side_dist_y)
					d->hit = 0;
				else
				{
					d->map_y += d->step_y;
					d->side = 1;
				}
				d->wallXOffset = 0;
			}
		}
	calculate_cols(d);
	draw_doors_cols(d, x);
}
