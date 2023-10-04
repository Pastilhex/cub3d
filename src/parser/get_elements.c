/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:23:39 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/04 18:28:38 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_elements(t_map *map)
{
	while (map->get_line)
	{
		if (!map->north_texture)
			if (find_texture(map->get_line, "N ") || find_texture(map->get_line, "NO "))
				map->north_texture = get_texture(map->get_line);
		if (!map->south_texture)
			if (find_texture(map->get_line, "S ") || find_texture(map->get_line, "SO "))
				map->south_texture = get_texture(map->get_line);
		if (!map->west_texture)
			if (find_texture(map->get_line, "W ") || find_texture(map->get_line, "WE "))
				map->west_texture = get_texture(map->get_line);
		if (!map->east_texture)
			if (find_texture(map->get_line, "E ") || find_texture(map->get_line, "EA "))
				map->east_texture = get_texture(map->get_line);
		if (!map->ceiling_texture)
			if (find_texture(map->get_line, "C"))
				map->ceiling_texture = get_back_line(map->get_line);
		if (!map->floor_texture)
			if (find_texture(map->get_line, "F"))
				map->floor_texture = get_back_line(map->get_line);
		if (map->north_texture && map->south_texture && map->west_texture && map->east_texture && map->ceiling_texture && map->floor_texture)
			break ;
		map->get_line = get_next_line(map->fd);
	}
}
