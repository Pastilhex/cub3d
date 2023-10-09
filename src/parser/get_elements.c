/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:23:39 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/09 18:55:46 by joaoalme         ###   ########.fr       */
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
	while (i < size - 1 && (line[i] != '.' && line[i + 1] != '/'))
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

void	get_elements_sides(t_map *map, char **line_arr)
{
	if (!map->north_texture)
		if (!ft_strncmp("N", line_arr[0], 2)
			|| !ft_strncmp("NO", line_arr[0], 3))
			map->north_texture = get_texture(map->get_line);
	if (!map->south_texture)
		if (!ft_strncmp("S", line_arr[0], 2)
			|| !ft_strncmp("SO", line_arr[0], 3))
			map->south_texture = get_texture(map->get_line);
	if (!map->west_texture)
		if (!ft_strncmp("W", line_arr[0], 2)
			|| !ft_strncmp("WE", line_arr[0], 3))
			map->west_texture = get_texture(map->get_line);
	if (!map->east_texture)
		if (!ft_strncmp("E", line_arr[0], 2)
			|| !ft_strncmp("EA", line_arr[0], 3))
			map->east_texture = get_texture(map->get_line);
}

void	get_elements(t_map *map)
{
	char	**line_arr;

	while (map->get_line)
	{
		map->line_nbr++;
		line_arr = ft_split(map->get_line, ' ');
		if (get_arr_size(line_arr) > 2)
			perror_close("Map Error Found", map);
		get_elements_sides(map, line_arr);
		if (!map->ceiling_texture)
			if (!ft_strncmp("C", line_arr[0], 2))
				map->ceiling_texture = ft_strdup(map->get_line);
		if (!map->floor_texture)
			if (!ft_strncmp("F", line_arr[0], 2))
				map->floor_texture = ft_strdup(map->get_line);
		free_arr1(line_arr);
		if (map->north_texture && map->south_texture && map->west_texture
			&& map->east_texture && map->ceiling_texture && map->floor_texture)
			break ;
		free(map->get_line);
		map->get_line = get_next_line(map->fd);
	}
	if (!map->north_texture || !map->south_texture || !map->west_texture
		|| !map->east_texture || !map->ceiling_texture || !map->floor_texture)
		perror_close("Map Error Found", map);
}
