/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_to_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:23:47 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/09 21:01:51 by joaoalme         ###   ########.fr       */
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
			map->world_map[i][j] = '0';
			set_start(i, j, map->get_line[j], map);
		}
		else
		{
			map->world_map[i][j] = map->get_line[j];
		}
		j++;
	}
	map->world_map[i][j] = '\0';
}
void 	ft_print_array(char **arr, int nb_lines)
{
	for (int i = 0; i < nb_lines; i++)
	{
		printf("%d - %s", ft_strlen(arr[i]), arr[i]);
	}
}

void	get_map_to_array(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	map->fd = access_file(map);
	map->get_line = get_next_line(map->fd);
	while (i < map->map_start)
	{
		free(map->get_line);
		map->get_line = get_next_line(map->fd);
		i++;
	}
	i = 0;
	while (map->get_line && i < map->map_end)
	{
		map->world_map[i] = malloc((ft_strlen(map->get_line) + 1)* sizeof(char));
		j = 0;
		get_map_to_array_while_get_line(map, i, j);
		free(map->get_line);
		i++;
		map->get_line = get_next_line(map->fd);
	}
	ft_print_array(map->world_map, map->map_end - map->map_start);
	close(map->fd);
}
