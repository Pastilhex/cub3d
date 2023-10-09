/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:56:22 by ialves-m          #+#    #+#             */
/*   Updated: 2023/10/09 17:04:47 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_p_slide_left(t_mlx *m)
{
	if (m->data_ptr->map_ptr->world_map \
		[(int)(m->data_ptr->pos_x - m->data_ptr->plane_x * \
			.5)][(int)(m->data_ptr->pos_y)] == '0')
		m->data_ptr->pos_x -= m->data_ptr->plane_x * m->data_ptr->move_speed;
	if (m->data_ptr->map_ptr->world_map \
		[(int)(m->data_ptr->pos_x)][(int)(m->data_ptr->pos_y \
			- m->data_ptr->plane_y * .5)] == '0')
		m->data_ptr->pos_y -= m->data_ptr->plane_y * m->data_ptr->move_speed;
}

void	move_p_slide_right(t_mlx *m)
{
	if (m->data_ptr->map_ptr->world_map \
		[(int)(m->data_ptr->pos_x + m->data_ptr->plane_x * \
			.5)][(int)(m->data_ptr->pos_y)] == '0')
		m->data_ptr->pos_x += m->data_ptr->plane_x * m->data_ptr->move_speed;
	if (m->data_ptr->map_ptr->world_map \
		[(int)(m->data_ptr->pos_x)][(int)(m->data_ptr->pos_y \
			+ m->data_ptr->plane_y * .5)] == '0')
		m->data_ptr->pos_y += m->data_ptr->plane_y * m->data_ptr->move_speed;
}

int	handle_keypress(int keysym, t_mlx *m)
{
	if (keysym == XK_W || keysym == XK_w)
		m->data_ptr->move_up = 1;
	if (keysym == XK_S || keysym == XK_s)
		m->data_ptr->move_down = 1;
	if (keysym == XK_A || keysym == XK_a)
		m->data_ptr->slide_left = 1;
	if (keysym == XK_D || keysym == XK_d)
		m->data_ptr->slide_right = 1;
	if (keysym == XK_Left)
		m->data_ptr->move_left = 1;
	if (keysym == XK_Right)
		m->data_ptr->move_right = 1;
	if (keysym == XK_Escape)
		close_window(m->data_ptr);
	return (0);
}

int	handle_keyrelease(int keysym, t_mlx *m)
{
	if (keysym == XK_W || keysym == XK_w)
		m->data_ptr->move_up = 0;
	if (keysym == XK_S || keysym == XK_s)
		m->data_ptr->move_down = 0;
	if (keysym == XK_A || keysym == XK_a)
		m->data_ptr->slide_left = 0;
	if (keysym == XK_D || keysym == XK_d)
		m->data_ptr->slide_right = 0;
	if (keysym == XK_Right)
		m->data_ptr->move_right = 0;
	if (keysym == XK_Left)
		m->data_ptr->move_left = 0;
	return (0);
}
