/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:50:21 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/12 20:56:52 by joaoalme         ###   ########.fr       */
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
	double j_correction;
	double i_correction;

	i = 0;
	j = SCREENHEIGHT - (SCREENHEIGHT / 6);
	j_correction = 80.0 / ((double)SCREENHEIGHT / 6.0);
	i_correction = (640.0 / (double)SCREENWIDTH);
	int k = 0;
	while (i < SCREENWIDTH)
	{
		j = SCREENHEIGHT - (SCREENHEIGHT / 6);
		while (j < SCREENHEIGHT)
		{
			// printf("j: %d\ni: %d\n",((int)(((SCREENHEIGHT - j ) * 0.8))), i);
			// ft_pixel_put(data->m_ptr, i, j, (unsigned int)ft_pixel_get(&data->txt_ptr[hud], i, (int)(k * 0.8)));
			ft_pixel_put(data->m_ptr, i, j, (unsigned int)ft_pixel_get(&data->txt_ptr[hud], i * i_correction, (int)(80 - ((SCREENHEIGHT - j ) * j_correction))));
			
			// ft_pixel_put(data->m_ptr, i, j, (unsigned int)ft_pixel_get(&data->txt_ptr[hud], i, j));
			//ft_pixel_put(data->m_ptr, i, j, 0xff00ff);
			j++;
			k++;
		}
		k = 0;
		i++;
	}
}

void	background(t_mlx m, int ground_color, int sky_color)
{
	draw_sky(m, sky_color);
	draw_ground(m, ground_color);
	// mlx_put_image_to_window(m.mlx, m.mlx_win, m.img, 0, 0);
}
