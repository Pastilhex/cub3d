/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frames2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:05:09 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/27 13:06:41 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	check_hit(t_data *data)
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
		if (dont_hit(data))
			data->hit = 1;
	}
	if (data->side == 0)
		data->perp_wall_dist = (data->side_dist_x - data->delta_dist_x);
	else
		data->perp_wall_dist = (data->side_dist_y - data->delta_dist_y);
}

void	calculate_cols(t_data *data)
{
	data->line_height = (int)(SCREENHEIGHT / data->perp_wall_dist);
	data->draw_start = -data->line_height / 2 + SCREENHEIGHT / 2;
	if (data->draw_start < 0)
		data->draw_start = 0;
	data->draw_end = data->line_height / 2 + SCREENHEIGHT / 2;
	if (data->draw_end >= SCREENHEIGHT)
		data->draw_end = SCREENHEIGHT - 1;
	if (data->side == 0)
		data->map_ptr->wall_x = data->pos_y + \
			data->perp_wall_dist * data->ray_dir_y;
	else
		data->map_ptr->wall_x = data->pos_x + \
			data->perp_wall_dist * data->ray_dir_x;
	data->map_ptr->wall_x -= floor((data->map_ptr->wall_x));
	data->tex_x = (int)(data->map_ptr->wall_x * (double)TEXWIDTH);
	if (data->side == 0 && data->ray_dir_x > 0)
		data->tex_x = TEXWIDTH - data->tex_x - 1;
	if (data->side == 1 && data->ray_dir_y < 0)
		data->tex_x = TEXWIDTH - data->tex_x - 1;
	data->map_ptr->step = 1.0 * TEXHEIGHT / data->line_height;
	data->map_ptr->tex_pos = (data->draw_start - \
		(double)SCREENHEIGHT / 2 + (double)data->line_height / 2) * \
			data->map_ptr->step;
}

void	draw_wall(t_data *d, char c, t_texture *txt_ns, t_texture *txt_we)
{
	if (d->side == 0 && d->ray_dir_x > 0 && d->map_ptr->world_map
		[(int)d->map_x][(int)d->map_y] == c)
		ft_pixel_put(d->m_ptr, *d->draw_ptr->x, d->draw_ptr->y,
			(unsigned int)ft_pixel_get(txt_ns, d->tex_x, d->draw_ptr->tex_y));
	else if (d->side == 0 && d->ray_dir_x < 0 && d->map_ptr->world_map
		[(int)d->map_x][(int)d->map_y] == c)
		ft_pixel_put(d->m_ptr, *d->draw_ptr->x, d->draw_ptr->y,
			(unsigned int)ft_pixel_get(txt_ns, d->tex_x, d->draw_ptr->tex_y));
	else if (d->side == 1 && d->ray_dir_y > 0 && d->map_ptr->world_map
		[(int)d->map_x][(int)d->map_y] == c)
		ft_pixel_put(d->m_ptr, *d->draw_ptr->x, d->draw_ptr->y,
			(unsigned int)ft_pixel_get(txt_we, d->tex_x, d->draw_ptr->tex_y));
	else if (d->side == 1 && d->ray_dir_y < 0 && d->map_ptr->world_map
		[(int)d->map_x][(int)d->map_y] == c)
		ft_pixel_put(d->m_ptr, *d->draw_ptr->x, d->draw_ptr->y,
			(unsigned int)ft_pixel_get(txt_we, d->tex_x, d->draw_ptr->tex_y));
}

static void	draw_cols(t_data *data, int *x)
{
	t_draw	draw;

	data->draw_ptr = &draw;
	draw.x = x;
	draw.y = 0;
	draw.tex_y = 0;
	draw.y = data->draw_start;
	while (draw.y <= data->draw_end)
	{
		draw.tex_y = (int)data->map_ptr->tex_pos & (TEXHEIGHT - 1);
		data->map_ptr->tex_pos += data->map_ptr->step;
		draw_wall(data, '1', &data->txt_ptr[0], &data->txt_ptr[2]);
		draw_wall(data, '2', &data->txt_ptr[6], &data->txt_ptr[6]);
		draw_wall(data, '3', &data->txt_ptr[5], &data->txt_ptr[5]);
		draw_wall(data, '4', &data->txt_ptr[7], &data->txt_ptr[8]);
		draw_wall(data, '5', &data->txt_ptr[9], &data->txt_ptr[10]);
		draw.y++;
	}
}

void	draw_walls(t_data *data, int *x)
{
	if (data->ray_dir_y < 0)
	{
		data->step_y = -1;
		data->side_dist_y = (data->pos_y - data->map_y) * data->delta_dist_y;
	}
	else
	{
		data->step_y = 1;
		data->side_dist_y = (data->map_y + 1.0 - data->pos_y) * \
			data->delta_dist_y;
	}
	if (data->map_x && data->map_y)
		check_hit(data);
	calculate_cols(data);
	draw_cols(data, x);
}
