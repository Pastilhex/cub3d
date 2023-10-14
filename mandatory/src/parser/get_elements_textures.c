/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elements_textures.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:23:39 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/10 22:01:31 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_texture(t_map *map, char **texture, char **s, char **line_arr)
{
	if (!*texture)
	{
		if (!ft_strncmp(s[0], line_arr[0], 2)
			|| !ft_strncmp(s[1], line_arr[0], 3))
			*texture = get_texture(line_arr[1]);
	}
	else if (*texture
		&& (!ft_strncmp(s[0], line_arr[0], 2)
			|| !ft_strncmp(s[1], line_arr[0], 3)))
	{
		free_arr1(line_arr);
		perror_close("Repeated Texture", map);
	}
}

void	get_elements_textures(t_map *map, char **line_arr)
{
	char	*n[2];
	char	*s[2];
	char	*w[2];
	char	*e[2];

	n[0] = "N";
	n[1] = "NO";
	s[0] = "S";
	s[1] = "SO";
	w[0] = "W";
	w[1] = "WE";
	e[0] = "E";
	e[1] = "EA";
	check_texture(map, &map->north_texture, n, line_arr);
	check_texture(map, &map->south_texture, s, line_arr);
	check_texture(map, &map->west_texture, w, line_arr);
	check_texture(map, &map->east_texture, e, line_arr);
}
