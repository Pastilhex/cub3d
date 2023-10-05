/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_to_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:23:47 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/04 22:42:33 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	is_direction(char c)
{
	if (c == 'N' || c == 'S' ||c == 'W' ||c == 'E')
		return (true);
	return (false);
}
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


void	get_map_to_array(t_map *map)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	map->fd = access_file(map);
	map->get_line = get_next_line(map->fd);
	while (i < (map->ttl_nbr_lines - map->map_length))
	{
		map->get_line = get_next_line(map->fd);
		i++;
	}
	i = 0;
	while (map->get_line)
	{
		map->worldMap[i] = ft_calloc(ft_strlen(map->get_line + 1), sizeof(char));
		j = 0;
		k = 0;
		while (map->get_line[j])
		{
			if (map->get_line[j] == ',')
				j++;
			else if (map->get_line[j] == ' ')
			{
				map->worldMap[i][k] = map->get_line[j];
				j += 2;
				k++;
			}
			else
			{
				if (is_direction(map->get_line[j]))
				{
					map->worldMap[i][k] = '0';
					set_start(i, k, map->get_line[j], map);
					j++;
					k++;
				}
				else
				{
					map->worldMap[i][k] = map->get_line[j];
					j++;
					k++;
				}
			}
		}
		i++;
		map->get_line = get_next_line(map->fd);
	}
	close(map->fd);
}

/*
	start position direction - 
	west
	data.dirX = 0;
	data.dirY = 1; 
	data.planeX = 0.66;
	data.planeY = 0; 
	
	east 
	data.dirX = 0;
	data.dirY = -1; 
	data.planeX = -0.66;
	data.planeY = 0;
	
	north
	data.dirX = -1;
	data.dirY = 0;
	data.planeX = 0;
	data.planeY = 0.66;
	
	South 
	data.dirX = 1;
	data.dirY = 0; 
	data.planeX = 0; 
	data.planeY = -0.66;
	
	
	
	
*/