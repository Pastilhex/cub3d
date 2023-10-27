/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures_extra.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:21:33 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/27 15:21:48 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_textures_extra_img(t_data *d)
{
	new_img(d, ceilinglamp, d->map_ptr->ceilinglamp_texture);
	new_img(d, barrel, d->map_ptr->barrel_texture);
	new_img(d, soldier, d->map_ptr->soldier_texture);
	new_img(d, bed, d->map_ptr->bed_texture);
	new_img(d, redflag, d->map_ptr->redflag_texture);
	new_img(d, hangskeleton, d->map_ptr->hangskeleton_texture);
	new_img(d, kitchenware, d->map_ptr->kitchenware_texture);
	new_img(d, oven, d->map_ptr->oven_texture);
	new_img(d, pilar, d->map_ptr->pilar_texture);
	new_img(d, table, d->map_ptr->table_texture);
	new_img(d, weapons, d->map_ptr->weapons_texture);
	new_img(d, knight, d->map_ptr->knight_texture);
	new_img(d, bush, d->map_ptr->bush_texture);
	new_img(d, groundlamp, d->map_ptr->groundlamp_texture);
	new_img(d, lamp, d->map_ptr->lamp_texture);
	new_img(d, sink, d->map_ptr->sink_texture);
}

void	init_extra_bonus(t_map *map, t_data *d)
{
	(void)d;
	map->ceilinglamp_texture = "./bonus/textures/xpm/finalceilinglamp.xpm";	//a
	map->barrel_texture = "./bonus/textures/xpm/barrel.xpm";				//b
	map->soldier_texture = "./bonus/textures/xpm/guard/front_01.xpm";		//c
	map->bed_texture = "./bonus/textures/xpm/bed.xpm";						//d
	map->redflag_texture = "./bonus/textures/xpm/redflag.xpm";				//e
	map->hangskeleton_texture = "./bonus/textures/xpm/hangskeleton.xpm";	//f
	map->kitchenware_texture = "./bonus/textures/xpm/kitchenware.xpm";		//g
	map->oven_texture = "./bonus/textures/xpm/oven.xpm";					//h
	map->pilar_texture = "./bonus/textures/xpm/pilar.xpm";					//k
	map->table_texture = "./bonus/textures/xpm/table.xpm";					//l
	map->weapons_texture = "./bonus/textures/xpm/weapons.xpm";				//m
	map->knight_texture = "./bonus/textures/xpm/knight.xpm";				//n
	map->bush_texture = "./bonus/textures/xpm/bush.xpm";					//o
	map->groundlamp_texture = "./bonus/textures/xpm/ground_lamp.xpm";		//p
	map->lamp_texture = "./bonus/textures/xpm/lamp.xpm";					//q
	map->sink_texture = "./bonus/textures/xpm/sink.xpm";					//r
}

int	allowed_sprites(int c)
{
	if (c == 'a' || c == 'b' || c == 'c' || c == 'd'
		|| c == 'e' || c == 'f' || c == 'g' || c == 'h'
		|| c == 'k' || c == 'l' || c == 'm' || c == 'n'
		|| c == 'o' || c == 'p' || c == 'q' || c == 'r')
		return (1);
	return (0);
}

bool	dont_hit(t_data *data)
{
	if (data->map_ptr->world_map[data->map_x][data->map_y] != '0'
		&& data->map_ptr->world_map[data->map_x][data->map_y] != '9'
		&& data->map_ptr->world_map[data->map_x][data->map_y] != 'b'
		&& data->map_ptr->world_map[data->map_x][data->map_y] != 'c'
		&& data->map_ptr->world_map[data->map_x][data->map_y] != 'd'
		&& data->map_ptr->world_map[data->map_x][data->map_y] != 'e'
		&& data->map_ptr->world_map[data->map_x][data->map_y] != 'f'
		&& data->map_ptr->world_map[data->map_x][data->map_y] != 'g'
		&& data->map_ptr->world_map[data->map_x][data->map_y] != 'h'
		&& data->map_ptr->world_map[data->map_x][data->map_y] != 'k'
		&& data->map_ptr->world_map[data->map_x][data->map_y] != 'l'
		&& data->map_ptr->world_map[data->map_x][data->map_y] != 'm'
		&& data->map_ptr->world_map[data->map_x][data->map_y] != 'n'
		&& data->map_ptr->world_map[data->map_x][data->map_y] != 'o'
		&& data->map_ptr->world_map[data->map_x][data->map_y] != 'p'
		&& data->map_ptr->world_map[data->map_x][data->map_y] != 'q'
		&& data->map_ptr->world_map[data->map_x][data->map_y] != 'r')
		return (true);
	return (false);
}
