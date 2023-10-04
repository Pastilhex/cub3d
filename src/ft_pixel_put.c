/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_put.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:02:23 by ialves-m          #+#    #+#             */
/*   Updated: 2023/10/04 09:13:12 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_pixel_put(t_mlx *m, int x, int y, int color)
{
	char	*dst;

	dst = m->addr + (y * m->line_length + x * (m->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

unsigned int	ft_pixel_get(t_texture *txt, int x, int y)
{
	//char	*dst;

	// dst = txt->addr + (y * txt->line_length + x * (txt->bits_per_pixel / 8));
	// return (*(unsigned int *)dst);
	return (*(unsigned int*)txt->addr + (y * txt->line_length + x * (txt->bits_per_pixel / 8)));
}
