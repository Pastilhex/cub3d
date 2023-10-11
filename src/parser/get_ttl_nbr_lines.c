/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ttl_nbr_lines.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:23:54 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/11 16:11:49 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_ttl_nbr_lines(t_map *map)
{
	int		fd;
	char	*line;

	fd = open(map->map_path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		map->ttl_nbr_lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

// char	**get_inverted_map(t_map *map)
// {
// 	int		i;
// 	int		fd;
// 	char	*line;
// 	char	**array_tmp;

// 	i = map->ttl_nbr_lines - 1;
// 	array_tmp = ft_calloc(map->ttl_nbr_lines, sizeof(char *));
// 	fd = open(map->map_path, O_RDONLY);
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		array_tmp[i] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
// 		ft_strlcpy(array_tmp[i], line, ft_strlen(line));
// 		free(line);
// 		line = get_next_line(fd);
// 		i--;
// 	}
// 	close(fd);
// 	return (array_tmp);
// }

// void	check_map_at_end(t_map *map)
// {
// 	int		i;
// 	int		j;
// 	char	**array_tmp;

// 	i = 0;
// 	j = 0;
// 	array_tmp = get_inverted_map(map);
// 	while (ft_strncmp(array_tmp[i], "\n", 1))
// 		i++;
// 	while (i < map->ttl_nbr_lines && !ft_strncmp(array_tmp[i], "\n", 1))
// 	{
// 		while (j < ft_strlen(array_tmp[i]))
// 		{
// 			if (!ft_isdigit(array_tmp[i][j]))
// 				perror_close("Map not Valid", map);
// 			j++;
// 		}
// 	}
// }
