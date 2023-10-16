/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frames2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:05:09 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/16 08:57:54 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	check_hit(t_data *data)
{
	while (data->hit == '0')
	{
		if (data->side_dist_x < data->side_dist_y)
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
		if (data->map_ptr->world_map[data->map_x][data->map_y] != '0')
			data->hit = '1';
	}
	if (data->side == '0')
		data->perp_wall_dist = (data->side_dist_x - data->delta_dist_x);
	else
		data->perp_wall_dist = (data->side_dist_y - data->delta_dist_y);
}

static void	calculate_cols(t_data *data)
{
	data->pitch = 0;
	data->line_height = (int)(SCREENHEIGHT / data->perp_wall_dist);
	data->draw_start = -data->line_height / 2 + SCREENHEIGHT / 2 + data->pitch;
	if (data->draw_start < 0)
		data->draw_start = 0;
	data->draw_end = data->line_height / 2 + SCREENHEIGHT / 2 + data->pitch;
	if (data->draw_end >= SCREENHEIGHT)
		data->draw_end = SCREENHEIGHT - 1;
	if (data->side == '0')
		data->map_ptr->wall_x = data->pos_y + \
			data->perp_wall_dist * data->ray_dir_y;
	else
		data->map_ptr->wall_x = data->pos_x + \
			data->perp_wall_dist * data->ray_dir_x;
	data->map_ptr->wall_x -= floor((data->map_ptr->wall_x));
	data->tex_x = (int)(data->map_ptr->wall_x * (double)TEXWIDTH);
	if (data->side == '0' && data->ray_dir_x > 0)
		data->tex_x = TEXWIDTH - data->tex_x - 1;
	if (data->side == '1' && data->ray_dir_y < 0)
		data->tex_x = TEXWIDTH - data->tex_x - 1;
	data->map_ptr->step = 1.0 * TEXHEIGHT / data->line_height;
	data->map_ptr->tex_pos = (data->draw_start - data->pitch - \
		(double)SCREENHEIGHT / 2 + (double)data->line_height / 2) * \
			data->map_ptr->step;
}

void	draw_wall(t_data *d, char wall_nbr, t_texture *txt_ns, t_texture *txt_we)
{
	if (d->side == '0' && d->ray_dir_x > 0 && d->map_ptr->world_map[(int)d->map_x][(int)d->map_y] == wall_nbr)
		ft_pixel_put(d->m_ptr, *d->draw_ptr->x, d->draw_ptr->y, (unsigned int)ft_pixel_get(txt_ns, d->tex_x, d->draw_ptr->tex_y));

	else if (d->side == '0' && d->ray_dir_x < 0 && d->map_ptr->world_map[(int)d->map_x][(int)d->map_y] == wall_nbr)
		ft_pixel_put(d->m_ptr, *d->draw_ptr->x, d->draw_ptr->y, (unsigned int)ft_pixel_get(txt_ns, d->tex_x, d->draw_ptr->tex_y));

	else if (d->side == '1' && d->ray_dir_y > 0 && d->map_ptr->world_map[(int)d->map_x][(int)d->map_y] == wall_nbr)
		ft_pixel_put(d->m_ptr, *d->draw_ptr->x, d->draw_ptr->y, (unsigned int)ft_pixel_get(txt_we, d->tex_x, d->draw_ptr->tex_y));

	else if (d->side == '1' && d->ray_dir_y < 0 && d->map_ptr->world_map[(int)d->map_x][(int)d->map_y] == wall_nbr)
		ft_pixel_put(d->m_ptr, *d->draw_ptr->x, d->draw_ptr->y, (unsigned int)ft_pixel_get(txt_we, d->tex_x, d->draw_ptr->tex_y));
}

// void	put_img_to_img(t_texture dst, t_texture src, int x, int y)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	while(i < src.txt_w) 
// 	{
// 		j = 0;
// 		while (j < src.txt_h)
// 		{
// 			put_pixel_img(dst, x + i, y + j, get_pixel_img(src, i, j));
// 			j++;
// 		}
// 		i++;
// 	}
// }

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

		// // Wall 1 - Gray Wall
		draw_wall(data, '1', &data->txt_ptr[0], &data->txt_ptr[2]);

		// // Wall 2 - Flag Wall
		draw_wall(data, '2', &data->txt_ptr[6], &data->txt_ptr[6]);

		// // Wall 3 - Eagle Wall
		draw_wall(data, '3', &data->txt_ptr[5], &data->txt_ptr[5]);

		// // Wall 4 - Blue wall
		draw_wall(data, '4', &data->txt_ptr[7], &data->txt_ptr[8]);

		// // Wall 5 - Blue wall Door Skeleton 
		draw_wall(data, '5', &data->txt_ptr[9], &data->txt_ptr[10]);

		if (data->side == '0' && data->ray_dir_x > 0 && data->map_ptr->world_map[(int)data->map_x][(int)data->map_y] == '6')
			ft_pixel_put(data->m_ptr, *draw.x, draw.y, (unsigned int)ft_pixel_get(&data->txt_ptr[11], data->tex_x, draw.tex_y));
		else if (data->side == '0' && data->ray_dir_x < 0 && data->map_ptr->world_map[(int)data->map_x][(int)data->map_y] == '6')
			ft_pixel_put(data->m_ptr, *draw.x, draw.y, (unsigned int)ft_pixel_get(&data->txt_ptr[11], data->tex_x, draw.tex_y));
		else if (data->side == '1' && data->ray_dir_y > 0 && data->map_ptr->world_map[(int)data->map_x][(int)data->map_y] == '6')
			ft_pixel_put(data->m_ptr, *draw.x, draw.y, (unsigned int)ft_pixel_get(&data->txt_ptr[11], data->tex_x, draw.tex_y));
		else if (data->side == '1' && data->ray_dir_y < 0 && data->map_ptr->world_map[(int)data->map_x][(int)data->map_y] == '6')
			ft_pixel_put(data->m_ptr, *draw.x, draw.y, (unsigned int)ft_pixel_get(&data->txt_ptr[11], data->tex_x, draw.tex_y));
		
		// if (data->side == '0' && data->ray_dir_x > 0 && data->map_ptr->world_map[(int)data->map_x][(int)data->map_y] == '1')
		// 	ft_pixel_put(data->m_ptr, *draw.x, draw.y, (unsigned int)ft_pixel_get(&data->txt_ptr[0], data->tex_x, draw.tex_y));
		// else if (data->side == '0' && data->ray_dir_x < 0 && data->map_ptr->world_map[(int)data->map_x][(int)data->map_y] == '1')
		// 	ft_pixel_put(data->m_ptr, *draw.x, draw.y, (unsigned int)ft_pixel_get(&data->txt_ptr[0], data->tex_x, draw.tex_y));
		// else if (data->side == '1' && data->ray_dir_y > 0 && data->map_ptr->world_map[(int)data->map_x][(int)data->map_y] == '1')
		// 	ft_pixel_put(data->m_ptr, *draw.x, draw.y, (unsigned int)ft_pixel_get(&data->txt_ptr[2], data->tex_x, draw.tex_y));
		// else if (data->side == '1' && data->ray_dir_y < 0 && data->map_ptr->world_map[(int)data->map_x][(int)data->map_y] == '1')
		// 	ft_pixel_put(data->m_ptr, *draw.x, draw.y, (unsigned int)ft_pixel_get(&data->txt_ptr[2], data->tex_x, draw.tex_y));

		draw.y++;
	}
}

void	render_frames2(t_data *data, int *x)
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
