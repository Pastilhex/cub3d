/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_integrity.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:23:47 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/08 21:07:43 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	**to_copy_map(t_map *map)
{
	int		i;
	int		j;
	char	**copy;

	i = 0;
	j = 0;
	copy = malloc(map->map_length * sizeof(char *));
	if (!copy)
		return (NULL);
	while (i < map->map_length)
	{
		copy[i] = malloc(map->map_width * sizeof(char));
		if (!copy[i])
			return (NULL);
		while (j < map->map_width)
		{
			copy[i][j] = map->worldMap[i][j];
			j++;
		}
		copy[i][j] = '\0';
		j = 0;
		i++;
	}
	return (copy);
}
void	check_map_copy(t_map *map, char **floor, int i, int j)
{
	if (i < 0 || j < 0 || i >= map->map_length || j >= map->map_width || floor[i][j] != '0')
	{
		return ;
	}
	floor[i][j] = 'X';
	ft_print_array(floor, map->map_length);
	check_map_copy(map, floor, i + 1, j);		
	check_map_copy(map, floor,i - 1, j);		
	check_map_copy(map, floor,i, j + 1);		
	check_map_copy(map, floor,i, j - 1);
}



void	check_map_integrity(t_map *map)
{
	int i;
	int j;
	char **map_copy;

	i = 0;
	j = 0;
	map->border_checked = 0;
	map_copy = to_copy_map(map);
	while (i < map->map_length)
	{
		j = 0;
		while (map->worldMap[j])
		{
			// Search for player position
			if (is_direction( map->worldMap[i][j]))
			{
				
				check_map_copy(map, map_copy, i, j);
				if (map->border_checked == 1)
					perror_close("Map Integrity Fail", map);
			}
			j++;
		}
		if (map->border_checked == 1)
			break ;
		free(map->get_line);
		i++;
		map->get_line = get_next_line(map->fd);
	}
	close(map->fd);
}
