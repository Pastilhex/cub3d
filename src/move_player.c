/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:53:33 by ialves-m          #+#    #+#             */
/*   Updated: 2023/10/09 16:48:28 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_player_up(t_data *data)
{
	move_p_up(data->m_ptr);
	if (data->move_left == 1)
	{
		move_p_left(data->m_ptr);
		if (data->slide_left == 1)
			move_p_slide_left(data->m_ptr);
	}
	else if (data->move_right == 1)
	{
		move_p_right(data->m_ptr);
		if (data->slide_right == 1)
			move_p_slide_right(data->m_ptr);
	}
	else if (data->slide_left == 1)
		move_p_slide_left(data->m_ptr);
	else if (data->slide_right == 1)
		move_p_slide_right(data->m_ptr);
}

void	move_player_down(t_data *data)
{
	move_p_down(data->m_ptr);
	if (data->move_left == 1)
	{
		move_p_left(data->m_ptr);
		if (data->slide_left == 1)
			move_p_slide_left(data->m_ptr);
	}
	else if (data->move_right == 1)
	{
		move_p_right(data->m_ptr);
		if (data->slide_right == 1)
			move_p_slide_right(data->m_ptr);
	}
	else if (data->slide_left == 1)
		move_p_slide_left(data->m_ptr);
	else if (data->slide_right == 1)
		move_p_slide_right(data->m_ptr);
}

void	move_player(t_data *data)
{
	if (data->move_up == 1)
		move_player_up(data);
	else if (data->move_down == 1)
		move_player_down(data);
	else if (data->move_left == 1)
		move_p_left(data->m_ptr);
	else if (data->move_right == 1)
		move_p_right(data->m_ptr);
	else if (data->slide_left == 1)
		move_p_slide_left(data->m_ptr);
	else if (data->slide_right == 1)
		move_p_slide_right(data->m_ptr);
}
