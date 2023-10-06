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

#define POSX m->data_ptr->posX
#define POSY m->data_ptr->posY
#define DIRX m->data_ptr->dirX
#define DIRY m->data_ptr->dirY
#define MOVESPEED m->data_ptr->moveSpeed
#define ROTSPEED m->data_ptr->rotSpeed
#define STRAFE_X m->data_ptr->planeX
#define STRAFE_Y m->data_ptr->planeY

void	moveUp(t_mlx *m)
{
	if (m->data_ptr->map_ptr->worldMap[(int)(POSX + DIRX * .5)][(int)(POSY)] == '0')
		POSX += DIRX * MOVESPEED;
	
	if (m->data_ptr->map_ptr->worldMap[(int)(POSX)][(int)(POSY + DIRY * .5)] == '0')
		POSY += DIRY * MOVESPEED;
}

void	moveDown(t_mlx *m)
{
	if(m->data_ptr->map_ptr->worldMap[(int)(POSX - DIRX * .5)][(int)(POSY)] == '0')
		POSX -= DIRX * MOVESPEED;
	if(m->data_ptr->map_ptr->worldMap[(int)(POSX)][(int)(POSY - DIRY * .5)] == '0')
		POSY -= DIRY * MOVESPEED;
}

void	moveSlideLeft(t_mlx *m)
{
	if(m->data_ptr->map_ptr->worldMap[(int)(POSX - STRAFE_X * .5)][(int)(POSY)] == '0')
		POSX -= STRAFE_X * MOVESPEED;
	if(m->data_ptr->map_ptr->worldMap[(int)(POSX)][(int)(POSY - STRAFE_Y * .5)] == '0')
		POSY -= STRAFE_Y * MOVESPEED;
}

void	moveSlideRight(t_mlx *m)
{
	if(m->data_ptr->map_ptr->worldMap[(int)(POSX + STRAFE_X * .5)][(int)(POSY)] == '0')
		POSX += STRAFE_X * MOVESPEED;
	if(m->data_ptr->map_ptr->worldMap[(int)(POSX)][(int)(POSY + STRAFE_Y * .5)] == '0')
		POSY += STRAFE_Y * MOVESPEED;	
}

void	moveRight(t_mlx *m)
{
	//both camera direction and camera plane must be rotated
	m->data_ptr->oldDirX = DIRX;
	DIRX = DIRX * cos(-ROTSPEED) - DIRY * sin(-ROTSPEED);
	DIRY = m->data_ptr->oldDirX * sin(-ROTSPEED) + DIRY * cos(-ROTSPEED);
	m->data_ptr->oldPlaneX = m->data_ptr->planeX;
	m->data_ptr->planeX = m->data_ptr->planeX * cos(-ROTSPEED) - m->data_ptr->planeY * sin(-ROTSPEED);
	m->data_ptr->planeY = m->data_ptr->oldPlaneX * sin(-ROTSPEED) + m->data_ptr->planeY * cos(-ROTSPEED);
}

void	moveLeft(t_mlx *m)
{
	//both camera direction and camera plane must be rotated
	m->data_ptr->oldDirX = DIRX;
	DIRX = DIRX * cos(ROTSPEED) - DIRY * sin(ROTSPEED);
	m->data_ptr-> dirY = m->data_ptr->oldDirX * sin(ROTSPEED) + DIRY * cos(ROTSPEED);
	m->data_ptr->oldPlaneX = m->data_ptr->planeX;
	m->data_ptr-> planeX = m->data_ptr->planeX * cos(ROTSPEED) - m->data_ptr->planeY * sin(ROTSPEED);
	m->data_ptr->planeY = m->data_ptr->oldPlaneX * sin(ROTSPEED) + m->data_ptr->planeY * cos(ROTSPEED);
}

int	handle_keypress(int keysym, t_mlx *m)
{
	if (keysym == XK_W || keysym == XK_w)
		m->data_ptr->moveUp = 1;
	if (keysym == XK_S || keysym == XK_s)
		m->data_ptr->moveDown = 1;
	if (keysym == XK_A || keysym == XK_a)
		m->data_ptr->slideLeft = 1;
	if (keysym == XK_D || keysym == XK_d)
		m->data_ptr->slideRight = 1;
	if (keysym == XK_Left)
		m->data_ptr->moveLeft = 1;
	if (keysym == XK_Right)
		m->data_ptr->moveRight = 1;
	if (keysym == XK_Escape)
		close_window(m->data_ptr);
	return (0);
}

int	handle_keyrelease(int keysym, t_mlx *m)
{
	if (keysym == XK_W || keysym == XK_w)
		m->data_ptr->moveUp = 0;
	if (keysym == XK_S || keysym == XK_s)
		m->data_ptr->moveDown = 0;
	if (keysym == XK_A || keysym == XK_a)
		m->data_ptr->slideLeft = 0;
	if (keysym == XK_D || keysym == XK_d)
		m->data_ptr->slideRight = 0;
	if (keysym == XK_Right)
		m->data_ptr->moveRight = 0;
	if (keysym == XK_Left)
		m->data_ptr->moveLeft = 0;
	return(0);
}
