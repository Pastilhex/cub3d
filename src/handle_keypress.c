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

#define POSX m->data_ptr->pos_x
#define POSY m->data_ptr->pos_y
#define DIRX m->data_ptr->dir_x
#define DIRY m->data_ptr->dir_y
#define MOVESPEED m->data_ptr->move_speed
#define ROTSPEED m->data_ptr->rot_speed
#define STRAFE_X m->data_ptr->plane_x
#define STRAFE_Y m->data_ptr->plane_y

void	moveUp(t_mlx *m)
{
	if (m->data_ptr->map_ptr->world_map[(int)(POSX + DIRX * .5)][(int)(POSY)] == '0')
		POSX += DIRX * MOVESPEED;
	
	if (m->data_ptr->map_ptr->world_map[(int)(POSX)][(int)(POSY + DIRY * .5)] == '0')
		POSY += DIRY * MOVESPEED;
}

void	moveDown(t_mlx *m)
{
	if(m->data_ptr->map_ptr->world_map[(int)(POSX - DIRX * .5)][(int)(POSY)] == '0')
		POSX -= DIRX * MOVESPEED;
	if(m->data_ptr->map_ptr->world_map[(int)(POSX)][(int)(POSY - DIRY * .5)] == '0')
		POSY -= DIRY * MOVESPEED;
}

void	moveSlideLeft(t_mlx *m)
{
	if(m->data_ptr->map_ptr->world_map[(int)(POSX - STRAFE_X * .5)][(int)(POSY)] == '0')
		POSX -= STRAFE_X * MOVESPEED;
	if(m->data_ptr->map_ptr->world_map[(int)(POSX)][(int)(POSY - STRAFE_Y * .5)] == '0')
		POSY -= STRAFE_Y * MOVESPEED;
}

void	moveSlideRight(t_mlx *m)
{
	if(m->data_ptr->map_ptr->world_map[(int)(POSX + STRAFE_X * .5)][(int)(POSY)] == '0')
		POSX += STRAFE_X * MOVESPEED;
	if(m->data_ptr->map_ptr->world_map[(int)(POSX)][(int)(POSY + STRAFE_Y * .5)] == '0')
		POSY += STRAFE_Y * MOVESPEED;	
}

void	moveRight(t_mlx *m)
{
	//both camera direction and camera plane must be rotated
	m->data_ptr->old_dir_x = DIRX;
	DIRX = DIRX * cos(-ROTSPEED) - DIRY * sin(-ROTSPEED);
	DIRY = m->data_ptr->old_dir_x * sin(-ROTSPEED) + DIRY * cos(-ROTSPEED);
	m->data_ptr->old_plane_x = m->data_ptr->plane_x;
	m->data_ptr->plane_x = m->data_ptr->plane_x * cos(-ROTSPEED) - m->data_ptr->plane_y * sin(-ROTSPEED);
	m->data_ptr->plane_y = m->data_ptr->old_plane_x * sin(-ROTSPEED) + m->data_ptr->plane_y * cos(-ROTSPEED);
}

void	moveLeft(t_mlx *m)
{
	//both camera direction and camera plane must be rotated
	m->data_ptr->old_dir_x = DIRX;
	DIRX = DIRX * cos(ROTSPEED) - DIRY * sin(ROTSPEED);
	m->data_ptr-> dir_y = m->data_ptr->old_dir_x * sin(ROTSPEED) + DIRY * cos(ROTSPEED);
	m->data_ptr->old_plane_x = m->data_ptr->plane_x;
	m->data_ptr-> plane_x = m->data_ptr->plane_x * cos(ROTSPEED) - m->data_ptr->plane_y * sin(ROTSPEED);
	m->data_ptr->plane_y = m->data_ptr->old_plane_x * sin(ROTSPEED) + m->data_ptr->plane_y * cos(ROTSPEED);
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
	return(0);
}
