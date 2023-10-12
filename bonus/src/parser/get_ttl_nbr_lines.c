/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ttl_nbr_lines.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:23:54 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/11 18:18:38 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_ttl_nbr_lines(t_map *map)
{
	int		fd;
	int		has_content;
	char	*line;

	fd = 0;
	fd = open(map->map_path, O_RDONLY);
	has_content = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strlen(line) > 1)
			has_content = 1;
		map->ttl_nbr_lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (has_content == 0)
		perror_close("Empty file", map);
}
