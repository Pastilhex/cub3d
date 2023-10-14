/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:50:21 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/14 12:34:28 by joaoalme         ###   ########.fr       */
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
	j_correction = 80.0 / ((double)SCREENHEIGHT / 6.0);
	i_correction = (640.0 / (double)SCREENWIDTH);
	while (i < SCREENWIDTH)
	{
		// printf("j: %d, i: %d\n",((int)SCREENHEIGHT - (SCREENHEIGHT / 6)), i);
		j = SCREENHEIGHT - (SCREENHEIGHT / 6);
		while (j < SCREENHEIGHT)
		{
			ft_pixel_put(data->m_ptr, i, j, (unsigned int)ft_pixel_get(&data->txt_ptr[hud], i * i_correction, (int)(80 - ((SCREENHEIGHT - j ) * j_correction))));

			j++;
		}
		i++;
	}
}

// 128 x 128
void	draw_hands(t_data *data)
{
	int	i;
	int	j;
	// double j_correction;
	// double i_correction;

	i = SCREENWIDTH - (SCREENWIDTH * 0.6);
	// i_correction = 128.0 / ((double)SCREENWIDTH / 4.6875);
	// j_correction = 128.0 / ((double)SCREENHEIGHT / 3.75);
	while (i < (SCREENWIDTH - SCREENWIDTH * 0.4))
	{
		// printf("j: %d, i: %d\n",((int)SCREENHEIGHT - (SCREENHEIGHT / 6)), i);
		j = SCREENHEIGHT - (SCREENHEIGHT / 6 + SCREENHEIGHT / 3.75);
		while (j < SCREENHEIGHT - (SCREENHEIGHT / 6))
		{
			ft_pixel_put(data->m_ptr, i, j, (unsigned int)ft_pixel_get(&data->txt_ptr[hands], (int)(i - ((SCREENWIDTH - SCREENWIDTH * 0.4) - 1)), (int)(j - ((SCREENHEIGHT - (SCREENHEIGHT / 6 + SCREENHEIGHT / 3.75)) - 1))));
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
