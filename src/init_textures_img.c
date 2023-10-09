/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures_img.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:21:33 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/09 16:46:09 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_textures_img(t_data *d)
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
