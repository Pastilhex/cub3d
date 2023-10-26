/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:42:45 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/26 20:06:33 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
	d->txt_ptr = malloc(sizeof(t_texture) * 15);
	d->map_ptr = map_ptr;
	d->m_ptr = m;
	d->mini_map_ptr = NULL;
	d->head = NULL;
	d->temp_head = NULL;
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
	d->move_margin = 0.0;
	d->time = 0.0;
	d->old_time = 0.0;
	d->camera_x = 0.0;
	d->ray_dir_x = 0.0;
	d->ray_dir_y = 0.0;
	d->map_x = 0;
	d->map_y = 0;
	d->press_space = 0;
	d->door_state = 0;
	init_mlx(m);
	init_data2(d, map_ptr, m);
}

static void	init_t_map2(t_map *map, t_data *d)
{
	map->map_start = 0;
	map->map_end = 0;
	map->larger_line = 0;
	map->line_nbr = 0;
	map->has_player = 0;
	map->sprites_nb = 0;
	d->txt_hands = NULL;
	d->txt_head = NULL;
	map->start_time_head = 0;
	map->start_time_hand = 0;
	map->start_time_door = 0;
}

void	init_t_map(t_map *map, t_data *d)
{
	map->fd = 0;
	map->ttl_nbr_lines = 0;
	map->extension = NULL;
	map->get_line = NULL;
	map->north_texture = NULL;
	map->south_texture = NULL;
	map->west_texture = NULL;
	map->east_texture = NULL;
	map->floor_texture = NULL;
	map->ceiling_texture = NULL;
	map->world_map = NULL;
	map->miniplayer_texture = NULL;
	map->door_texture = NULL;
	map->wall_x = 0.0;
	map->step = 0.0;
	map->tex_pos = 0.0;
	map->tex_y = 0;
	map->start_dir = '0';
	map->data_ptr = d;
	map->color = 0;
	map->data_ptr = d;
	init_t_map2(map, d);
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
