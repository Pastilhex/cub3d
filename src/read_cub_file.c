/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cub_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:53:33 by ialves-m          #+#    #+#             */
/*   Updated: 2023/10/06 21:15:38 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	define_rgb_colors(t_map *m, char **array, char *c)
{
	char	**rgb;

	rgb = ft_split(array[1], ',');
	if (ft_strncmp(c, "C", 1) == 0)
	{
		m->ceiling_colors.r = ft_atoi(rgb[0]);
		m->ceiling_colors.g = ft_atoi(rgb[1]);
		m->ceiling_colors.b = ft_atoi(rgb[2]);
	}
	else if (ft_strncmp(c, "F", 1) == 0)
	{
		m->floor_colors.r = ft_atoi(rgb[0]);
		m->floor_colors.g = ft_atoi(rgb[1]);
		m->floor_colors.b = ft_atoi(rgb[2]);
	}
}

void	check_elements(t_map *m, char *texture, char *c)
{
	int		i;
	char	**array;

	i = -1;
	m->nbr = 0;
	m->comma = 0;
	m->rest = 0;
	// array = NULL;
	array = ft_split(texture, ' ');
	while (array[1][++i] && array[1][i] != '\n')
	{
		if (ft_isdigit(array[1][i]))
			m->nbr++;
		else if (array[1][i] == ',')
			m->comma++;
		else
			m->rest++;
	}
	if (ft_strncmp(array[0], c, 1) != 0
		|| ((m->nbr < 0 || m->nbr > 9) && (m->comma != 2) && m->rest != 0))
	{
		free_arr1(array);
		close_window(m->data_ptr);
	}
	define_rgb_colors(m, array, c);
}

void	read_cub_file(t_map *map)
{
	get_ttl_nbr_lines(map);
	map->fd = open(map->map_path, O_RDONLY);
	map->get_line = get_next_line(map->fd);
	get_elements(map);
	check_elements(map, map->ceiling_texture, "C");
	check_elements(map, map->floor_texture, "F");
	get_map_size(map);
	get_map_to_array(map);
	free(map->get_line);
}
