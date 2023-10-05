/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 09:33:20 by ialves-m          #+#    #+#             */
/*   Updated: 2023/10/05 13:18:27 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"


void 	init_textures_img(t_data *d)
{
	d->txt_ptr[north].img = mlx_xpm_file_to_image(d->m_ptr->mlx,
		d->map_ptr->north_texture, &d->txt_ptr[north].txt_w,
		&d->txt_ptr[north].txt_h);
	d->txt_ptr[north].addr = mlx_get_data_addr(d->txt_ptr[north].img,
		&d->txt_ptr[north].bits_per_pixel, &d->txt_ptr[north].line_length,
		&d->txt_ptr[north].endian);
	d->txt_ptr[south].img = mlx_xpm_file_to_image(d->m_ptr->mlx,
		d->map_ptr->south_texture, &d->txt_ptr[south].txt_w,
		&d->txt_ptr[south].txt_h);
	d->txt_ptr[south].addr = mlx_get_data_addr(d->txt_ptr[south].img,
		&d->txt_ptr[south].bits_per_pixel, &d->txt_ptr[south].line_length,
		&d->txt_ptr[south].endian);
	d->txt_ptr[west].img = mlx_xpm_file_to_image(d->m_ptr->mlx,
		d->map_ptr->west_texture, &d->txt_ptr[west].txt_w,
		&d->txt_ptr[west].txt_h);
	d->txt_ptr[west].addr = mlx_get_data_addr(d->txt_ptr[west].img,
		&d->txt_ptr[west].bits_per_pixel, &d->txt_ptr[west].line_length,
		&d->txt_ptr[west].endian);
	d->txt_ptr[east].img = mlx_xpm_file_to_image(d->m_ptr->mlx,
		d->map_ptr->east_texture, &d->txt_ptr[east].txt_w, 
		&d->txt_ptr[east].txt_h);
	d->txt_ptr[east].addr = mlx_get_data_addr(d->txt_ptr[east].img,
		&d->txt_ptr[east].bits_per_pixel, &d->txt_ptr[east].line_length,
		&d->txt_ptr[east].endian);
}
void 	ft_print_array(char **arr, int nb_lines);

int main()
{
	t_mlx m;
	t_data data;
	t_map map;

	init_t_map(&map, &data);
	init_data(&data, &map, &m);
	map.data_ptr = &data;
	m.data_ptr = &data;

	char *path = "./maps/test.cub"; //av[2]
	map.map_path = path;
	read_map_from_file(&map);
	open_window(&m, screenWidth, screenHeight, "Cube3d IvoJao");
	init_textures_img(&data);

	mlx_hook(m.mlx_win, 2, 1L << 0, &handle_keypress, &m);
	mlx_hook(m.mlx_win, 3, 1L << 1, &handle_keyrelease, &m);
	mlx_hook(m.mlx_win, 17, 0, close_window, &m);
	mlx_loop_hook(m.mlx, render_frames, &data);
	mlx_loop(m.mlx);	
}
void 	ft_print_array(char **arr, int nb_lines)
{
	for (int i = 0; i < nb_lines; i++)
		printf("%s", arr[i]);
}
