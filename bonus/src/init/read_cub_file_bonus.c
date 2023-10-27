/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cub_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:53:33 by ialves-m          #+#    #+#             */
/*   Updated: 2023/10/27 10:09:15 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	close_free(char *msg, char **arr, t_map *m)
{
	free_arr1(arr);
	perror_close(msg, m);
}

static void	fill_t_rgb(t_rgb *c, char *r, char *g, char *b)
{
	c->r = ft_atoi(r);
	c->g = ft_atoi(g);
	c->b = ft_atoi(b);
}

static void	define_rgb_colors(t_map *m, char **rgb, char *str)
{
	if (ft_strncmp(str, "C", 1) == 0)
	{
		fill_t_rgb(&m->ceiling_colors, rgb[1], rgb[2], rgb[3]);
		if (!is_valid_colors(&m->ceiling_colors))
			close_free("Invalid Ceil Color", rgb, m);
	}
	else if (ft_strncmp(str, "F", 1) == 0)
	{
		fill_t_rgb(&m->floor_colors, rgb[1], rgb[2], rgb[3]);
		if (!is_valid_colors(&m->floor_colors))
			close_free("Invalid Floor Color", rgb, m);
	}
}

void	check_elements(t_map *m, char *texture, char *c)
{
	int		i;
	int		j;
	char	**array;

	i = 1;
	j = 0;
	array = ft_split_set(texture, ", \n\t");
	if (get_arr_size(array) != 4)
		close_free("Invalid color", array, m);
	while (array[i])
	{
		j = 0;
		while (array[i][j] && array[i][j] != '\n')
			if (!ft_isdigit(array[i][j++]))
				close_free("Invalid Char in Color Definition", array, m);
		i++;
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
	map->sprite_arr = ft_calloc(map->sprites_nb, (sizeof(t_sprite)));
	map->sprite_order = ft_calloc(map->sprites_nb, (sizeof(t_sprite)));
	map->sprite_distance = ft_calloc(map->sprites_nb, (sizeof(t_sprite)));
	get_map_to_array(map);
	check_map_integrity(map);
}
