/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 09:33:20 by ialves-m          #+#    #+#             */
/*   Updated: 2023/10/06 09:40:01 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	free_t_map(t_map *m)
{
	free(m->north_texture);
	free(m->south_texture);
	free(m->east_texture);
	free(m->west_texture);
	free(m->ceiling_texture);
	free(m->floor_texture);
	free(m->get_line);
	free_arr(m->worldMap, m);
}
void	cleaning(t_data *d, t_map* m)
{
	free(d->txt_ptr);
	free_t_map(m);
}

void 	ft_print_array(char **arr, int nb_lines);

int main()
{
	t_mlx m;
	t_data data;
	t_map map;

	init_t_map(&map, &data);
	init_data(&data, &map, &m);
	m.data_ptr = &data;

	char *path = "./maps/test.cub"; //av[2]
	map.map_path = path;
	read_cub_file(&map);
	open_window(&m, screenWidth, screenHeight, "Cube3d IvoJao");
	init_textures_img(&data);

	mlx_hook(m.mlx_win, 2, 1L << 0, &handle_keypress, &m);
	mlx_hook(m.mlx_win, 3, 1L << 1, &handle_keyrelease, &m);
	mlx_hook(m.mlx_win, 17, 0, close_window, &data);
	mlx_loop_hook(m.mlx, render_frames, &data);
	mlx_loop(m.mlx);
	return(0);
}
void 	ft_print_array(char **arr, int nb_lines)
{
	for (int i = 0; i < nb_lines; i++)
		printf("%s", arr[i]);
}
