/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures_img.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:21:33 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/16 15:36:11 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	new_img(t_data *d, enum e_direction var, char *txt)
{
	d->txt_ptr[var].img = mlx_xpm_file_to_image(d->m_ptr->mlx,
			txt, &d->txt_ptr[var].txt_w,
			&d->txt_ptr[var].txt_h);
	d->txt_ptr[var].addr = mlx_get_data_addr(d->txt_ptr[var].img,
			&d->txt_ptr[var].bits_per_pixel, &d->txt_ptr[var].line_length,
			&d->txt_ptr[var].endian);
}

void	init_bonus_sprites(t_data *d)
{
	new_img(d, ceilinglamp, d->map_ptr->ceilinglamp_texture);			//11
	new_img(d, barrel, d->map_ptr->barrel_texture);				//13
}	

void	init_bonus_textures(t_data *d)
{
	new_img(d, hud, d->map_ptr->hud_texture);							//4
	new_img(d, eagle, d->map_ptr->eagle_wall_texture);					//5
	new_img(d, flag, d->map_ptr->flag_wall_texture);					//6
	new_img(d, blue1, d->map_ptr->blue1_wall_texture);					//7
	new_img(d, blue2, d->map_ptr->blue2_wall_texture);					//8
	new_img(d, blueskeleton, d->map_ptr->blueskeleton_wall_texture);	//9
	new_img(d, blueempty, d->map_ptr->blueempty_wall_texture);			//10
	new_img(d, hands, d->map_ptr->hands);								//12
}

void	init_textures_img(t_data *d)
{
	new_img(d, south, d->map_ptr->south_texture);		//0
	new_img(d, north, d->map_ptr->north_texture);		//1
	new_img(d, east, d->map_ptr->east_texture);			//2
	new_img(d, west, d->map_ptr->west_texture);			//3
	init_bonus_textures(d);
	init_bonus_sprites(d);
}

void	init_bonus(t_map *map, t_data *d)
{
	(void) d;
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
	map->hands = "./bonus/textures/xpm/handsgun.xpm";
}