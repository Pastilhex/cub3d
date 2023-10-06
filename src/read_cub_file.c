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
	map->worldMap = NULL;
	map->wallX = 0.0;
	map->step = 0.0;
	map->texPos = 0.0;
	map->texY = 0;
	map->start_dir = '0';
	map->data_ptr = d;
	map->color = 0;
	map->data_ptr = d;
}

void	read_cub_file(t_map *map)
{
	get_ttl_nbr_lines(map);
	map->fd = open(map->map_path, O_RDONLY);
	map->get_line = get_next_line(map->fd);
	get_elements(map);
	get_map_size(map);
	get_map_to_array(map);
	free(map->get_line);
}
