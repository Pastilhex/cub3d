/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 21:50:47 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/23 21:52:15 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	set_start_ns(char c, t_data *d)
{
	if (c == 'N')
	{
		d->dir_x = -1;
		d->dir_y = 0;
		d->plane_x = 0;
		d->plane_y = 0.66;
	}
	if (c == 'S')
	{
		d->dir_x = 1;
		d->dir_y = 0;
		d->plane_x = 0;
		d->plane_y = -0.66;
	}
}

void	set_start(double i, double k, char c, t_map *m)
{
	t_data	*d;

	d = m->data_ptr;
	d->pos_x = i + 0.50;
	d->pos_y = k + 0.50;
	set_start_ns(c, d);
	if (c == 'W')
	{
		d->dir_x = 0;
		d->dir_y = -1;
		d->plane_x = -0.66;
		d->plane_y = 0;
	}
	if (c == 'E')
	{
		d->dir_x = 0;
		d->dir_y = 1;
		d->plane_x = 0.66;
		d->plane_y = 0;
	}
}
