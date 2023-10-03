/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 09:33:20 by ialves-m          #+#    #+#             */
/*   Updated: 2023/10/03 22:25:00 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	background(t_mlx m, int ground_color, int sky_color)
{
	draw_sky(m, sky_color);
	draw_ground(m, ground_color);
	mlx_put_image_to_window(m.mlx, m.mlx_win, m.img, 0, 0);
}

int	render_frames(void *arg)
{
	t_data *data;
	t_map *map;

	data = arg;
	map = data->map_ptr;
	background(*data->m_ptr, BLACK, WHITE);
	
	for(int x = 0; x < screenWidth; x++)
	{
		//calculate ray position and direction
		data->cameraX = 2 * x / (double)screenWidth - 1; //x-coordinate in camera space
		data->rayDirX = data->dirX + data->planeX * data->cameraX;
		data->rayDirY = data->dirY + data->planeY * data->cameraX;

		//which box of the map we're in
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
		
		data->hit = '0'; //was there a wall hit?
		
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
		while(data->hit == '0')
		{
			//jump to next map square, either in x-direction, or in y-direction
			if(data->sideDistX < data->sideDistY)
			{
				data->sideDistX += data->deltaDistX;
				data->mapX += data->stepX;
				data->side = '0';
			}
			else
			{
				data->sideDistY += data->deltaDistY;
				data->mapY += data->stepY;
				data->side = '1';
			}
			
			//Check if ray has hit a wall
			if(map->worldMap[data->mapX][data->mapY] > '0')
				data->hit = '1';
		}
		
		//Calculate distance projected on camera direction. This is the shortest distance from the point where the wall is
		//hit to the camera plane. Euclidean to center camera point would give fisheye effect!
		//This can be computed as (mapX - data.posX + (1 - stepX) / 2) / rayDirX for side == 0, or same formula with Y
		//for size == 1, but can be simplified to the code below thanks to how sideDist and deltaDist are computed:
		//because they were left scaled to |rayDir|. sideDist is the entire length of the ray above after the multiple
		//steps, but we subtract deltaDist once because one step more into the wall was taken above.
		if(data->side == '0')
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

		//calculate value of wallX
		//where exactly the wall was hit
		if (data->side == '0') 
			map->wallX = data->posY + data->perpWallDist * data->rayDirY;
		else
		    map->wallX = data->posX + data->perpWallDist * data->rayDirX;
		map->wallX -= floor((map->wallX));
		
		// int wallColor = map->worldMap[data->mapX][data->mapY];
		// if (data->side == '0' && data->rayDirX > 0 && wallColor == '1')
		// 	color = RED;
		// else if (data->side == '0' && data->rayDirX < 0 && wallColor == '1')
		// 	color = YELLOW;
		// else if (data->side == '1' && data->rayDirY > 0 && wallColor == '1')
		// 	color = BLUE;
		// else if (data->side == '1' && data->rayDirY < 0 && wallColor == '1')
		// 	color = GREEN;

		//x coordinate on the texture
		int texX = (int)(map->wallX * texWidth);
		if(data->side == '0' && data->rayDirX > 0)
			texX = texWidth - texX - 1;
		if(data->side == '1' && data->rayDirY < 0)
			texX = texWidth - texX - 1;
		
		// How much to increase the texture coordinate per screen pixel
		map->step = 1.0 * texHeight / data->lineHeight;
		
		// Starting texture coordinate
		map->texPos = (data->drawStart - (int)(screenHeight / 2) + (int)(data->lineHeight / 2)) * map->step;
		for(int y = data->drawStart; y < data->drawEnd; y++)
		{
			// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
			int texY = (int)map->texPos & (texHeight - 1);
			map->texPos += map->step;
			//map->color = data->txt_ptr[texHeight * texY + texX];
			ft_pix_put(data->m_ptr, x, y, ft_get_pix_color(data->txt_ptr[0].img));
      	
		}
    

		//draw the pixels of the stripe as a vertical line
		// vertical_line(x, data->drawStart, data->drawEnd, color);
		// for(int y = data->drawStart; y <= data->drawEnd; y++)
		// 	ft_pix_put(data->m_ptr, x, y, map->color);
	}

	// FPS
    data->oldTime = data->time;
    data->time = get_actual_time();
	data->frameTime = (data->time - data->oldTime) / 1000.0; //frameTime is the time this frame has taken, in seconds

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

	data->moveSpeed = data->frameTime * 5.0; //the constant value is in squares/second
	data->rotSpeed = data->frameTime * 2.0; //the constant value is in radians/second

	// Control Player Movement
	movePlayer(data);

	printf("Side %d ", data->side - 48);
	printf("PlaneX %f PlaneY %f ", data->planeX, data->planeY);
	printf("POSX %f POSY %f ", data->posX, data->posY);
	printf("DIRX %f DIRY %f\n", data->dirX, data->dirY);

	return(0);
}

void 	get_textures(t_data *d)
{
	d->txt_ptr[0].img = mlx_xpm_file_to_image(d->m_ptr->mlx, d->map_ptr->north_texture, &d->txt_ptr[0].txt_w, &d->txt_ptr[0].txt_h);
	d->txt_ptr[1].img = mlx_xpm_file_to_image(d->m_ptr->mlx, d->map_ptr->south_texture, &d->txt_ptr[1].txt_w, &d->txt_ptr[1].txt_h);
	d->txt_ptr[2].img = mlx_xpm_file_to_image(d->m_ptr->mlx, d->map_ptr->west_texture, &d->txt_ptr[2].txt_w, &d->txt_ptr[2].txt_h);
	d->txt_ptr[3].img = mlx_xpm_file_to_image(d->m_ptr->mlx, d->map_ptr->east_texture, &d->txt_ptr[3].txt_w, &d->txt_ptr[3].txt_h);
}
	
int main()
{
	t_mlx m;
	t_data data;
	t_map map;

	init_t_map(&map);
	data.map_ptr = &map;
	data.posX = 2, data.posY = 2;  //x and y start position
	data.dirX = -1, data.dirY = 0; //initial direction vector
	data.planeX = 0, data.planeY = 0.66; //the 2d raycaster version of camera plane
	data.time = 0; //time of current frame
	data.oldTime = 0; //time of previous frame
	data.fps = 0;
	data.tps = 0.0;
	// data.txt_ptr = malloc(sizeof(t_texture) * 4); 
	// if (!data.txt_ptr)
	// 	return (-1);
	

	data.m_ptr = &m;
	m.data_ptr = &data;

	char *path = "./maps/test.cub"; //av[2]
	map.map_path = path;
	read_map_from_file(&map);

	open_window(&m, screenWidth, screenHeight, "Cube3d IvoJao");

	mlx_hook(m.mlx_win, 2, 1L << 0, &handle_keypress, &m);
	mlx_hook(m.mlx_win, 3, 1L << 1, &handle_keyrelease, &m);
	mlx_hook(m.mlx_win, 17, 0, close_window, &m);
	mlx_loop_hook(m.mlx, render_frames, &data);
	mlx_loop(m.mlx);	
}



void 	ft_print_array(char ** arr, int nb_lines)
{
	for (int i = 0; i < nb_lines; i++)
		printf("%s", arr[i]);
}


/* 
int main()
{
	t_map my_map;
	init_t_map(&my_map);
	char *path = "./maps/test.cub"; //av[2]
	my_map.map_path = path;

	read_map_from_file(&my_map);
	//ft_print_array(my_map.worldMap, my_map.map_length);
	
	
}
 */