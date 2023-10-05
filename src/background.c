/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:50:21 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/05 16:03:38 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void     draw_ground(t_mlx m, int color)
{
	int		x;
	int		y;
	
	x = 0;
	y = screenHeight / 2;
	while (y < screenHeight)
	{
		x = 0;
		while (x < screenWidth)
		{
			ft_pixel_put(&m, x, y, color);
			x++;
		}
		y++;
	}
}

static void     draw_sky(t_mlx m, int color)
{
	int		x;
	int		y;
	
	x = 0;
	y = 0;
	while (y < screenHeight / 2)
	{
		x = 0;
		while (x < screenWidth)
		{
			ft_pixel_put(&m, x, y, color);
			x++;
		}
		y++;
	}
}

void	background(t_mlx m, int ground_color, int sky_color)
{
	draw_sky(m, sky_color);
	draw_ground(m, ground_color);
	mlx_put_image_to_window(m.mlx, m.mlx_win, m.img, 0, 0);
}
