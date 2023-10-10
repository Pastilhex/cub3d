/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_integrity.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:23:47 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/10 14:07:47 by joaoalme         ###   ########.fr       */
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
	copy = malloc((map->map_end - map->map_start) * sizeof(char *));
	if (!copy)
		return (NULL);
	while (i < (map->map_end - map->map_start))
	{
		copy[i] = malloc(ft_strlen(map->world_map[i]) * sizeof(char) + 1);
		if (!copy[i])
			return (NULL);
		while (j < ft_strlen(map->world_map[i]))
		{
			copy[i][j] = map->world_map[i][j];
			j++;
		}
		copy[i][j] = '\0';
		j = 0;
		i++;
	}
	return (copy);
}

void	check_map_inside(t_map *map, char **floor, int i, int j)
{
	if (i < 0 || j < 0 || i >= map->map_end - map->map_start
		|| j >= ft_strlen(floor[i]) || floor[i][j] != '0')
	{
		if (floor[i][j] != '0' && floor[i][j] != '1' && floor[i][j] != 'X')
			map->inside_checked = 1;
		return ;
	}
	floor[i][j] = 'X';
	check_map_inside(map, floor, i + 1, j);
	check_map_inside(map, floor, i - 1, j);
	check_map_inside(map, floor, i, j + 1);
	check_map_inside(map, floor, i, j - 1);
}

void	check_map_integrity(t_map *map)
{
	char	**map_copy;

	map->inside_checked = 0;
	map_copy = to_copy_map(map);
	check_map_inside(map, map_copy, map->data_ptr->pos_x, map->data_ptr->pos_y);
	free_arr(map_copy, map);
	if (map->inside_checked == 1)
		perror_close("Map Integrity Fail", map);
}
