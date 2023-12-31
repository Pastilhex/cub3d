/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frames.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:11:26 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/19 19:1:03 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	calc_walls(t_data *data, int *x)
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

void	walls(t_data *data, t_rend_sprite *r)
{
	r->x = 0;
	while (r->x < SCREENWIDTH)
	{
		calc_walls(data, &r->x);
		draw_walls(data, &r->x);
		data->z_buffer[r->x] = data->perp_wall_dist;
		r->x++;
	}
}

void	doors(t_data *data, t_rend_sprite *r)
{
	r->x = 0;
	while (r->x < SCREENWIDTH)
	{
		calc_doors(data, &r->x);
		draw_doors(data, &r->x);
		r->x++;
		if (data->map_ptr->world_map[data->map_x][data->map_y] == '9')
			data->z_buffer[r->x] = data->perp_wall_dist;
	}
}

static void	main_render(t_map *m, t_data *data, t_rend_sprite *r)
{
	t_rgb			*sky;
	t_rgb			*floor;
	t_minimap		mm;

	sky = &data->map_ptr->ceiling_colors;
	floor = &data->map_ptr->floor_colors;
	background(*data->m_ptr, get_rgb(sky->r, sky->g, sky->b), \
		get_rgb(floor->r, floor->g, floor->b));
	walls(data, r);
	init_t_minimap(&mm, data);
	data->mini_map_ptr = &mm;
	create_big_map(data);
	draw_sprites(data, m, r);
	doors(data, r);
	clear_list(data->temp_head);
	draw_hands(data);
	draw_hud(data);
	draw_head_hud(data);
	get_minimap(data);
	free_arr2(data->mini_map_ptr->big_map, data->map_ptr->m_end
		- data->map_ptr->m_start + 10);
}

int	render_frames(void *arg)
{
	t_data			*data;
	t_map			*m;
	t_rend_sprite	*r;

	r = (t_rend_sprite *) malloc(sizeof(t_rend_sprite));
	init_t_rend(r);
	data = arg;
	data->t_rend_ptr = r;
	m = data->map_ptr;
	main_render(m, data, r);
	mlx_put_image_to_window(data->m_ptr->mlx, \
	data->m_ptr->mlx_win, data->m_ptr->img, 0, 0);
	fps(data);
	data->move_speed = data->frame_time * 3;
	if (m->data_ptr->move_left == 1 || m->data_ptr->move_right == 1)
		data->rot_speed = data->frame_time * 2.0;
	else
		data->rot_speed = data->frame_time * 1;
	data->move_margin = 0.4;
	move_player(data);
	free(r);
	return (0);
}
