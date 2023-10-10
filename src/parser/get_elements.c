/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:23:39 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/10 11:30:00 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static char	*get_texture(char *line)
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
	str = malloc((ft_strlen(line) - i) * sizeof(char));
	if (!str)
		return (NULL);
	while (line[i] && line[i] != '\n')
		str[j++] = line[i++];
	str[j] = '\0';
	return (str);
}

void	get_elements_side_textures(t_map *map, char **line_arr)
{
	if (!map->north_texture)
		if (!ft_strncmp("N", line_arr[0], 2)
			|| !ft_strncmp("NO", line_arr[0], 3))
			map->north_texture = get_texture(line_arr[1]);
	access_path(map, map->north_texture, line_arr);
	if (!map->south_texture)
		if (!ft_strncmp("S", line_arr[0], 2)
			|| !ft_strncmp("SO", line_arr[0], 3))
			map->south_texture = get_texture(line_arr[1]);
	access_path(map, map->south_texture, line_arr);
	if (!map->west_texture)
		if (!ft_strncmp("W", line_arr[0], 2)
			|| !ft_strncmp("WE", line_arr[0], 3))
			map->west_texture = get_texture(line_arr[1]);
	access_path(map, map->west_texture, line_arr);
	if (!map->east_texture)
		if (!ft_strncmp("E", line_arr[0], 2)
			|| !ft_strncmp("EA", line_arr[0], 3))
			map->east_texture = get_texture(line_arr[1]);
	access_path(map, map->east_texture, line_arr);
}

void	get_elements_colors_textures(t_map *map, char **line_arr)
{
	if (!map->ceiling_texture)
		if (!ft_strncmp("C", line_arr[0], 2))
			map->ceiling_texture = ft_strdup(map->get_line);
	if (!map->floor_texture)
		if (!ft_strncmp("F", line_arr[0], 2))
			map->floor_texture = ft_strdup(map->get_line);
}

void	get_elements(t_map *map)
{
	char	**line_arr;

	while (map->get_line)
	{
		map->line_nbr++;
		line_arr = ft_split(map->get_line, ' ');
		if (ft_strncmp("\n", line_arr[0], 1) != 0 && get_arr_size(line_arr) > 1)
		{
			if (get_arr_size(line_arr) > 2)
				perror_close("Check Map Elements", map);
			get_elements_side_textures(map, line_arr);
			get_elements_colors_textures(map, line_arr);
			if (map->north_texture && map->south_texture && map->west_texture
				&& map->east_texture && map->ceiling_texture
				&& map->floor_texture)
				break ;
		}
		free(map->get_line);
		free_arr1(line_arr);
		map->get_line = get_next_line(map->fd);
	}
	if (!map->north_texture || !map->south_texture || !map->west_texture
		|| !map->east_texture || !map->ceiling_texture || !map->floor_texture)
		perror_close("Map Error Found", map);
}
