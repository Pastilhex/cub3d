/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:23:39 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/06 09:46:38 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static char		*get_back_line(char *line)
{
	int		i;
	int		j;
	int		size;
	char	*str;

	size = ft_strlen(line);
	i = 0;
	j = 0;
	while (i < size && !ft_isdigit(line[i]))
		i++;
	if (line[i + 1] == '\n' || line[i + 1] == '\0')
		return (NULL);
	str = malloc((ft_strlen(line) - i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (line[i])
		str[j++] = line[i++];
	str[j] = '\0';
	return (str);
}

static char		*get_texture(char *line)
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

/*
static bool		find_texture(char *line, char *texture)
{
	int		size;
	char	*texture_found;

	size = ft_strlen(line);
	texture_found = ft_strnstr(line, texture, size);
	if (texture_found)
		return (true);
	return (false);
}*/
/*
void	get_elements(t_map *map)
{
	while (map->get_line)
	{
		if (!map->north_texture)
			if (find_texture(map->get_line, "N ") || find_texture(map->get_line, "NO "))
				map->north_texture = get_texture(map->get_line);
		if (!map->south_texture)
			if (find_texture(map->get_line, "S ") || find_texture(map->get_line, "SO "))
				map->south_texture = get_texture(map->get_line);
		if (!map->west_texture)
			if (find_texture(map->get_line, "W ") || find_texture(map->get_line, "WE "))
				map->west_texture = get_texture(map->get_line);
		if (!map->east_texture)
			if (find_texture(map->get_line, "E ") || find_texture(map->get_line, "EA "))
				map->east_texture = get_texture(map->get_line);
		if (!map->ceiling_texture)
			if (find_texture(map->get_line, "C"))
				map->ceiling_texture = get_back_line(map->get_line);
		if (!map->floor_texture)
			if (find_texture(map->get_line, "F"))
				map->floor_texture = get_back_line(map->get_line);
		if (map->north_texture && map->south_texture && map->west_texture && map->east_texture && map->ceiling_texture && map->floor_texture)
			break ;
		map->get_line = get_next_line(map->fd);
	}
}*/

void	get_elements(t_map *map)
{
	char	**line_arr;
	
	while (map->get_line)
	{
		line_arr = ft_split(map->get_line, ' ');
		if (!map->north_texture)
			if (!ft_strncmp("N", line_arr[0], 2) || !ft_strncmp("NO", line_arr[0], 3))
				map->north_texture = get_texture(map->get_line);
		if (!map->south_texture)
			if (!ft_strncmp("S", line_arr[0], 2) || !ft_strncmp("SO", line_arr[0], 3))
				map->south_texture = get_texture(map->get_line);
		if (!map->west_texture)
			if (!ft_strncmp("W", line_arr[0], 2) || !ft_strncmp("WE", line_arr[0], 3))
				map->west_texture = get_texture(map->get_line);
		if (!map->east_texture)
			if (!ft_strncmp("E", line_arr[0], 2) || !ft_strncmp("EA", line_arr[0], 3))
				map->east_texture = get_texture(map->get_line);
		if (!map->ceiling_texture)
			if (!ft_strncmp("C", line_arr[0], 2))
				map->ceiling_texture = get_back_line(map->get_line);
		if (!map->floor_texture)
			if (!ft_strncmp("F", line_arr[0], 2))
				map->floor_texture = get_back_line(map->get_line);
		free_arr1(line_arr);
		if (map->north_texture && map->south_texture && map->west_texture && map->east_texture && map->ceiling_texture && map->floor_texture)
			break ;
		free(map->get_line);
		map->get_line = get_next_line(map->fd);
	}
}
