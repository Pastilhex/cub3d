/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:53:33 by ialves-m          #+#    #+#             */
/*   Updated: 2023/10/05 14:34:56 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	movePlayerUp(t_data *data)
{
	moveUp(data->m_ptr);
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

void	movePlayerDown(t_data *data)
{
	moveDown(data->m_ptr);
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

void movePlayer(t_data *data)
{
	if (data->moveUp == 1)
		movePlayerUp(data);
	else if (data->moveDown == 1)
		movePlayerDown(data);
	else if (data->moveLeft == 1)
		moveLeft(data->m_ptr);
	else if (data->moveRight == 1)
		moveRight(data->m_ptr);
	else if (data->slideLeft == 1)
		moveSlideLeft(data->m_ptr);
	else if (data->slideRight == 1)
		moveSlideRight(data->m_ptr);
}
