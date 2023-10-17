/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frames.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:11:26 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/16 22:49:58 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	render_frames1(t_data *data, int *x)
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
	data->hit = '0';
	if (data->ray_dir_x < 0)
	{
		data->step_x = -1;
		data->side_dist_x = (data->pos_x - data->map_x) * data->delta_dist_x;
	}
	else
	{
		data->step_x = 1;
		data->side_dist_x = (data->map_x + 1.0 - data->pos_x) * \
			data->delta_dist_x;
	}
}

static void	fps(t_data *data)
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
		// printf("FPS: %d\n", data->fps);
		data->fps = 0;
		data->tps = 0.0;
	}
}

int	get_rgb(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

void	init_t_rend(t_rend_sprite *r)
{
	r->x = 0;
	r->y = 0;
	r->d = 0;
	r->sprite_x = 0.0;
	r->sprite_y = 0.0;
	r->inv_det = 0.0;
	r->transform_x = 0.0;
	r->transform_y = 0.0;
	r->sprite_screen_x = 0;
	r->sprite_height = 0;
	r->sprite_width = 0;
	r->draw_start_y = 0;
	r->draw_end_y = 0;
	r->draw_start_x = 0;
	r->draw_end_x = 0;
	r->stripe = 0;
	r->tex_y = 0;
}

int	render_frames(void *arg)
{
	t_data			*data;
	t_rgb			*sky;
	t_rgb			*floor;
	t_map			*m;
	t_rend_sprite	*r;

	init_t_rend(r);
	

	data = arg;
	m = data->map_ptr;
	sky = &data->map_ptr->ceiling_colors;
	floor = &data->map_ptr->floor_colors;
	background(*data->m_ptr, get_rgb(sky->r, sky->g, sky->b), \
		get_rgb(floor->r, floor->g, floor->b));
	r->x = 0;
	while (r->x < SCREENWIDTH)
	{
		render_frames1(data, &r->x);
		render_frames2(data, &r->x);
		data->z_buffer[r->x] = data->perp_wall_dist;
		r->x++;
	}
	r->x = 0;
	data->head = creat_node(data, r->x);
	while (++r->x < m->sprites_nb )
    {
		add_element_back(data->head, data, r->x);
    }
	order_list(&data->head);
	while (data->head != NULL)
	{
		r->x = 0;
		m->sprite_x = m->sprite_arr[data->head->order].x;
		m->sprite_y = m->sprite_arr[data->head->order].y;
		sprite_x = m->sprite_x - data->pos_x + 0.5;
		sprite_y = m->sprite_y - data->pos_y + 0.5;
		inv_det = 1.0 / (data->plane_x * data->dir_y - data->dir_x * data->plane_y);
		transform_x = inv_det * (data->dir_y * sprite_x - data->dir_x * sprite_y);
		transform_y = inv_det * (-data->plane_y * sprite_x + data->plane_x * sprite_y); 
		sprite_screen_x = (int)((SCREENWIDTH / 2) * (1 + transform_x / transform_y));
		sprite_height = abs((int)(SCREENHEIGHT / transform_y));
		draw_start_y = -sprite_height / 2 + SCREENHEIGHT / 2;
		if (draw_start_y < 0)
			draw_start_y = 0;
		draw_end_y = sprite_height / 2 + SCREENHEIGHT / 2;
		if (draw_end_y >= SCREENHEIGHT)
			draw_end_y = SCREENHEIGHT - 1;
		sprite_width = abs((int)(SCREENWIDTH / transform_y));
		draw_start_x = -sprite_width / 2 + sprite_screen_x;
		if (draw_start_x < 0)
			draw_start_x = 0;
		draw_end_x = sprite_width / 2 + sprite_screen_x;
		if(draw_end_x >= SCREENWIDTH)
			draw_end_x = SCREENWIDTH - 1;
		stripe = draw_start_x;
		while (stripe < draw_end_x)
		{
			data->tex_x = (int)(256 * (stripe - (-sprite_width / 2 + sprite_screen_x)) * TEXWIDTH / sprite_width) / 256;
			if ((transform_y > 0 && stripe > 0 && stripe < SCREENWIDTH && transform_y < data->z_buffer[stripe]))
			{
				y = draw_start_y;
				while (y < draw_end_y)
				{
					d = y * 256 - SCREENHEIGHT * 128 + sprite_height * 128;
					tex_y = ((d * TEXHEIGHT) / sprite_height) / 256;
					ft_pixel_put(data->m_ptr, stripe, y, (unsigned int)ft_pixel_get(m->sprite_arr[data->head->order].txt, data->tex_x, tex_y));
					y++;
				}
			}
			stripe++;	
		}
		data->head = data->head->next;
	}
	draw_hands(data);
	draw_hud(data);
	mlx_put_image_to_window(data->m_ptr->mlx, data->m_ptr->mlx_win, data->m_ptr->img, 0, 0);
	fps(data);
	data->move_speed = data->frame_time * 3;
	data->rot_speed = data->frame_time * 2.0;
	data->move_margin = 0.6;
	move_player(data);
	return (0);
}

