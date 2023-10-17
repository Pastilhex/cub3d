/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:50:21 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/18 00:11:45 by ialves-m         ###   ########.fr       */
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

void	draw_head_hud(t_data *data)
{
	int	i;
	int	j;
    double a;
    double b;
    double begin_i;
    double begin_j;

    a = 47.0 / ((double) SCREENWIDTH / 13.617021277);
    b = (62.0 / ((double) SCREENHEIGHT / 7.741935484));
    begin_i = (SCREENWIDTH * 0.4265625);
    begin_j = (SCREENHEIGHT * 0.85);
	i = SCREENWIDTH * 0.4265625;
	j = SCREENHEIGHT * 0.855;
	
	data->map_ptr->current_time = get_actual_time();
	if (data->map_ptr->current_time - data->map_ptr->start_time > 1000)
	{
		data->swap_img++;
		if (data->swap_img == 3)
			data->swap_img = 0;
		data->map_ptr->start_time = get_actual_time();
	}
	while (i < SCREENWIDTH * 0.5)
	{
		j = SCREENHEIGHT * 0.855;
		while (j < SCREENHEIGHT * 0.972916667)
		{
			ft_pixel_put(data->m_ptr, i, j, (unsigned int)ft_pixel_get(&data->txt_head[data->swap_img], (int)((i - begin_i) * a), (int)((j - begin_j) * b)));
			j++;
		}
		i++;
	}
}

void    draw_hands(t_data *data)
{
    int i;
    int j;
    double a;
    double b;
    double begin_i;
    double begin_j;
    i = SCREENWIDTH * 0.4;
    a = 128.0 / ((double) SCREENWIDTH / 5);
    b = (128.0 / ((double) SCREENHEIGHT / 3.75));
    begin_i = (SCREENWIDTH * 0.4);
    begin_j = (SCREENHEIGHT - (SCREENHEIGHT / 6.0 + SCREENHEIGHT / 3.75));
	
	data->map_ptr->current_time = get_actual_time();
	if (data->press_space == 1)
	{
		if (data->map_ptr->current_time - data->map_ptr->start_time > 100)
		{
			data->swap_hands++;
			if (data->swap_hands == 3)
			{
				data->swap_hands = 0;
				data->press_space = 0;
			}	
			data->map_ptr->start_time = get_actual_time();
		}
	}
    while (i < SCREENWIDTH * 0.6)
    {
        j = SCREENHEIGHT - (SCREENHEIGHT / 6.0 + SCREENHEIGHT / 3.75);
        while (j < SCREENHEIGHT - (SCREENHEIGHT / 6.0))
        {
            ft_pixel_put(data->m_ptr, i, j, (unsigned int)
                ft_pixel_get(&data->txt_hands[data->swap_hands], (int)((i - begin_i) * a), (int)((j - begin_j) * b)));
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
