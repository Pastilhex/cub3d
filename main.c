/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 09:33:20 by ialves-m          #+#    #+#             */
/*   Updated: 2023/09/27 11:02:59 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	open_window(t_mlx *m)
{
	m->mlx = mlx_init();
	m->mlx_win = mlx_new_window(m->mlx, screenWidth, screenHeight, "Cub3D");
	m->img = mlx_new_image(m->mlx, screenWidth, screenHeight);
	m->addr = mlx_get_data_addr(m->img, &m->bits_per_pixel, &m->line_length, &m->endian);
	mlx_destroy_image(m->mlx, m->img);
}

int main()
{
	t_mlx m;
	
	open_window(&m);
	mlx_hook(m.mlx_win, 2, 1L << 0, &handle_keypress, &m);
	mlx_hook(m.mlx_win, 17, 0, close_window, &m);
	mlx_loop(m.mlx);
}
