/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:23:43 by joaoalme          #+#    #+#             */
/*   Updated: 2023/09/29 18:27:12 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_map_size(t_map *map)
{
	map->get_line = get_next_line(map->fd);
	while (map->get_line)
	{
		map->map_length++;
		if (ft_strlen(map->get_line) > map->map_width)
			map->map_width = ft_strlen(map->get_line);
		map->get_line = get_next_line(map->fd);
	}
	map->worldMap = (char**)ft_calloc(map->map_length, sizeof(char *));
	if (!map->worldMap)
		return ;
	close(map->fd);
}