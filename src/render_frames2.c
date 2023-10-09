/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frames2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:05:09 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/09 14:09:58 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void     check_hit(t_data *data)
{
	while(data->hit == '0')
		{
			if(data->side_dist_x < data->side_dist_y)
			{
				data->side_dist_x += data->delta_dist_x;
				data->map_x += data->step_x;
				data->side = '0';
			}
			else
			{
				data->side_dist_y += data->delta_dist_y;
				data->map_y += data->step_y;
				data->side = '1';
			}
			if(data->map_ptr->world_map[data->map_x][data->map_y] > '0')
				data->hit = '1';
		}
		if(data->side == '0')
			data->perp_wall_dist = (data->side_dist_x - data->delta_dist_x);
		else
			data->perp_wall_dist = (data->side_dist_y - data->delta_dist_y);
}

static void     calculate_cols(t_data *data)
{
	data->line_height = (int)(SCREENHEIGHT / data->perp_wall_dist);
	int pitch = 0;
	data->draw_start = -data->line_height / 2 + SCREENHEIGHT / 2 + pitch;
	if(data->draw_start < 0)
		data->draw_start = 0;
	data->draw_end = data->line_height / 2 + SCREENHEIGHT / 2 + pitch;
	if(data->draw_end >= SCREENHEIGHT)
		data->draw_end = SCREENHEIGHT - 1;
	if (data->side == '0')
		data->map_ptr->wall_x = data->pos_y + data->perp_wall_dist * data->ray_dir_y; 
	else
		data->map_ptr->wall_x = data->pos_x + data->perp_wall_dist * data->ray_dir_x; 
	data->map_ptr->wall_x -= floor((data->map_ptr->wall_x));
	data->tex_x = (int)(data->map_ptr->wall_x * (double)TEXWIDTH);
	if(data->side == '0' && data->ray_dir_x > 0)
		data->tex_x = TEXWIDTH - data->tex_x - 1;
	if(data->side == '1' && data->ray_dir_y < 0)
		data->tex_x = TEXWIDTH - data->tex_x - 1;
	data->map_ptr->step = 1.0 * TEXHEIGHT / data->line_height;
	data->map_ptr->tex_pos = (data->draw_start - pitch - (double)SCREENHEIGHT / 2 + (double)data->line_height / 2) * data->map_ptr->step;
}

static void     draw_cols(t_data *data, int *x)
{
	int		y;
	
	y = data->draw_start;
	while (y <= data->draw_end)
	{
		int texY = (int)data->map_ptr->tex_pos & (TEXHEIGHT - 1);
		data->map_ptr->tex_pos += data->map_ptr->step;
		if (data->side == '0' && data->ray_dir_x > 0)
			ft_pixel_put(data->m_ptr, *x, y, (unsigned int)ft_pixel_get(&data->txt_ptr[south], data->tex_x, texY));
		else if (data->side == '0' && data->ray_dir_x < 0)
			ft_pixel_put(data->m_ptr, *x, y, (unsigned int)ft_pixel_get(&data->txt_ptr[1], data->tex_x, texY));
		else if (data->side == '1' && data->ray_dir_y > 0)
			ft_pixel_put(data->m_ptr, *x, y, (unsigned int)ft_pixel_get(&data->txt_ptr[2], data->tex_x, texY));
		else if (data->side == '1' && data->ray_dir_y < 0)
			ft_pixel_put(data->m_ptr, *x, y, (unsigned int)ft_pixel_get(&data->txt_ptr[3], data->tex_x, texY));
		y++;
	}
}

void	render_frames2(t_data *data, int *x)
{
	if(data->ray_dir_y < 0)
	{
		data->step_y = -1;
		data->side_dist_y = (data->pos_y - data->map_y) * data->delta_dist_y;
	}
	else
	{
		data->step_y = 1;
		data->side_dist_y = (data->map_y + 1.0 - data->pos_y) * data->delta_dist_y;
	}
    check_hit(data);
	calculate_cols(data);
	draw_cols(data, x);
}
