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

int	handle_keypress(int keysym, t_mlx *m)
{
	if (keysym == XK_W || keysym == XK_w)
	{
		if (m->data_ptr->map_ptr->worldMap[(int)(POSX + DIRX * MOVESPEED)][(int)(POSY)] == '0')
			POSX += DIRX * MOVESPEED;
		
		if (m->data_ptr->map_ptr->worldMap[(int)(POSX)][(int)(POSY + DIRY * MOVESPEED)] == '0')
			POSY += DIRY * MOVESPEED;
	}
	if (keysym == XK_S || keysym == XK_s)
	{
		if(m->data_ptr->map_ptr->worldMap[(int)(POSX - DIRX * MOVESPEED)][(int)(POSY)] == '0')
			POSX -= DIRX * MOVESPEED;
		if(m->data_ptr->map_ptr->worldMap[(int)(POSX)][(int)(POSY - DIRY * MOVESPEED)] == '0')
			POSY -= DIRY * MOVESPEED;
	}	
	if (keysym == XK_D || keysym == XK_d)
	{
		if(m->data_ptr->map_ptr->worldMap[(int)(POSY - DIRX * MOVESPEED)][(int)(POSY)] == '0')
			POSX += DIRY * MOVESPEED;
		if(m->data_ptr->map_ptr->worldMap[(int)(POSX)][(int)(POSY - DIRY * MOVESPEED)] == '0')
			POSY -= DIRX * MOVESPEED;
	}
	if (keysym == XK_A || keysym == XK_a)
	{
		if(m->data_ptr->map_ptr->worldMap[(int)(POSY + DIRX * MOVESPEED)][(int)(POSY)] == '0')
			POSX -= DIRY * MOVESPEED;
		if(m->data_ptr->map_ptr->worldMap[(int)(POSX)][(int)(POSY - DIRY * MOVESPEED)] == '0')
			POSY += DIRX * MOVESPEED;
	}
	if (keysym == XK_Right)
	{
		//both camera direction and camera plane must be rotated
		m->data_ptr->oldDirX = DIRX;
		DIRX = DIRX * cos(-ROTSPEED) - DIRY * sin(-ROTSPEED);
		DIRY = m->data_ptr->oldDirX * sin(-ROTSPEED) + DIRY * cos(-ROTSPEED);
		m->data_ptr->oldPlaneX = m->data_ptr->planeX;
		m->data_ptr->planeX = m->data_ptr->planeX * cos(-ROTSPEED) - m->data_ptr->planeY * sin(-ROTSPEED);
		m->data_ptr->planeY = m->data_ptr->oldPlaneX * sin(-ROTSPEED) + m->data_ptr->planeY * cos(-ROTSPEED);
	}
	if (keysym == XK_Left)
	{
		//both camera direction and camera plane must be rotated
		m->data_ptr->oldDirX = DIRX;
		DIRX = DIRX * cos(ROTSPEED) - DIRY * sin(ROTSPEED);
		m->data_ptr-> dirY = m->data_ptr->oldDirX * sin(ROTSPEED) + DIRY * cos(ROTSPEED);
		m->data_ptr->oldPlaneX = m->data_ptr->planeX;
		m->data_ptr-> planeX = m->data_ptr->planeX * cos(ROTSPEED) - m->data_ptr->planeY * sin(ROTSPEED);
		m->data_ptr->planeY = m->data_ptr->oldPlaneX * sin(ROTSPEED) + m->data_ptr->planeY * cos(ROTSPEED);
	}
	if (keysym == XK_Escape)
		close_window(m);
	return (0);
}
