/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_extension.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:23:26 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/09 15:13:21 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	check_map_extension(t_map *map, char *filename)
{
	int	i;

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
