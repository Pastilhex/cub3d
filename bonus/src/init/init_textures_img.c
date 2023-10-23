/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures_img.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:21:33 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/23 21:44:49 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	new_img(t_data *d, enum e_direction var, char *txt)
{
	d->txt_ptr[var].img = mlx_xpm_file_to_image(d->m_ptr->mlx, txt,
			&d->txt_ptr[var].txt_w, &d->txt_ptr[var].txt_h);
	d->txt_ptr[var].addr = mlx_get_data_addr(d->txt_ptr[var].img,
			&d->txt_ptr[var].bits_per_pixel, &d->txt_ptr[var].line_length,
			&d->txt_ptr[var].endian);
}

void	init_textures_img(t_data *d)
{
	new_img(d, south, d->map_ptr->south_texture);
	new_img(d, north, d->map_ptr->north_texture);
	new_img(d, east, d->map_ptr->east_texture);
	new_img(d, west, d->map_ptr->west_texture);
	new_img(d, hud, d->map_ptr->hud_texture);
	new_img(d, eagle, d->map_ptr->eagle_wall_texture);
	new_img(d, flag, d->map_ptr->flag_wall_texture);
	new_img(d, blue1, d->map_ptr->blue1_wall_texture);
	new_img(d, blue2, d->map_ptr->blue2_wall_texture);
	new_img(d, blueskeleton, d->map_ptr->blueskeleton_wall_texture);
	new_img(d, blueempty, d->map_ptr->blueempty_wall_texture);
	new_img(d, ceilinglamp, d->map_ptr->ceilinglamp_texture);
	new_img(d, barrel, d->map_ptr->barrel_texture);
	new_img(d, mini_ground, d->map_ptr->ground_square_texture);
	new_img(d, miniplayer, d->map_ptr->miniplayer_texture);
	img_head(d);
	img_hands(d);
}

void	init_bonus(t_map *map, t_data *d)
{
	(void)d;
	map->sprite_index = 0;
	map->hud_texture = "./bonus/textures/xpm/hud.xpm";
	map->eagle_wall_texture = "./bonus/textures/xpm/eaglewall.xpm";
	map->flag_wall_texture = "./bonus/textures/xpm/flagwall.xpm";
	map->blue1_wall_texture = "./bonus/textures/xpm/bluewall1.xpm";
	map->blue2_wall_texture = "./bonus/textures/xpm/bluewall2.xpm";
	map->blueskeleton_wall_texture = "./bonus/textures/xpm/blueskeleton.xpm";
	map->blueempty_wall_texture = "./bonus/textures/xpm/blueempty.xpm";
	map->ceilinglamp_texture = "./bonus/textures/xpm/finalceilinglamp.xpm";
	map->barrel_texture = "./bonus/textures/xpm/barrel.xpm";
	map->miniplayer_texture = "./bonus/textures/xpm/mini_player.xpm";
	map->ground_square_texture = "./bonus/textures/xpm/ground_square.xpm";
	map->animated_head = ft_calloc(3, sizeof(char *));
	map->animated_head[0] = "./bonus/textures/xpm/guard/head_01.xpm";
	map->animated_head[1] = "./bonus/textures/xpm/guard/head_02.xpm";
	map->animated_head[2] = "./bonus/textures/xpm/guard/head_03.xpm";
	map->animated_hands = ft_calloc(3, sizeof(char *));
	map->animated_hands[0] = "./bonus/textures/xpm/handsgun01.xpm";
	map->animated_hands[1] = "./bonus/textures/xpm/handsgun02.xpm";
	map->animated_hands[2] = "./bonus/textures/xpm/handsgun03.xpm";
}

void	img_head(t_data *d)
{
	d->map_ptr->start_time = get_actual_time();
	d->swap_img = 0;
	d->txt_head = malloc(sizeof(t_texture) * 3);
	d->txt_head[0].img = mlx_xpm_file_to_image(d->m_ptr->mlx,
			d->map_ptr->animated_head[0], &d->txt_head[0].txt_w,
			&d->txt_head[0].txt_h);
	d->txt_head[0].addr = mlx_get_data_addr(d->txt_head[0].img,
			&d->txt_head[0].bits_per_pixel, &d->txt_head[0].line_length,
			&d->txt_head[0].endian);
	d->txt_head[1].img = mlx_xpm_file_to_image(d->m_ptr->mlx,
			d->map_ptr->animated_head[1], &d->txt_head[1].txt_w,
			&d->txt_head[1].txt_h);
	d->txt_head[1].addr = mlx_get_data_addr(d->txt_head[1].img,
			&d->txt_head[1].bits_per_pixel, &d->txt_head[1].line_length,
			&d->txt_head[1].endian);
	d->txt_head[2].img = mlx_xpm_file_to_image(d->m_ptr->mlx,
			d->map_ptr->animated_head[2], &d->txt_head[2].txt_w,
			&d->txt_head[2].txt_h);
	d->txt_head[2].addr = mlx_get_data_addr(d->txt_head[2].img,
			&d->txt_head[2].bits_per_pixel, &d->txt_head[2].line_length,
			&d->txt_head[2].endian);
}

void	img_hands(t_data *d)
{
	d->map_ptr->start_time = get_actual_time();
	d->swap_hands = 0;
	d->txt_hands = malloc(sizeof(t_texture) * 3);
	d->txt_hands[0].img = mlx_xpm_file_to_image(d->m_ptr->mlx,
			d->map_ptr->animated_hands[0], &d->txt_hands[0].txt_w,
			&d->txt_hands[0].txt_h);
	d->txt_hands[0].addr = mlx_get_data_addr(d->txt_hands[0].img,
			&d->txt_hands[0].bits_per_pixel, &d->txt_hands[0].line_length,
			&d->txt_hands[0].endian);
	d->txt_hands[1].img = mlx_xpm_file_to_image(d->m_ptr->mlx,
			d->map_ptr->animated_hands[1], &d->txt_hands[1].txt_w,
			&d->txt_hands[1].txt_h);
	d->txt_hands[1].addr = mlx_get_data_addr(d->txt_hands[1].img,
			&d->txt_hands[1].bits_per_pixel, &d->txt_hands[1].line_length,
			&d->txt_hands[1].endian);
	d->txt_hands[2].img = mlx_xpm_file_to_image(d->m_ptr->mlx,
			d->map_ptr->animated_hands[2], &d->txt_hands[2].txt_w,
			&d->txt_hands[2].txt_h);
	d->txt_hands[2].addr = mlx_get_data_addr(d->txt_hands[2].img,
			&d->txt_hands[2].bits_per_pixel, &d->txt_hands[2].line_length,
			&d->txt_hands[2].endian);
}
