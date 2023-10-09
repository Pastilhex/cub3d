/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:42:45 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/09 18:54:49 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	init_data2(t_data *d, struct s_map *map_ptr, t_mlx *m)
{
	d->side_dist_x = 0.0;
	d->side_dist_y = 0.0;
	d->delta_dist_x = 0.0;
	d->delta_dist_y = 0.0;
	d->perp_wall_dist = 0.0;
	d->step_x = 0;
	d->step_y = 0;
	d->hit = 0;
	d->side = 0;
	d->line_height = 0;
	d->draw_start = 0;
	d->draw_end = 0;
	d->old_dir_x = 0.0;
	d->old_plane_x = 0.0;
	d->frame_time = 0.0;
	d->fps = 0;
	d->tps = 0.0;
	d->tex_x = 0;
	d->txt_ptr = malloc(sizeof(t_texture) * 4);
	if (!d->txt_ptr)
		exit(EXIT_FAILURE);
	d->map_ptr = map_ptr;
	d->m_ptr = m;
}

void	init_data(t_data *d, struct s_map *map_ptr, t_mlx *m)
{
	d->move_up = 0;
	d->move_down = 0;
	d->move_left = 0;
	d->move_right = 0;
	d->slide_left = 0;
	d->slide_right = 0;
	d->pos_x = 0.0;
	d->pos_y = 0.0;
	d->dir_x = 0.0;
	d->dir_y = 0.0;
	d->plane_x = 0.0;
	d->plane_y = 0.0;
	d->move_speed = 0.0;
	d->rot_speed = 0.0;
	d->time = 0.0;
	d->old_time = 0.0;
	d->camera_x = 0.0;
	d->ray_dir_x = 0.0;
	d->ray_dir_y = 0.0;
	d->map_x = 0;
	d->map_y = 0;
	init_data2(d, map_ptr, m);
}

void	init_t_map(t_map *map, t_data *d)
{
	map->fd = 0;
	map->ttl_nbr_lines = 0;
	map->map_width = 0;
	map->map_length = 0;
	map->extension = NULL;
	map->get_line = NULL;
	map->north_texture = NULL;
	map->south_texture = NULL;
	map->west_texture = NULL;
	map->east_texture = NULL;
	map->floor_texture = NULL;
	map->ceiling_texture = NULL;
	map->world_map = NULL;
	map->wall_x = 0.0;
	map->step = 0.0;
	map->tex_pos = 0.0;
	map->tex_y = 0;
	map->start_dir = '0';
	map->data_ptr = d;
	map->color = 0;
	map->data_ptr = d;
	map->map_start = 0;
	map->map_end = 0;
	map->line_nbr = 0;
}

void	init_mlx(t_mlx *m)
{
	m->mlx = NULL;
	m->mlx_win = NULL;
}
