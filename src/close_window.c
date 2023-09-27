/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:59:10 by ialves-m          #+#    #+#             */
/*   Updated: 2023/09/27 11:02:54 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	close_window(t_mlx *m)
{
	if (m->mlx)
		mlx_destroy_window(m->mlx, m->mlx_win);
	if (m->mlx_win)
		mlx_destroy_display(m->mlx);
	exit(0);
	return (0);
}
