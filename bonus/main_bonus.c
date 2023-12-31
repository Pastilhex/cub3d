/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 09:33:20 by ialves-m          #+#    #+#             */
/*   Updated: 2023/10/23 19:08:20 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int	main(int ac, char **av)
{
	t_mlx	m;
	t_data	data;
	t_map	map;

	check_input(ac, av[1], &map);
	init_t_map(&map, &data);
	init_data(&data, &map, &m);
	init_bonus(&map, &data);
	init_mlx(&m);
	m.data_ptr = &data;
	read_cub_file(&map);
	open_window(&m, SCREENWIDTH, SCREENHEIGHT, "Cube3d Bonus");
	init_textures_img(&data);
	mlx_hook(m.mlx_win, 2, 1L << 0, &handle_keypress, &m);
	mlx_hook(m.mlx_win, 3, 1L << 1, &handle_keyrelease, &m);
	mlx_hook(m.mlx_win, 17, 0, close_window, &data);
	mlx_mouse_hook(m.mlx_win, &handle_mouse_fire, &data);
	mlx_hook(m.mlx_win, 06, 1L << 6, &handle_mouse, &data);
	mlx_loop_hook(m.mlx, render_frames, &data);
	mlx_loop(m.mlx);
	return (0);
}
