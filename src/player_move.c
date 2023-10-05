/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:53:33 by ialves-m          #+#    #+#             */
/*   Updated: 2023/10/05 16:43:39 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void		inner_move(t_data *data)
{
	if (data->moveLeft == 1)
		{
			moveLeft(data->m_ptr);
			if (data->slideLeft == 1)
				moveSlideLeft(data->m_ptr);
		}
		else if (data->moveRight == 1)
		{
			moveRight(data->m_ptr);
			if (data->slideRight == 1)
				moveSlideRight(data->m_ptr);
		}
		else if (data->slideLeft == 1)
			moveSlideLeft(data->m_ptr);
		else if (data->slideRight == 1)
			moveSlideRight(data->m_ptr);
}

void	movePlayer(t_data *data)
{
	if (data->moveUp == 1)
	{
		moveUp(data->m_ptr);
		inner_move(data);
	}
	else if (data->moveDown == 1)
	{
		moveDown(data->m_ptr);
		inner_move(data);
	}
	else if (data->moveLeft == 1)
		moveLeft(data->m_ptr);
	else if (data->moveRight == 1)
		moveRight(data->m_ptr);
	else if (data->slideLeft == 1)
		moveSlideLeft(data->m_ptr);
	else if (data->slideRight == 1)
		moveSlideRight(data->m_ptr);	
}
