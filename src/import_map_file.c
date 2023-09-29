/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_map_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:53:33 by ialves-m          #+#    #+#             */
/*   Updated: 2023/09/29 13:08:005 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	access_file(t_map *map)
{
	map->fd = 0;
	map->fd = open(map->map_path, O_RDONLY);
	if (map->fd < 0)
		exit(0);
	return (map->fd);
}

int	get_ttl_nbr_lines(t_map *map)
{
	map->ttl_nbr_lines = 0;
	map->fd = access_file(map);
	map->get_line = get_next_line(map->fd);
	while (map->get_line)
	{
		map->get_line = get_next_line(map->fd);
		map->ttl_nbr_lines++;
	}
	return (map->ttl_nbr_lines);
}

bool	check_map_extension(t_map *map, char *filename)
{
	int i;

	i = 3;
	map->extension = ".cub";
	while (i >= 0)
	{
		if (filename[ft_strlen(filename) - i - 1] != map->extension[3 - i])
			return (false);
		i--;
	}
	return (true);
}
bool	find_texture(char *line, char *texture)
{
	int 	i;
	int		size;
	char	*texture_found;

	i = 0;
	size = ft_strlen(line);
	texture_found = ft_strnstr(line, texture, size);
	if (texture_found)
		return (true);
	return (false);
}

char	*get_texture(t_map *map, char *line)
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
	str = malloc((ft_strlen(line) - i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (line[i])
		str[j++] = line[i++];
	str[j] = '\0';
	return (str);
}
void	get_elements(t_map *map)
{
	while (map->get_line)
	{
		if (!map->north_texture)
			if (find_texture(map->get_line, "N") || find_texture(map->get_line, "NO"))
				map->north_texture = get_texture(map, map->get_line);
		if (!map->south_texture)
			if (find_texture(map->get_line, "S") || find_texture(map->get_line, "SO"))
				map->south_texture = get_texture(map, map->get_line);
		if (!map->west_texture)
			if (find_texture(map->get_line, "W") || find_texture(map->get_line, "WE"))
				map->west_texture = get_texture(map, map->get_line);
		if (!map->east_texture)
			if (find_texture(map->get_line, "E") || find_texture(map->get_line, "EA"))
				map->east_texture = get_texture(map, map->get_line);
		if (!map->ceiling_texture)
			if (find_texture(map->get_line, "C"))
				map->ceiling_texture = get_texture(map, map->get_line);
		if (!map->floor_texture)
			if (find_texture(map->get_line, "F"))
				map->floor_texture = get_texture(map, map->get_line);
		if (map->north_texture && map->south_texture && map->west_texture && map->east_texture && map->ceiling_texture && map->floor_texture)
			break ;
		map->get_line = get_next_line(map->fd);
	}
}

void	get_map_size(t_map *map)
{
	map->map_length = 0;
	map->map_width = 0;
	map->get_line = get_next_line(map->fd);
	while (map->get_line)
	{
		map->map_length++;
		if (ft_strlen(map->get_line) > map->map_width)
			map->map_width = ft_strlen(map->get_line);
		map->get_line = get_next_line(map->fd);
	}
	map->worldMap = (char**)ft_calloc(map->map_length, sizeof(char *));
	if (!map->worldMap)
		return ;
	close(map->fd);
}

void	get_map_to_array(t_map *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
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
		while (map->get_line[j])
		{
			if (map->get_line[j] == ' ' && map->get_line[j + 1] == ' ')
			{
				map->worldMap[i][j] = ' ';
				j += 2;
			}
			else
			{
				map->worldMap[i][j] = map->get_line[j];
				j++;
			}
		}
		i++;
		map->get_line = get_next_line(map->fd);
	}
	close(map->fd);
}

void	read_map_from_file(t_map *map)
{
	map->fd = access_file(map);
	map->get_line = get_next_line(map->fd);
	get_elements(map);
	get_map_size(map);
	get_map_to_array(map);
}
