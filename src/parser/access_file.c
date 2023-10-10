/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:23:18 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/10 11:26:53 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	access_file(t_map *map)
{
	map->fd = open(map->map_path, O_RDONLY);
	if (map->fd < 0)
		exit(0);
	return (map->fd);
}

void	access_path(t_map *map, char *texture, char **line_arr)
{
	int	fd;

	fd = open(texture, O_RDONLY);
	if (fd < 0)
	{
		free_arr1(line_arr);
		perror_close("Wrong Texture Path", map);
	}
	close (fd);
}

void	perror_close(char *msg, t_map *map)
{
	printf("Error\n%s\n", msg);
	close_window(map->data_ptr);
}
