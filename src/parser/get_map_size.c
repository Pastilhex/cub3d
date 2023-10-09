/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:23:43 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/09 21:23:12 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_map_size(t_map *map)
{
	free(map->get_line);
	map->get_line = get_next_line(map->fd);
	while (ft_strncmp(map->get_line, "\n", 1) == 0)
	{
		map->line_nbr++;
		free(map->get_line);
		map->get_line = get_next_line(map->fd);
	}
	map->map_start = map->line_nbr;
	while (ft_strncmp(map->get_line, "\n", 1) != 0)
	{
		map->line_nbr++;
		map->map_length++;
		if (ft_strlen(map->get_line) > map->map_width)
			map->map_width = ft_strlen(map->get_line);
		free(map->get_line);
		map->get_line = get_next_line(map->fd);
	}
	map->map_end = map->line_nbr;
	map->world_map = ft_calloc(map->map_end - map->map_start, sizeof(char *));
	if (!map->world_map)
		return ;
	close(map->fd);
}
