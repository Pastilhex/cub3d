/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_to_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:23:47 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/27 17:21:45 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	is_valid_char(char c)
{
	if (c == '0' || ft_isdigit(c) || is_direction(c)
		|| allowed_sprites(c) || c == '\n' || c == ' ')
		return (true);
	return (false);
}

bool	is_sprite(char c)
{
	if (c == '6' || allowed_sprites(c))
		return (true);
	return (false);
}

void	set_sprite_arr(t_map *m, int i, int j, char c)
{
	t_sprite	*sprite;

	sprite = m->sprite_arr;
	sprite[m->sprite_index].x = i;
	sprite[m->sprite_index].y = j;
	set_sprite_extra(m, i, j, c);
	m->sprite_index++;
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
		else if (is_sprite(map->get_line[j]))
			set_sprite_arr(map, i, j, map->get_line[j]);
		else
			map->world_map[i][j] = map->get_line[j];
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
