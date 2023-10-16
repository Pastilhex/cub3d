/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 09:33:20 by ialves-m          #+#    #+#             */
/*   Updated: 2023/10/16 23:04:50 by joaoalme         ###   ########.fr       */
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
	ft_print_array(map.world_map, map.map_end - map.map_start);
	mlx_hook(m.mlx_win, 2, 1L << 0, &handle_keypress, &m);
	mlx_hook(m.mlx_win, 3, 1L << 1, &handle_keyrelease, &m);
	mlx_hook(m.mlx_win, 17, 0, close_window, &data);
	mlx_loop_hook(m.mlx, render_frames, &data);
	mlx_loop(m.mlx);
	return (0);
}
