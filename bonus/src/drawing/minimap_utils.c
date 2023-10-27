/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:50:21 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/27 09:21:00 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	create_big_map(t_data *d)
{
	set_larger_line(d);
	add_spaces(d);
}

void	init_t_miniplayer(t_miniplayer *mp)
{
	mp->pl_radius = SCREENHEIGHT * 0.00625;
	mp->line_length = SCREENHEIGHT * 0.025;
	mp->i_center = (int)((SCREENWIDTH * 0.86875
		+ SCREENWIDTH * 0.878125) / 2);
	mp->j_center = (int)((SCREENHEIGHT * 0.9125
		+ SCREENHEIGHT * 0.925) / 2);
	mp->dx = 0;
	mp->dy = 0;
	mp->sx = 0;
	mp->sy = 0;
	mp->err = 0;
	mp->e2 = 0;
	mp->x2 = 0;
	mp->y2 = 0;
}

void	init_t_minimap(t_minimap *mm, t_data *d)
{
	mm->start_x = d->pos_x;
	mm->end_x = d->pos_x + 10 + 10;
	mm->start_y = d->pos_y;
	mm->end_y = d->pos_y + 5 + 5;
	mm->x = ((double)SCREENHEIGHT * 0.85);
	mm->big_map = ft_calloc((d->map_ptr->map_end - \
		d->map_ptr->map_start + 10), sizeof(char *));
}
