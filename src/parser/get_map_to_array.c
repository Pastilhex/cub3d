/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_to_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:23:47 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/08 20:58:42 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


void 	set_start(double i, double k, char c, t_map *m)
{
	t_data * d = m->data_ptr;
	d->posX = i + 0.49;
	d->posY = k + 0.49;
	
	if (c == 'N')
	{
		d->dirX = -1;
		d->dirY = 0;
		d->planeX = 0;
		d->planeY = 0.66;
	}
	if (c == 'S')
	{
		d->dirX = 1;
		d->dirY = 0;
		d->planeX = 0;
		d->planeY = -0.66;
	}
	if (c == 'W')
	{
		d->dirX = 0;
		d->dirY = -1;
		d->planeX = -0.66;
		d->planeY = 0;
	}
	if (c == 'E')
	{
		d->dirX = 0;
		d->dirY = 1;
		d->planeX = 0.66;
		d->planeY = 0;
	}
}

bool	isValidChar(char c)
{
	if (c == '0' || c == '1' || is_direction(c) || c == '\n' || c == ' ')
		return(true);
	return (false);
}

void	get_map_to_array(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	map->fd = access_file(map);
	map->get_line = get_next_line(map->fd);
	while (i < (map->ttl_nbr_lines - map->map_length))
	{
		free(map->get_line);
		map->get_line = get_next_line(map->fd);
		i++;
	}
	i = 0;
	while (map->get_line)
	{
		map->worldMap[i] = ft_calloc((ft_strlen(map->get_line) + 1), sizeof(char));
		j = 0;
		while (map->get_line[j])
		{
			
			if (!isValidChar(map->get_line[j]))
			{
				printf("Invalid char >> %c\n", map->get_line[j]);
				perror_close("Invalid char in map", map);	
			}
			if (is_direction(map->get_line[j]))
			{
				map->worldMap[i][j] = '0';
				set_start(i, j, map->get_line[j], map);
				j++;
			}
			else
			{
				map->worldMap[i][j] = map->get_line[j];
				j++;
			}
		}
		free(map->get_line);
		i++;
		map->get_line = get_next_line(map->fd);
	}
	close(map->fd);
}
