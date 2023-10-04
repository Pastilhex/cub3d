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

void	init_t_map(t_map *map)
{
	map->fd = 0;
	map->ttl_nbr_lines = 0;
	map->map_length = 0;
	map->map_width = 0;
	map->extension = NULL;
	map->get_line = NULL;
	map->map_path = NULL;
	map->north_texture = NULL;
	map->south_texture = NULL;
	map->west_texture = NULL;
	map->east_texture = NULL;
	map->floor_texture = NULL;
	map->ceiling_texture = NULL;
	map->worldMap = NULL;
	map->start_dir = '0';
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
