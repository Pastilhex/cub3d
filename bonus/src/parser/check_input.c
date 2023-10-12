/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:37:24 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/11 18:15:39 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_input(int ac, char *path_str, t_map *m)
{
	int		temp_fd;

	if (ac != 2)
	{
		printf("Error!\nUsage: ./cube3d <map_path>\n");
		exit(EXIT_FAILURE);
	}
	m->map_path = path_str;
	if (!check_map_extension(m, path_str))
	{
		printf("Error!\nCan not open file\n");
		exit(EXIT_FAILURE);
	}
	temp_fd = open(m->map_path, O_RDONLY);
	if (temp_fd == -1)
	{
		printf("Error!\nCan not open file 2\n");
		exit(EXIT_FAILURE);
	}
	close(temp_fd);
	return (1);
}
