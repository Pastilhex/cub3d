/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:50:21 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/13 15:19:29 by ialves-m         ###   ########.fr       */
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
		// printf("j: %d, i: %d\n",((int)SCREENHEIGHT - (SCREENHEIGHT / 6)), i);
		j = SCREENHEIGHT - (SCREENHEIGHT / 6);
		while (j < SCREENHEIGHT)
		{
			ft_pixel_put(data->m_ptr, i, j, (unsigned int)ft_pixel_get(&data->txt_ptr[hud], i * i_correction, (int)(80 - ((SCREENHEIGHT - j ) * j_correction))));

			j++;
			k++;
		}
		k = 0;
		i++;
	}
}

// void	draw_hands(t_data *data)
// {
// 	int	i;
// 	int	j;

// 	i = 256;
// 	// i = (SCREENWIDTH * 0.4);
// 	j = 432;
// 	// j = SCREENHEIGHT - (SCREENHEIGHT / 3.75);
// 	while (i < (SCREENWIDTH * 0.6))	
// 	{
// 		j = SCREENHEIGHT - (SCREENHEIGHT / 3.75);
// 		while (j < SCREENHEIGHT)
// 		{
// 			ft_pixel_put(data->m_ptr, i, j, (unsigned int)ft_pixel_get(&data->txt_ptr[hands], (int)(i - (SCREENWIDTH - (SCREENWIDTH / 5))), (int)(j - (SCREENHEIGHT - ((SCREENHEIGHT / 3.75))))));	
// 			// ft_pixel_put(data->m_ptr, i, j, (unsigned int)ft_pixel_get(&data->txt_ptr[hands], (int)(i - (SCREENWIDTH - (SCREENWIDTH / 5))), (int)(j - (SCREENHEIGHT - ((SCREENHEIGHT / 3.75))))));	
// 			j++;
// 		}
// 		i++;
// 	}
// }

void	background(t_mlx m, int ground_color, int sky_color)
{
	draw_sky(m, sky_color);
	draw_ground(m, ground_color);
	// mlx_put_image_to_window(m.mlx, m.mlx_win, m.img, 0, 0);
}
