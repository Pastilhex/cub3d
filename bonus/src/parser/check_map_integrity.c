/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_integrity.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:23:47 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/27 17:21:07 by joaoalme         ###   ########.fr       */
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
	copy = malloc((map->m_end - map->m_start) * sizeof(char *));
	if (!copy)
		return (NULL);
	while (i < (map->m_end - map->m_start))
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

int	ft_begin_strlen(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	return (i);
}

int	find_next_space(t_map *map, char **map_copy)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	map->map_copy_x = 0;
	map->map_copy_y = 0;
	while (i < (map->m_end - map->m_start))
	{
		while (map_copy[i][j])
		{
			if (map_copy[i][j] == '0')
			{
				map->map_copy_x = i;
				map->map_copy_y = j;
				return (0);
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

void	check_map_inside(t_map *map, char **floor, int i, int j)
{
	if (i < (map->m_start - map->m_start) || i > (map->m_end - map->m_start - 1)
		|| j < ft_begin_strlen(floor[i]) || j >= ft_strlen(floor[i])
		|| (floor[i][j] != '0' && floor[i][j] != '9'))
	{
		if (i < 0 || j < 0 || i >= map->m_end - map->m_start)
		{
			map->inside_checked = 1;
			return ;
		}
		if (floor[i][j] != '0' && !ft_isdigit(floor[i][j])
		&& !allowed_sprites(floor[i][j]) && floor[i][j] != 'X')
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
	while (map->inside_checked == 0)
	{
		if (find_next_space(map, map_copy) == 1)
			break ;
		check_map_inside(map, map_copy, map->map_copy_x, map->map_copy_y);
	}
	free_arr(map_copy, map);
	if (map->inside_checked == 1)
		perror_close("Map Integrity Fail", map);
}
