/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:56:22 by ialves-m          #+#    #+#             */
/*   Updated: 2023/09/28 20:41:112 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	handle_keypress(int keysym, t_mlx *m)
{
	if (keysym == XK_W || keysym == XK_w)
	{
		if (*m->data_ptr->worldMap_ptr[(int)(m->data_ptr->posX + m->data_ptr->dirX * m->data_ptr->moveSpeed)][(int)(m->data_ptr->posY)] == 0)
			m->data_ptr->posX += m->data_ptr->dirX * m->data_ptr->moveSpeed;
		
		if (*m->data_ptr->worldMap_ptr[(int)(m->data_ptr->posX)][(int)(m->data_ptr->posY + m->data_ptr->dirY * m->data_ptr->moveSpeed)] == 0)
			m->data_ptr->posY += m->data_ptr->dirY * m->data_ptr->moveSpeed;

		// int xxx = *m->data_ptr->worldMap_ptr[(int)(m->data_ptr->posX + m->data_ptr->dirX * m->data_ptr->moveSpeed)][(int)(m->data_ptr->posY)];
		// printf("%d\n", xxx);
	}
	if (keysym == XK_S || keysym == XK_s)
	{
		//if(m->data_ptr->worldMap_ptr[(int)(m->data_ptr->posX - m->data_ptr->dirX * m->data_ptr->moveSpeed)][(int)(m->data_ptr->posY)] == false)
		m->data_ptr->posX -= m->data_ptr->dirX * m->data_ptr->moveSpeed;
		//if(m->data_ptr->worldMap_ptr[(int)(m->data_ptr->posX)][(int)(m->data_ptr->posY - m->data_ptr->dirY * m->data_ptr->moveSpeed)] == false)
		m->data_ptr->posY -= m->data_ptr->dirY * m->data_ptr->moveSpeed;
	}
	if (keysym == XK_D || keysym == XK_d)
	{
		//if(m->data_ptr->worldMap_ptr[(int)(m->data_ptr->posX - m->data_ptr->dirX * m->data_ptr->moveSpeed)][(int)(m->data_ptr->posY)] == false)
		m->data_ptr->posX -= m->data_ptr->dirY * m->data_ptr->moveSpeed;
		//if(m->data_ptr->worldMap_ptr[(int)(m->data_ptr->posX)][(int)(m->data_ptr->posY - m->data_ptr->dirY * m->data_ptr->moveSpeed)] == false)
		m->data_ptr->posY -= m->data_ptr->dirX * m->data_ptr->moveSpeed;
	}
	if (keysym == XK_A || keysym == XK_a)
	{
		//if(m->data_ptr->worldMap_ptr[(int)(m->data_ptr->posX - m->data_ptr->dirX * m->data_ptr->moveSpeed)][(int)(m->data_ptr->posY)] == false)
		m->data_ptr->posX += m->data_ptr->dirY * m->data_ptr->moveSpeed;
		//if(m->data_ptr->worldMap_ptr[(int)(m->data_ptr->posX)][(int)(m->data_ptr->posY - m->data_ptr->dirY * m->data_ptr->moveSpeed)] == false)
		m->data_ptr->posY += m->data_ptr->dirX * m->data_ptr->moveSpeed;
	}
	if (keysym == XK_Right)
	{
		//both camera direction and camera plane must be rotated
		m->data_ptr->oldDirX = m->data_ptr->dirX;
		m->data_ptr->dirX = m->data_ptr->dirX * cos(-m->data_ptr->rotSpeed) - m->data_ptr->dirY * sin(-m->data_ptr->rotSpeed);
		m->data_ptr->dirY = m->data_ptr->oldDirX * sin(-m->data_ptr->rotSpeed) + m->data_ptr->dirY * cos(-m->data_ptr->rotSpeed);
		m->data_ptr->oldPlaneX = m->data_ptr->planeX;
		m->data_ptr->planeX = m->data_ptr->planeX * cos(-m->data_ptr->rotSpeed) - m->data_ptr->planeY * sin(-m->data_ptr->rotSpeed);
		m->data_ptr->planeY = m->data_ptr->oldPlaneX * sin(-m->data_ptr->rotSpeed) + m->data_ptr->planeY * cos(-m->data_ptr->rotSpeed);
	}
	if (keysym == XK_Left)
	{
		//both camera direction and camera plane must be rotated
		m->data_ptr->oldDirX = m->data_ptr->dirX;
		m->data_ptr->dirX = m->data_ptr->dirX * cos(m->data_ptr->rotSpeed) - m->data_ptr->dirY * sin(m->data_ptr->rotSpeed);
		m->data_ptr-> dirY = m->data_ptr->oldDirX * sin(m->data_ptr->rotSpeed) + m->data_ptr->dirY * cos(m->data_ptr->rotSpeed);
		m->data_ptr->oldPlaneX = m->data_ptr->planeX;
		m->data_ptr-> planeX = m->data_ptr->planeX * cos(m->data_ptr->rotSpeed) - m->data_ptr->planeY * sin(m->data_ptr->rotSpeed);
		m->data_ptr->planeY = m->data_ptr->oldPlaneX * sin(m->data_ptr->rotSpeed) + m->data_ptr->planeY * cos(m->data_ptr->rotSpeed);
	}
	if (keysym == XK_Escape)
		close_window(m);
	return (0);
}
