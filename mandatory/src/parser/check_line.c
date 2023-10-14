/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:49:45 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/11 19:59:22 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_coordinate(char *line)
{
	if (ft_strcmp("N", line) == 0 || ft_strcmp("NO", line) == 0
		|| ft_strcmp("S", line) == 0 || ft_strcmp("SO", line) == 0
		|| ft_strcmp("W", line) == 0 || ft_strcmp("WE", line) == 0
		|| ft_strcmp("E", line) == 0 || ft_strcmp("EA", line) == 0
		|| ft_strcmp("F", line) == 0 || ft_strcmp("C", line) == 0)
		return (1);
	return (0);
}

void	check_line_for_digit(char *line, char **arr, t_map *m)
{
	if (is_coordinate(line) == 0)
	{
		free_arr1(arr);
		perror_close("Check map elements", m);
	}
}
