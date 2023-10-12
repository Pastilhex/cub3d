/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:50:21 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/12 18:37:21 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	draw_ground(t_mlx m, int color)
{
	int		x;
	int		y;

	x = 0;
	y = SCREENHEIGHT / 2;
	while (y < SCREENHEIGHT)
	{
		x = 0;
		while (x < SCREENWIDTH)
		{
			ft_pixel_put(&m, x, y, color);
			x++;
		}
		y++;
	}
}

static void	draw_sky(t_mlx m, int color)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < SCREENHEIGHT / 2)
	{
		x = 0;
		while (x < SCREENWIDTH)
		{
			ft_pixel_put(&m, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_hud(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = SCREENHEIGHT - (SCREENHEIGHT / 6);
	while (i < SCREENWIDTH)
	{
		j = SCREENHEIGHT - (SCREENHEIGHT / 6);
		while (j < SCREENHEIGHT)
		{
			// ft_pixel_put(data->m_ptr, 0, 0, (unsigned int)ft_pixel_get(&data->txt_ptr[hud], i, ((double) SCREENHEIGHT * 0.1667)));
			ft_pixel_put(data->m_ptr, 0, 0, (unsigned int)ft_pixel_get(&data->txt_ptr[hud], 10, 10));
			//ft_pixel_put(data->m_ptr, i, j, 0xff00ff);
			j++;
		}
		i++;
	}
}

void	background(t_mlx m, int ground_color, int sky_color)
{
	draw_sky(m, sky_color);
	draw_ground(m, ground_color);
	// mlx_put_image_to_window(m.mlx, m.mlx_win, m.img, 0, 0);
}
