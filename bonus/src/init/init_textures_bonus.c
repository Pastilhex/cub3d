/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:21:33 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/27 13:32:21 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
	new_img(d, miniplayer, d->map_ptr->miniplayer_texture);
	img_head(d);
	img_hands(d);
	img_door(d);
	init_textures_extra_img(d);
}

void	init_door(t_map *map)
{
	map->animated_door = ft_calloc(21, sizeof(char *));
	map->animated_door[0] = "./bonus/textures/xpm/door_00.xpm";
	map->animated_door[1] = "./bonus/textures/xpm/door_01.xpm";
	map->animated_door[2] = "./bonus/textures/xpm/door_02.xpm";
	map->animated_door[3] = "./bonus/textures/xpm/door_03.xpm";
	map->animated_door[4] = "./bonus/textures/xpm/door_04.xpm";
	map->animated_door[5] = "./bonus/textures/xpm/door_05.xpm";
	map->animated_door[6] = "./bonus/textures/xpm/door_06.xpm";
	map->animated_door[7] = "./bonus/textures/xpm/door_07.xpm";
	map->animated_door[8] = "./bonus/textures/xpm/door_08.xpm";
	map->animated_door[9] = "./bonus/textures/xpm/door_09.xpm";
	map->animated_door[10] = "./bonus/textures/xpm/door_10.xpm";
	map->animated_door[11] = "./bonus/textures/xpm/door_11.xpm";
	map->animated_door[12] = "./bonus/textures/xpm/door_12.xpm";
	map->animated_door[13] = "./bonus/textures/xpm/door_13.xpm";
	map->animated_door[14] = "./bonus/textures/xpm/door_14.xpm";
	map->animated_door[15] = "./bonus/textures/xpm/door_15.xpm";
	map->animated_door[16] = "./bonus/textures/xpm/door_16.xpm";
	map->animated_door[17] = "./bonus/textures/xpm/door_17.xpm";
	map->animated_door[18] = "./bonus/textures/xpm/door_18.xpm";
	map->animated_door[19] = "./bonus/textures/xpm/door_19.xpm";
	map->animated_door[20] = "./bonus/textures/xpm/door_20.xpm";
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
	map->miniplayer_texture = "./bonus/textures/xpm/mini_player.xpm";
	map->animated_head = ft_calloc(3, sizeof(char *));
	map->animated_head[0] = "./bonus/textures/xpm/guard/head_01.xpm";
	map->animated_head[1] = "./bonus/textures/xpm/guard/head_02.xpm";
	map->animated_head[2] = "./bonus/textures/xpm/guard/head_03.xpm";
	map->animated_hands = ft_calloc(3, sizeof(char *));
	map->animated_hands[0] = "./bonus/textures/xpm/handsgun01.xpm";
	map->animated_hands[1] = "./bonus/textures/xpm/handsgun02.xpm";
	map->animated_hands[2] = "./bonus/textures/xpm/handsgun03.xpm";
	init_door(map);
	init_extra_bonus(map, d);
}
