/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_map_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:53:33 by ialves-m          #+#    #+#             */
/*   Updated: 2023/09/29 13:08:005 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_t_map(t_map *m)
{
	m->fd = 0;
	m->ttl_nbr_lines = 0;
	m->map_length = 0;
	m->map_length = 0;
	m->extension = NULL;
	m->get_line = NULL;
	m->map_path = NULL;
	m->north_texture = NULL;
	m->south_texture = NULL;
	m->west_texture = NULL;
	m->east_texture = NULL;
	m->floor_texture = NULL;
	m->ceiling_texture = NULL;
	m->worldMap = NULL;
}

void	read_map_from_file(t_map *map)
{
	get_ttl_nbr_lines(map);
	map->fd = access_file(map);
	map->get_line = get_next_line(map->fd);
	get_elements(map);
	get_map_size(map);
	get_map_to_array(map);
}
