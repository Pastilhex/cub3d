/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cub_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:53:33 by ialves-m          #+#    #+#             */
/*   Updated: 2023/10/10 21:41:22 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	fill_t_rgb(t_rgb *c, char *r, char *g, char *b)
{
	c->r = atoi(r);
	c->g = atoi(g);
	c->b = atoi(b);
}

static void	define_rgb_colors(t_map *m, char **array, char *str)
{
	char	**rgb;

	rgb = ft_split(array[1], ',');
	if (ft_strncmp(str, "C", 1) == 0)
	{
		fill_t_rgb(&m->ceiling_colors, rgb[0], rgb[1], rgb[2]);
		if (!is_valid_colors(&m->ceiling_colors)
			|| !is_only_digit_or_comma(array[1]))
		{
			free_arr1(rgb);
			perror_close("Invalid Ceil Color", m);
		}
	}
	else if (ft_strncmp(str, "F", 1) == 0)
	{
		fill_t_rgb(&m->floor_colors, rgb[0], rgb[1], rgb[2]);
		if (!is_valid_colors(&m->ceiling_colors)
			|| !is_only_digit_or_comma(array[1]))
		{
			free_arr1(rgb);
			perror_close("Invalid Floor Color", m);
		}
	}
	free_arr1(rgb);
}

void	check_elements(t_map *m, char *texture, char *c)
{
	int		i;
	char	**array;

	i = -1;
	m->nbr = 0;
	m->comma = 0;
	m->rest = 0;
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
		perror_close("Invalid Char in Color Definition", m);
	}
	define_rgb_colors(m, array, c);
	free_arr1(array);
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
	check_map_integrity(map);
	free(map->get_line);
}
