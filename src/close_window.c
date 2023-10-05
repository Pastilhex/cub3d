/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:59:10 by ialves-m          #+#    #+#             */
/*   Updated: 2023/10/05 21:20:17 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	close_window(t_mlx *m)
{
	if (m->mlx)
		mlx_destroy_window(m->mlx, m->mlx_win);
	if (m->mlx_win)
		mlx_destroy_display(m->mlx);
	cleaning(m->data_ptr, m->data_ptr->map_ptr);	
	exit(0);
	return (0);
}
