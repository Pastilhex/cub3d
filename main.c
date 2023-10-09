/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 09:33:20 by ialves-m          #+#    #+#             */
/*   Updated: 2023/10/09 17:00:34 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	perror_close(char *msg, t_map *map)
{
	printf("Error\n%s\n", msg);
	close_window(map->data_ptr);
}

int	main(int ac, char **av)
{
	t_mlx	m;
	t_data	data;
	t_map	map;

	check_input(ac, av[1], &map);
	init_t_map(&map, &data);
	init_data(&data, &map, &m);
	init_mlx(&m);
	m.data_ptr = &data;
	read_cub_file(&map);
	open_window(&m, SCREENWIDTH, SCREENHEIGHT, "Cube3d IvoJao");
	init_textures_img(&data);
	mlx_hook(m.mlx_win, 2, 1L << 0, &handle_keypress, &m);
	mlx_hook(m.mlx_win, 3, 1L << 1, &handle_keyrelease, &m);
	mlx_hook(m.mlx_win, 17, 0, close_window, &data);
	mlx_loop_hook(m.mlx, render_frames, &data);
	mlx_loop(m.mlx);
	return (0);
}
