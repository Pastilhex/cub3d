/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elements_textures.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:23:39 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/10 21:14:222 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_texture(t_map *map, char **texture, char *s1, char *s2, char **line_arr)
{
	if (!*texture)
	{
		if (!ft_strncmp(s1, line_arr[0], 2)
			|| !ft_strncmp(s2, line_arr[0], 3))
			*texture = get_texture(line_arr[1]);
	}
	else if (*texture
		&& (!ft_strncmp(s1, line_arr[0], 2)
			|| !ft_strncmp(s2, line_arr[0], 3)))
	{
		free_arr1(line_arr);
		perror_close("Texture Repeated", map);
	}
}

void	get_elements_textures(t_map *map, char **line_arr)
{
	check_texture(map, &map->north_texture, "N", "NO", line_arr);
	check_texture(map, &map->north_texture, "S", "SO", line_arr);
	check_texture(map, &map->north_texture, "W", "WE", line_arr);
	check_texture(map, &map->north_texture, "E", "EA", line_arr);
}
