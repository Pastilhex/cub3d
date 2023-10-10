/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:53:33 by ialves-m          #+#    #+#             */
/*   Updated: 2023/10/10 14:43:50 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	open_window(t_mlx *m, int screen_width,
				int screen_height, char *window_description)
{
	m->mlx = mlx_init();
	m->mlx_win = mlx_new_window(m->mlx, screen_width,
			screen_height, window_description);
	m->img = mlx_new_image(m->mlx, screen_width, screen_height);
	m->addr = mlx_get_data_addr(m->img, &m->bits_per_pixel,
			&m->line_length, &m->endian);
}
