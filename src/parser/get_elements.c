/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:23:39 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/11 23:49:00 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*get_texture(char *line)
{
	int		i;
	int		j;
	int		size;
	char	*str;

	size = ft_strlen(line);
	i = 0;
	j = 0;
	while (i < size - 1 && line[i] == ' ')
		i++;
	if (line[i + 1] == '\n' || line[i + 1] == '\0')
		return (NULL);
	str = malloc((ft_strlen(line) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (line[i] && line[i] != '\n')
		str[j++] = line[i++];
	str[j] = '\0';
	return (str);
}

static void	get_elements_side_textures(t_map *map, char **line_arr)
{
	if (is_direction(line_arr[0][0] && get_arr_size(line_arr) > 2))
	{
		free_arr1(line_arr);
		perror_close("Check Map Elements", map);
	}
	get_elements_textures(map, line_arr);
}

static void	get_elements_colors_textures(t_map *map, char **line_arr)
{
	if (!map->ceiling_texture)
		if (!ft_strncmp("C", line_arr[0], 2))
			map->ceiling_texture = ft_strdup(map->get_line);
	if (!map->floor_texture)
		if (!ft_strncmp("F", line_arr[0], 2))
			map->floor_texture = ft_strdup(map->get_line);
}

static void	check_textures_paths(t_map *map)
{
	access_path(map, map->north_texture);
	access_path(map, map->south_texture);
	access_path(map, map->west_texture);
	access_path(map, map->east_texture);
}

void	get_elements(t_map *map)
{
	char	**line_arr;

	while (map->get_line)
	{
		map->line_nbr++;
		line_arr = ft_split_set(map->get_line, " \t");
		if (ft_strncmp("\n", line_arr[0], 1) != 0)
		{
			check_line_for_digit(line_arr[0], line_arr, map);
			get_elements_side_textures(map, line_arr);
			get_elements_colors_textures(map, line_arr);
			if (map->north_texture && map->south_texture && map->west_texture
				&& map->east_texture && map->ceiling_texture
				&& map->floor_texture)
			{
				free_arr1(line_arr);
				break ;
			}
		}
		free_total(line_arr, map->get_line);
		map->get_line = get_next_line(map->fd);
	}
	check_textures_paths(map);
	if (!map->ceiling_texture || !map->floor_texture)
		perror_close("Missing Color", map);
}
