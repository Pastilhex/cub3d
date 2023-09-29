/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_extension.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:23:26 by joaoalme          #+#    #+#             */
/*   Updated: 2023/09/29 18:27:18 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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