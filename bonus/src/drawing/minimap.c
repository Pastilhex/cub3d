/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:50:21 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/23 21:08:16 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_square(char c, t_data *d, int x, int y)
{
	unsigned int	color;
	int				x_end;
	int				y_end;
	int				start_y;

	(void)c;
	x_end = x + (0.0125 * SCREENHEIGHT);
	y_end = y + (0.009375 * SCREENWIDTH);
	start_y = y;
	color = 0xA4A4A4;
	if (c != '0')
		color = 0x646464;
	while (x < x_end)
	{
		y = start_y;
		while (y < y_end)
		{
			ft_pixel_put(d->m_ptr, y, x, color);
			y++;
		}
		x++;
	}
}

void	draw_circle(t_mlx *mlx, int x, int y, int radius)
{
	int	i;
	int	j;
	int	color;

	color = 0xFF0000;
	i = 0;
	while (i < 2 * radius)
	{
		j = 0;
		while (j < 2 * radius)
		{
			if ((i - radius) * (i - radius) + (j - radius) * (j
					- radius) <= radius * radius)
				ft_pixel_put(mlx, x + i - radius, y + j - radius, color);
			j++;
		}
		i++;
	}
}

void	draw_line(t_data *d, t_miniplayer mp, int x2, int y2)
{
	if (mp.i_center < x2)
		mp.sx = 1;
	else
		mp.sx = -1;
	if (mp.j_center < y2)
		mp.sy = 1;
	else
		mp.sy = -1;
	while (mp.i_center != x2 || mp.j_center != y2)
	{
		mp.e2 = 2 * mp.err;
		if (mp.e2 > -mp.dy)
		{
			mp.err -= mp.dy;
			mp.i_center += mp.sx;
		}
		if (mp.e2 < mp.dx)
		{
			mp.err += mp.dx;
			mp.j_center += mp.sy;
		}
		ft_pixel_put(d->m_ptr, mp.i_center, mp.j_center, 0xFE1010);
	}
}

void	draw_miniplayer(t_data *d)
{
	t_miniplayer	mp;
	int				x2;
	int				y2;

	init_t_miniplayer(&mp);
	x2 = mp.i_center + (d->dir_y * mp.line_length);
	y2 = mp.j_center + (d->dir_x * mp.line_length);
	draw_circle(d->m_ptr, mp.i_center, mp.j_center, mp.pl_radius);
	mp.x2 = mp.i_center + (d->dir_y * mp.line_length);
	mp.y2 = mp.j_center + (d->dir_x * mp.line_length);
	mp.dx = abs(x2 - mp.i_center);
	mp.dy = abs(y2 - mp.j_center);
	mp.err = mp.dx - mp.dy;
	draw_line(d, mp, x2, y2);
}

void	get_minimap(t_data *d)
{
	t_minimap	mm;

	init_t_minimap(&mm, d);
	d->mini_map_ptr = &mm;
	copy_large_world_map(d);
	while (mm.start_x <= d->pos_x + 10)
	{
		mm.start_y = d->pos_y;
		mm.y = SCREENWIDTH * 0.775;
		while (mm.start_y <= d->pos_y + 20)
		{
			draw_square(mm.big_map[(int)mm.start_x][(int)mm.start_y], d, mm.x,
				mm.y);
			mm.start_y++;
			mm.y += 0.009375 * SCREENWIDTH;
		}
		mm.start_x++;
		mm.x += (0.0125 * SCREENHEIGHT);
	}
	free_arr2(d->mini_map_ptr->big_map, d->map_ptr->map_end
		- d->map_ptr->map_start + 10);
	draw_miniplayer(d);
}
