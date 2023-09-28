/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 09:33:20 by ialves-m          #+#    #+#             */
/*   Updated: 2023/09/28 16:45:36 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int worldMap[mapWidth][mapHeight]=
{
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
}; // Mapa definido como variavel global para já

void	background(t_mlx m, int ground_color, int sky_color)
{
	draw_sky(m, sky_color);
	draw_ground(m, ground_color);
	mlx_put_image_to_window(m.mlx, m.mlx_win, m.img, 0, 0);
}
// void back2(t_mlx m)
// {
// 	draw_sky(m, RED);
// 	draw_ground(m, GREEN);
// 	mlx_put_image_to_window(m.mlx, m.mlx_win, m.img, 0, 0);
// }

int	render_frames(void *arg)
{
	t_data *data;

	data = arg;
	background(*data->m_ptr, RED, BLUE);
	sleep(1);

	
	for(int x = 0; x < screenWidth; x++)
	{
		//calculate ray position and direction
		data->cameraX = 2 * x / (double)screenWidth - 1; //x-coordinate in camera space
		data->rayDirX = data->dirX + data->planeX * data->cameraX;
		data->rayDirY = data->dirY + data->planeY * data->cameraX;
		//which box of the map we're in
		data->mapX = (int)data->posX;
		data->mapY = (int)data->posY;

		//length of ray from current position to next x or y-side
		// data->sideDistX;
		// data->sideDistY;

		//length of ray from one x or y-side to next x or y-side
		//these are derived as:
		//deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX))
		//deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY))
		//which can be simplified to abs(|rayDir| / rayDirX) and abs(|rayDir| / rayDirY)
		//where |rayDir| is the length of the vector (rayDirX, rayDirY). Its length,
		//unlike (data.dirX, dirY) is not 1, however this does not matter, only the
		//ratio between deltaDistX and deltaDistY matters, due to the way the DDA
		//stepping further below works. So the values can be computed as below.
		// Division through zero is prevented, even though technically that's not
		// needed in C++ with IEEE 754 floating point values.
		// data->deltaDistX = (data->rayDirX == 0) ? 1e30 : abs(1 / data->rayDirX);
		// data->deltaDistY = (data->rayDirY == 0) ? 1e30 : abs(1 / data->rayDirY);
		if (data->rayDirX == 0)
			data->deltaDistX = 1e30;
		else
			data->deltaDistX = fabs(1.0 / data->rayDirX);

		if (data->rayDirY == 0)
			data->deltaDistY = 1e30;
		else
			data->deltaDistY = fabs(1.0 / data->rayDirY);
		

		//what direction to step in x or y-direction (either +1 or -1)


		data-> hit = 0; //was there a wall hit?
		
		//calculate step and initial sideDist
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
		if(data->rayDirY < 0)
		{
			data->stepY = -1;
			data->sideDistY = (data->posY - data->mapY) * data->deltaDistY;
		}
		else
		{
			data->stepY = 1;
			data->sideDistY = (data->mapY + 1.0 - data->posY) * data->deltaDistY;
		}
		
		//perform DDA
		while(data->hit == 0)
		{
		//jump to next map square, either in x-direction, or in y-direction
		if(data->sideDistX < data->sideDistY)
		{
			data->sideDistX += data->deltaDistX;
			data->mapX += data->stepX;
			data->side = 0;
		}
		else
		{
			data->sideDistY += data->deltaDistY;
			data->mapY += data->stepY;
			data->side = 1;
		}
		//Check if ray has hit a wall
		if(worldMap[data->mapX][data->mapY] > 0) data->hit = 1;
		}
		//Calculate distance projected on camera direction. This is the shortest distance from the point where the wall is
		//hit to the camera plane. Euclidean to center camera point would give fisheye effect!
		//This can be computed as (mapX - data.posX + (1 - stepX) / 2) / rayDirX for side == 0, or same formula with Y
		//for size == 1, but can be simplified to the code below thanks to how sideDist and deltaDist are computed:
		//because they were left scaled to |rayDir|. sideDist is the entire length of the ray above after the multiple
		//steps, but we subtract deltaDist once because one step more into the wall was taken above.
		if(data->side == 0)
			data->perpWallDist = (data->sideDistX - data->deltaDistX);
		else
			data->perpWallDist = (data->sideDistY - data->deltaDistY);

		//Calculate height of line to draw on screen
		data->lineHeight = (int)(screenHeight / data->perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		data->drawStart = -data->lineHeight / 2 + screenHeight / 2;
		if(data->drawStart < 0)
			data->drawStart = 0;
		
		data->drawEnd = data->lineHeight / 2 + screenHeight / 2;
		if(data->drawEnd >= screenHeight)
			data->drawEnd = screenHeight - 1;

		//choose wall color
		// ColorRGB color;
		// switch(worldMap[mapX][mapY])
		// {
		// 	case 1:  color = RGB_Red;    break; //red
		// 	case 2:  color = RGB_Green;  break; //green
		// 	case 3:  color = RGB_Blue;   break; //blue
		// 	case 4:  color = RGB_White;  break; //white
		// 	default: color = RGB_Yellow; break; //yellow
		// }
		
		// Choose wall color
		int color;
		switch (worldMap[data->mapX][data->mapY]) {
			case 1:
				color = RED;
				break; // red
			case 2:
				color = GREEN;
				break; // green
			case 3:
				color = CUSTOM;
				break; // blue
			case 4:
				color = WHITE;
				break; // white
			default:
				color = YELLOW;
				break; // yellow
		}
		//give x and y sides different brightness
		if(data->side == 1) {color = color / 2;}

		//draw the pixels of the stripe as a vertical line
		// vertical_line(x, data->drawStart, data->drawEnd, color);
		for(int y = data->drawStart; y <= data->drawEnd; y++)
			ft_pix_put(data->m_ptr, x, y, color);
	}



	
	return(0);
}
	
int main()
{
	t_mlx m;
	t_data data;

	data.posX = 22, data.posY = 12;  //x and y start position
	data.dirX = -1, data.dirY = 0; //initial direction vector
	data.planeX = 0, data.planeY = 0.66; //the 2d raycaster version of camera plane
	data.time = 0; //time of current frame
	data.oldTime = 0; //time of previous frame

	data.m_ptr = &m;
	open_window(&m, screenWidth, screenHeight, "Cube3d IvoJao");

	mlx_hook(m.mlx_win, 2, 1L << 0, &handle_keypress, &m);
	mlx_hook(m.mlx_win, 17, 0, close_window, &m);
	mlx_loop_hook(m.mlx, render_frames, &data);
	mlx_loop(m.mlx);	
}
