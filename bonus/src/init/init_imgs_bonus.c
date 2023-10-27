/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:49:20 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/27 10:53:45 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	new_img(t_data *d, enum e_direction var, char *txt)
{
	d->txt_ptr[var].img = mlx_xpm_file_to_image(d->m_ptr->mlx, txt,
			&d->txt_ptr[var].txt_w, &d->txt_ptr[var].txt_h);
	d->txt_ptr[var].addr = mlx_get_data_addr(d->txt_ptr[var].img,
			&d->txt_ptr[var].bits_per_pixel, &d->txt_ptr[var].line_length,
			&d->txt_ptr[var].endian);
}

void	img_door(t_data *d)
{
	int	i;

	i = -1;
	d->txt_door = malloc(sizeof(t_texture) * 21);
	while (++i <= 20)
	{
		d->txt_door[i].img = mlx_xpm_file_to_image(d->m_ptr->mlx,
				d->map_ptr->animated_door[i],
				&d->txt_door[i].txt_w,
				&d->txt_door[i].txt_h);
		d->txt_door[i].addr = mlx_get_data_addr(d->txt_door[i].img,
				&d->txt_door[i].bits_per_pixel,
				&d->txt_door[i].line_length,
				&d->txt_door[i].endian);
	}
}

void	img_head(t_data *d)
{
	d->map_ptr->start_time_head = get_actual_time();
	d->swap_img = 0;
	d->txt_head = malloc(sizeof(t_texture) * 3);
	d->txt_head[0].img = mlx_xpm_file_to_image(d->m_ptr->mlx,
			d->map_ptr->animated_head[0], &d->txt_head[0].txt_w,
			&d->txt_head[0].txt_h);
	d->txt_head[0].addr = mlx_get_data_addr(d->txt_head[0].img,
			&d->txt_head[0].bits_per_pixel, &d->txt_head[0].line_length,
			&d->txt_head[0].endian);
	d->txt_head[1].img = mlx_xpm_file_to_image(d->m_ptr->mlx,
			d->map_ptr->animated_head[1], &d->txt_head[1].txt_w,
			&d->txt_head[1].txt_h);
	d->txt_head[1].addr = mlx_get_data_addr(d->txt_head[1].img,
			&d->txt_head[1].bits_per_pixel, &d->txt_head[1].line_length,
			&d->txt_head[1].endian);
	d->txt_head[2].img = mlx_xpm_file_to_image(d->m_ptr->mlx,
			d->map_ptr->animated_head[2], &d->txt_head[2].txt_w,
			&d->txt_head[2].txt_h);
	d->txt_head[2].addr = mlx_get_data_addr(d->txt_head[2].img,
			&d->txt_head[2].bits_per_pixel, &d->txt_head[2].line_length,
			&d->txt_head[2].endian);
}

void	img_hands(t_data *d)
{
	d->map_ptr->start_time_hand = get_actual_time();
	d->swap_hands = 0;
	d->txt_hands = malloc(sizeof(t_texture) * 3);
	d->txt_hands[0].img = mlx_xpm_file_to_image(d->m_ptr->mlx,
			d->map_ptr->animated_hands[0], &d->txt_hands[0].txt_w,
			&d->txt_hands[0].txt_h);
	d->txt_hands[0].addr = mlx_get_data_addr(d->txt_hands[0].img,
			&d->txt_hands[0].bits_per_pixel, &d->txt_hands[0].line_length,
			&d->txt_hands[0].endian);
	d->txt_hands[1].img = mlx_xpm_file_to_image(d->m_ptr->mlx,
			d->map_ptr->animated_hands[1], &d->txt_hands[1].txt_w,
			&d->txt_hands[1].txt_h);
	d->txt_hands[1].addr = mlx_get_data_addr(d->txt_hands[1].img,
			&d->txt_hands[1].bits_per_pixel, &d->txt_hands[1].line_length,
			&d->txt_hands[1].endian);
	d->txt_hands[2].img = mlx_xpm_file_to_image(d->m_ptr->mlx,
			d->map_ptr->animated_hands[2], &d->txt_hands[2].txt_w,
			&d->txt_hands[2].txt_h);
	d->txt_hands[2].addr = mlx_get_data_addr(d->txt_hands[2].img,
			&d->txt_hands[2].bits_per_pixel, &d->txt_hands[2].line_length,
			&d->txt_hands[2].endian);
}
