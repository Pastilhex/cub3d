/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:23:18 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/11 21:44:37 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	access_file(t_map *map)
{
	if (map->map_path)
		map->fd = open(map->map_path, O_RDONLY);
	if (map->fd < 0)
		exit(0);
	return (map->fd);
}

void	access_path(t_map *map, char *texture)
{
	int	fd;

	if (texture == 0)
		perror_close("Invalid map", map);
	fd = open(texture, O_RDONLY);
	if (fd < 0)
		perror_close("Wrong Texture Path", map);
	close (fd);
	if (ft_strnstr(texture, ".xpm", ft_strlen(texture)) == 0)
		perror_close("Texture not a .xpm file", map);
}

void	perror_close(char *msg, t_map *map)
{
	printf("Error\n%s\n", msg);
	close_window(map->data_ptr);
}

void	perror_close2(char *msg, t_map *map, int fd)
{
	close(fd);
	printf("Error\n%s\n", msg);
	close_window(map->data_ptr);
}
