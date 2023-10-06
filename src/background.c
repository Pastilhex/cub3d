/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:50:21 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/06 15:37:03 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_int_to_hex(int nbr)
{
	char	*hexa_base;
	int		res;

	res = 0;
	hexa_base = "0123456789abcdef";
	if (nbr >= 16)
		ft_int_to_hex(nbr / 16);
	return (nbr % 16);
}
40/


int	get_rgb_color(char *str)
{
	int		i;
	int 	rgb;
	char	*rgb_str;
	char	*hex;

	i = 0;
	rgb = 0;
	rgb_str = "0x";
	while (str[i])
	{
		while (str[i] && str[i] != ',')
			rgb *= 10 + ft_atoi(&str[i++]);
		hex = ft_itoa(ft_int_to_hex(rgb));
		rgb = 0;
		rgb_str = ft_strjoin(rgb_str, ft_itoa(rgb));
		i++;
	}
	return (ft_atoi(rgb_str));
}

static void     draw_ground(t_mlx m, char *ground)
{
	int		x;
	int		y;
	
	(void) ground;
	x = 0;
	y = screenHeight / 2;
	while (y < screenHeight)
	{
		x = 0;
		while (x < screenWidth)
		{
			ft_pixel_put(&m, x, y, 0x123456);
			x++;
		}
		y++;
	}
}

static void     draw_sky(t_mlx m, char *sky)
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
			ft_pixel_put(&m, x, y, get_rgb_color(sky));
			x++;
		}
		y++;
	}
}

void	background(t_mlx m, t_map *map)
{
	draw_sky(m, map->ceiling_texture);
	draw_ground(m, map->floor_texture);
	mlx_put_image_to_window(m.mlx, m.mlx_win, m.img, 0, 0);
}
