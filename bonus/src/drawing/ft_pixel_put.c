/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:02:23 by ialves-m          #+#    #+#             */
/*   Updated: 2023/10/13 13:19:49 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_pixel_put(t_mlx *m, int x, int y, int color)
{
	char	*dst;

	if (color == (int)0x980088)
		return ;
	dst = m->addr + (y * m->line_length + x * (m->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
