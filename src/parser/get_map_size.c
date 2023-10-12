/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:23:43 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/12 10:56:46 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_map_size_last_while(t_map *map)
{
	while (map->get_line && ft_strcmp(map->get_line, "\0") != 0)
	{
		if (ft_strncmp(map->get_line, "\n", 1) != 0)
		{
			close(map->fd);
			perror_close("Invalid map configuration", map);
		}
		free(map->get_line);
		map->get_line = get_next_line(map->fd);
	}
}

void	get_map_size(t_map *map)
{
	free(map->get_line);
	map->get_line = get_next_line(map->fd);
	while (map->get_line && ft_strncmp(map->get_line, "\n", 1) == 0)
	{
		map->line_nbr++;
		free(map->get_line);
		map->get_line = get_next_line(map->fd);
	}
	map->map_start = map->line_nbr;
	while (map->get_line && (ft_strcmp(map->get_line, "\n") != 0))
	{
		map->line_nbr++;
		free(map->get_line);
		map->get_line = get_next_line(map->fd);
	}
	map->map_end = map->line_nbr;
	map->world_map = ft_calloc(map->map_end - map->map_start, sizeof(char *));
	if (!map->world_map)
		return ;
	get_map_size_last_while(map);
	free(map->get_line);
	close(map->fd);
}
