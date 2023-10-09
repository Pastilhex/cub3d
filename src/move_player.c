/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:53:33 by ialves-m          #+#    #+#             */
/*   Updated: 2023/10/09 13:42:07 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	movePlayerUp(t_data *data)
{
	moveUp(data->m_ptr);
	if (data->move_left == 1)
	{
		moveLeft(data->m_ptr);
		if (data->slide_left == 1)
			moveSlideLeft(data->m_ptr);
	}
	else if (data->move_right == 1)
	{
		moveRight(data->m_ptr);
		if (data->slide_right == 1)
			moveSlideRight(data->m_ptr);
	}
	else if (data->slide_left == 1)
		moveSlideLeft(data->m_ptr);
	else if (data->slide_right == 1)
		moveSlideRight(data->m_ptr);	
}

void	movePlayerDown(t_data *data)
{
	moveDown(data->m_ptr);
	if (data->move_left == 1) 
	{
		moveLeft(data->m_ptr);
		if (data->slide_left == 1)
			moveSlideLeft(data->m_ptr);
	}
	else if (data->move_right == 1)
	{
		moveRight(data->m_ptr);
		if (data->slide_right == 1)
			moveSlideRight(data->m_ptr);
	}
	else if (data->slide_left == 1)
		moveSlideLeft(data->m_ptr);
	else if (data->slide_right == 1)
		moveSlideRight(data->m_ptr);
}

void movePlayer(t_data *data)
{
	if (data->move_up == 1)
		movePlayerUp(data);
	else if (data->move_down == 1)
		movePlayerDown(data);
	else if (data->move_left == 1)
		moveLeft(data->m_ptr);
	else if (data->move_right == 1)
		moveRight(data->m_ptr);
	else if (data->slide_left == 1)
		moveSlideLeft(data->m_ptr);
	else if (data->slide_right == 1)
		moveSlideRight(data->m_ptr);
}
