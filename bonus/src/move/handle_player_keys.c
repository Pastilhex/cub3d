/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_player_keys.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:11:05 by ialves-m          #+#    #+#             */
/*   Updated: 2023/10/26 14:53:48 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move_p_up(t_mlx *m)
{
	if (m->data_ptr->map_ptr->world_map[(int)(m->data_ptr->pos_x + \
			m->data_ptr->dir_x * m->data_ptr->move_margin)]
			[(int)(m->data_ptr->pos_y)] == '0'
			|| m->data_ptr->map_ptr->world_map[(int)(m->data_ptr->pos_x + \
			m->data_ptr->dir_x * m->data_ptr->move_margin)]
			[(int)(m->data_ptr->pos_y)] == '9')
		m->data_ptr->pos_x += m->data_ptr->dir_x * m->data_ptr->move_speed;
	if (m->data_ptr->map_ptr->world_map[(int)(m->data_ptr->pos_x)] \
			[(int)(m->data_ptr->pos_y + m->data_ptr->dir_y *
			m->data_ptr->move_margin)] == '0'
			|| m->data_ptr->map_ptr->world_map[(int)(m->data_ptr->pos_x)] \
			[(int)(m->data_ptr->pos_y + m->data_ptr->dir_y *
			m->data_ptr->move_margin)] == '9')
		m->data_ptr->pos_y += m->data_ptr->dir_y * m->data_ptr->move_speed;
}

void	move_p_down(t_mlx *m)
{
	if (m->data_ptr->map_ptr->world_map[(int)(m->data_ptr->pos_x - \
			m->data_ptr->dir_x * m->data_ptr->move_margin)]
			[(int)(m->data_ptr->pos_y)] == '0'
			|| m->data_ptr->map_ptr->world_map[(int)(m->data_ptr->pos_x - \
			m->data_ptr->dir_x * m->data_ptr->move_margin)]
			[(int)(m->data_ptr->pos_y)] == '9')
		m->data_ptr->pos_x -= m->data_ptr->dir_x * m->data_ptr->move_speed;
	if (m->data_ptr->map_ptr->world_map[(int)(m->data_ptr->pos_x)] \
			[(int)(m->data_ptr->pos_y - m->data_ptr->dir_y *
			m->data_ptr->move_margin)] == '0'
			|| m->data_ptr->map_ptr->world_map[(int)(m->data_ptr->pos_x)] \
			[(int)(m->data_ptr->pos_y - m->data_ptr->dir_y *
			m->data_ptr->move_margin)] == '9')
		m->data_ptr->pos_y -= m->data_ptr->dir_y * m->data_ptr->move_speed;
}

void	move_p_right(t_mlx *m)
{
	m->data_ptr->old_dir_x = m->data_ptr->dir_x;
	m->data_ptr->dir_x = m->data_ptr->dir_x * cos(-m->data_ptr->rot_speed) \
			- m->data_ptr->dir_y * sin(-m->data_ptr->rot_speed);
	m->data_ptr->dir_y = m->data_ptr->old_dir_x * sin(-m->data_ptr->rot_speed) \
			+ m->data_ptr->dir_y * cos(-m->data_ptr->rot_speed);
	m->data_ptr->old_plane_x = m->data_ptr->plane_x;
	m->data_ptr->plane_x = m->data_ptr->plane_x * cos(-m->data_ptr->rot_speed) \
		- m->data_ptr->plane_y * sin(-m->data_ptr->rot_speed);
	m->data_ptr->plane_y = m->data_ptr->old_plane_x * \
		sin(-m->data_ptr->rot_speed) + m->data_ptr->plane_y * \
		cos(-m->data_ptr->rot_speed);
}

void	move_p_left(t_mlx *m)
{
	m->data_ptr->old_dir_x = m->data_ptr->dir_x;
	m->data_ptr->dir_x = m->data_ptr->dir_x * cos(m->data_ptr->rot_speed) \
		- m->data_ptr->dir_y * sin(m->data_ptr->rot_speed);
	m->data_ptr-> dir_y = m->data_ptr->old_dir_x * \
		sin(m->data_ptr->rot_speed) + m->data_ptr->dir_y * \
			cos(m->data_ptr->rot_speed);
	m->data_ptr->old_plane_x = m->data_ptr->plane_x;
	m->data_ptr-> plane_x = m->data_ptr->plane_x * \
		cos(m->data_ptr->rot_speed) - m->data_ptr->plane_y * \
			sin(m->data_ptr->rot_speed);
	m->data_ptr->plane_y = m->data_ptr->old_plane_x * \
		sin(m->data_ptr->rot_speed) + m->data_ptr->plane_y * \
			cos(m->data_ptr->rot_speed);
}
