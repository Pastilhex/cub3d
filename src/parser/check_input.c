/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:37:24 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/06 10:40:00 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		check_input(int ac, char *path_str, t_map *m)
{
	if (ac != 2)
	{
		printf("Error!\nUsage: ./cube3d <map_path>\n");
		exit(EXIT_FAILURE);
	}
	m->map_path = path_str;
	if (open(path_str, O_RDONLY) == -1)
	{
		printf("Error!\nCan not open file\n");
		exit(EXIT_FAILURE);
	}
	return(1);
}