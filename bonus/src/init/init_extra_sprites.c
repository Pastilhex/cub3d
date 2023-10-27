/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_extra_sprites.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:21:33 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/27 17:22:54 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	set_sprite_extra_three(t_map *m, int i, int j, char c)
{
	if (c == 'o')
	{
		m->world_map[i][j] = 'o';
		m->sprite_arr[m->sprite_index].txt = &m->data_ptr->txt_ptr[bush];
	}
	if (c == 'p')
	{
		m->sprite_arr[m->sprite_index].txt = &m->data_ptr->txt_ptr[groundlamp];
		m->world_map[i][j] = 'p';
	}
	if (c == 'q')
	{
		m->sprite_arr[m->sprite_index].txt = &m->data_ptr->txt_ptr[lamp];
		m->world_map[i][j] = '0';
	}
	if (c == 'r')
	{
		m->sprite_arr[m->sprite_index].txt = &m->data_ptr->txt_ptr[sink];
		m->world_map[i][j] = 'r';
	}
}

void	set_sprite_extra_two(t_map *m, int i, int j, char c)
{
	if (c == 'k')
	{
		m->world_map[i][j] = 'k';
		m->sprite_arr[m->sprite_index].txt = &m->data_ptr->txt_ptr[pilar];
	}
	if (c == 'l')
	{
		m->sprite_arr[m->sprite_index].txt = &m->data_ptr->txt_ptr[table];
		m->world_map[i][j] = 'l';
	}
	if (c == 'm')
	{
		m->sprite_arr[m->sprite_index].txt = &m->data_ptr->txt_ptr[weapons];
		m->world_map[i][j] = 'm';
	}
	if (c == 'n')
	{
		m->sprite_arr[m->sprite_index].txt = &m->data_ptr->txt_ptr[knight];
		m->world_map[i][j] = 'n';
	}
	set_sprite_extra_three(m, i, j, c);
}

void	set_sprite_extra_one(t_map *m, int i, int j, char c)
{
	if (c == 'e')
	{
		m->world_map[i][j] = 'e';
		m->sprite_arr[m->sprite_index].txt = &m->data_ptr->txt_ptr[redflag];
	}
	if (c == 'f')
	{
		m->sprite_arr[m->sprite_index].txt
			= &m->data_ptr->txt_ptr[hangskeleton];
		m->world_map[i][j] = 'f';
	}
	if (c == 'g')
	{
		m->sprite_arr[m->sprite_index].txt = &m->data_ptr->txt_ptr[kitchenware];
		m->world_map[i][j] = '0';
	}
	if (c == 'h')
	{
		m->sprite_arr[m->sprite_index].txt = &m->data_ptr->txt_ptr[oven];
		m->world_map[i][j] = 'h';
	}
	set_sprite_extra_two(m, i, j, c);
}

void	set_sprite_extra(t_map *m, int i, int j, char c)
{
	if (c == 'a')
	{
		m->world_map[i][j] = '0';
		m->sprite_arr[m->sprite_index].txt = &m->data_ptr->txt_ptr[ceilinglamp];
	}
	if (c == 'b')
	{
		m->sprite_arr[m->sprite_index].txt = &m->data_ptr->txt_ptr[barrel];
		m->world_map[i][j] = 'b';
	}
	if (c == 'c')
	{
		m->sprite_arr[m->sprite_index].txt = &m->data_ptr->txt_ptr[soldier];
		m->world_map[i][j] = 'c';
	}
	if (c == 'd')
	{
		m->sprite_arr[m->sprite_index].txt = &m->data_ptr->txt_ptr[bed];
		m->world_map[i][j] = 'd';
	}
	set_sprite_extra_one(m, i, j, c);
}
