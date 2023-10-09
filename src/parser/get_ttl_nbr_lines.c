/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ttl_nbr_lines.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:23:54 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/09 15:23:15 by ialves-m         ###   ########.fr       */
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
