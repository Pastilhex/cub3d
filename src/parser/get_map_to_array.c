/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_to_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:23:47 by joaoalme          #+#    #+#             */
/*   Updated: 2023/09/29 18:27:10 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_map_to_array(t_map *map)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	map->fd = access_file(map);
	map->get_line = get_next_line(map->fd);
	while (i < (map->ttl_nbr_lines - map->map_length))
	{
		map->get_line = get_next_line(map->fd);
		i++;
	}
	i = 0;
	while (map->get_line)
	{
		map->worldMap[i] = ft_calloc(ft_strlen(map->get_line + 1), sizeof(char));
		j = 0;
		k = 0;
		while (map->get_line[j])
		{
			if (map->get_line[j] == ',')
				j++;
			else if (map->get_line[j] == ' ')
			{
				map->worldMap[i][k] = map->get_line[j];
				j += 2;
				k++;
			}
			else
			{
				map->worldMap[i][k] = map->get_line[j];
				j++;
				k++;
			}
		}
		i++;
		map->get_line = get_next_line(map->fd);
	}
	close(map->fd);
}