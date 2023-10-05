/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frames.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:11:26 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/05 13:11:27 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void     render_frames1(t_data *data, int *x)
{
	data->cameraX = 2 * *x / (double)screenWidth - 1; 
	data->rayDirX = data->dirX + data->planeX * data->cameraX;
	data->rayDirY = data->dirY + data->planeY * data->cameraX;
	data->mapX = (int)data->posX;
	data->mapY = (int)data->posY;
	if (data->rayDirX == 0)
		data->deltaDistX = 1e30;
	else
		data->deltaDistX = fabs(1.0 / data->rayDirX);

	if (data->rayDirY == 0)
		data->deltaDistY = 1e30;
	else
		data->deltaDistY = fabs(1.0 / data->rayDirY);
	data->hit = '0'; 
	if(data->rayDirX < 0)
		{
			data->stepX = -1;
			data->sideDistX = (data->posX - data->mapX) * data->deltaDistX;
		}
		else
		{
			data->stepX = 1;
			data->sideDistX = (data->mapX + 1.0 - data->posX) * data->deltaDistX;
		}
}


static void     fps(t_data *data)
{
	data->oldTime = data->time;
    data->time = get_actual_time();
	data->frameTime = (data->time - data->oldTime) / 1000.0; 
	if (data->tps <= 1.0)
	{
		data->fps++;
		data->tps += data->frameTime;
	}	
	else
	{
		printf("FPS: %d\n", data->fps);
		data->fps = 0;
		data->tps = 0.0;
	}
}
int	render_frames(void *arg)
{
	t_data 	*data;
	int		x;

	data = arg;
	background(*data->m_ptr, BLACK, WHITE);
	x = 0;
	while (x < screenWidth)
	{
		render_frames1(data, &x);
		render_frames2(data, &x);
		x++;
	}
	fps(data);
	data->moveSpeed = data->frameTime * 5.0;
	data->rotSpeed = data->frameTime * 2.0; 
	movePlayer(data);
	return(0);
}
