/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_extension.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:23:26 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/12 16:45:37 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	check_map_extension(t_map *map, char *filename)
{
	int		i;
	char	*s;

	i = 3;
	if (ft_strlen(filename) < 5)
		return (false);
	s = ft_strrchr(filename, '/');
	if (s != NULL)
	{
		s++;
		if (ft_strlen(s) < 5)
			return (false);
	}
	map->extension = ".cub";
	while (i >= 0)
	{
		if (filename[ft_strlen(filename) - i - 1] != map->extension[3 - i])
			return (false);
		i--;
	}
	return (true);
}
