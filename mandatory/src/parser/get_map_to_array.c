/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_to_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:23:47 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/27 17:12:24 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	set_start_ns(char c, t_data *d)
{
	if (c == 'N')
	{
		d->dir_x = -1;
		d->dir_y = 0;
		d->plane_x = 0;
		d->plane_y = 0.66;
	}
	if (c == 'S')
	{
		d->dir_x = 1;
		d->dir_y = 0;
		d->plane_x = 0;
		d->plane_y = -0.66;
	}
}

void	set_start(double i, double k, char c, t_map *m)
{
	t_data	*d;

	d = m->data_ptr;
	d->pos_x = i + 0.49;
	d->pos_y = k + 0.49;
	set_start_ns(c, d);
	if (c == 'W')
	{
		d->dir_x = 0;
		d->dir_y = -1;
		d->plane_x = -0.66;
		d->plane_y = 0;
	}
	if (c == 'E')
	{
		d->dir_x = 0;
		d->dir_y = 1;
		d->plane_x = 0.66;
		d->plane_y = 0;
	}
}

bool	is_valid_char(char c)
{
	if (c == '0' || c == '1' || is_direction(c) || c == '\n' || c == ' ')
		return (true);
	return (false);
}

void	get_map_to_array_while_get_line(t_map *map, int i, int j)
{
	while (map->get_line[j])
	{
		if (!is_valid_char(map->get_line[j]))
		{
			printf("Invalid char >> %c\n", map->get_line[j]);
			perror_close("Invalid char in map", map);
		}
		if (is_direction(map->get_line[j]))
		{
			if (map->has_player == 1)
				perror_close("More than one player", map);
			map->world_map[i][j] = '0';
			set_start(i, j, map->get_line[j], map);
			map->has_player = 1;
		}
		else
		{
			map->world_map[i][j] = map->get_line[j];
		}
		j++;
	}
	map->world_map[i][j] = '\0';
}

void	get_map_to_array(t_map *map)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	map->fd = access_file(map);
	map->get_line = get_next_line(map->fd);
	while (++i < map->m_start)
	{
		free(map->get_line);
		map->get_line = get_next_line(map->fd);
	}
	i = -1;
	while (map->get_line && ++i < map->m_end - map->m_start)
	{
		map->world_map[i] = ft_calloc((ft_strlen(map->get_line)
					+ 1), sizeof(char));
		j = 0;
		get_map_to_array_while_get_line(map, i, j);
		free(map->get_line);
		map->get_line = get_next_line(map->fd);
	}
	close(map->fd);
	if (map->has_player == 0)
		perror_close("No player found", map);
}
