/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_integrity.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:23:47 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/07 22:39:34 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	**map_copy(t_map *map)
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
void	check_border_map(t_map *map, char **border, int i, int j)
{
	if (i < 0 || j < 0 || i >= map->map_length || j >= map->map_width || border[i][j] != '1')
	{
		if (i == map->border_begin_x && j == map->border_begin_y)
			map->border_checked = 1;
		else
			return ;
	}
	else if (border[i][j] == '1')
		border[i][j] = 'X';
	ft_print_array(border, map->map_length);
	check_border_map(map, border, i + 1, j);		
	check_border_map(map, border,i - 1, j);		
	check_border_map(map, border,i, j + 1);		
	check_border_map(map, border,i, j - 1);
}

void	check_map_integrity(t_map *map)
{
	int i;
	int j;
	char **border_map;

	i = 0;
	j = 0;
	map->border_checked = 0;
	border_map = map_copy(map);
	map->fd = access_file(map);
	map->get_line = get_next_line(map->fd);
	while (i < (map->ttl_nbr_lines - map->map_length))
	{
		free(map->get_line);
		map->get_line = get_next_line(map->fd);
		i++;
	}
	i = 0;
	while (map->get_line)
	{
		j = 0;
		while (map->get_line[j])
		{
			// Search for first block of wall to start border checking
			if (map->get_line[j] == '1' && map->border_checked == 0)
			{
				map->border_begin_x = i;
				map->border_begin_x = j;
				check_border_map(map, border_map, i, j);
				if (map->border_checked == 0)
					perror_close("Map Border Integrity Fail", map);
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
