// draw_line(m.mlx, m.mlx_win, m.img, screenWidth, screenHeight, 0, 0, 0xFFFFFF);
// int draw_line(void *mlx, void *win, void *img, int beginX, int beginY, int endX, int endY, int color)
// {
// 	double deltaX = endX - beginX; // -640 = 0 - 640
// 	double deltaY = endY - beginY; // -480 = 0 - 480
	
// 	int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
// 	// = sqrt((-640 * -640) + (-480 * -480))
// 	// = sqrt(409600 + 230400)
// 	// = 800

// 	deltaX /= pixels; // 640 / 800 = 0.8
// 	deltaY /= pixels; // 480 / 800 = 0.6

// 	double pixelX = beginX; // 640
// 	double pixelY = beginY; // 480

// 	while (pixels)
// 	{
// 		mlx_pixel_put(mlx, win, pixelX, pixelY, color);
// 		printf("PixelX: %.2f\nPixelY: %.2f\n", pixelX, pixelY);
// 		usleep(10000);
// 		pixelX += deltaX;
// 		pixelY += deltaY;
// 		--pixels;
// 	}
// 	return (0);
// }


// if (data->moveUp == 1 && data->moveLeft == 1 && data->slideLeft == 1)
// {
// 	moveUp(data->m_ptr);
// 	moveLeft(data->m_ptr);
// 	moveSlideLeft(data->m_ptr);
// }
// else if (data->moveUp == 1 && data->moveRight == 1 && data->slideLeft == 1)
// {
// 	moveUp(data->m_ptr);
// 	moveRight(data->m_ptr);
// 	moveSlideLeft(data->m_ptr);
// }
// if (data->moveUp == 1 && data->moveLeft == 1 && data->slideRight == 1)
// {
// 	moveUp(data->m_ptr);
// 	moveLeft(data->m_ptr);
// 	moveSlideRight(data->m_ptr);
// }
// else if (data->moveUp == 1 && data->moveRight == 1 && data->slideRight == 1)
// {
// 	moveUp(data->m_ptr);
// 	moveRight(data->m_ptr);
// 	moveSlideRight(data->m_ptr);
// }

// else if (data->moveDown == 1 && data->moveLeft == 1 && data->slideLeft == 1)
// {
// 	moveDown(data->m_ptr);
// 	moveLeft(data->m_ptr);
// 	moveSlideLeft(data->m_ptr);
// }
// else if (data->moveDown == 1 && data->moveRight == 1 && data->slideLeft == 1)
// {
// 	moveDown(data->m_ptr);
// 	moveRight(data->m_ptr);
// 	moveSlideLeft(data->m_ptr);
// }
// if (data->moveDown == 1 && data->moveLeft == 1 && data->slideRight == 1)
// {
// 	moveDown(data->m_ptr);
// 	moveLeft(data->m_ptr);
// 	moveSlideRight(data->m_ptr);
// }
// else if (data->moveDown == 1 && data->moveRight == 1 && data->slideRight == 1)
// {
// 	moveDown(data->m_ptr);
// 	moveRight(data->m_ptr);
// 	moveSlideRight(data->m_ptr);
// }

// else if (data->moveUp == 1 && data->moveLeft == 1)
// {
// 	moveUp(data->m_ptr);
// 	moveLeft(data->m_ptr);
// }
// else if (data->moveUp == 1 && data->moveRight == 1)
// {
// 	moveUp(data->m_ptr);
// 	moveRight(data->m_ptr);
// }
// else if (data->moveDown == 1 && data->moveLeft == 1)
// {
// 	moveDown(data->m_ptr);
// 	moveLeft(data->m_ptr);
// }
// else if (data->moveDown == 1 && data->moveRight == 1)
// {
// 	moveDown(data->m_ptr);
// 	moveRight(data->m_ptr);
// }
// else if (data->moveUp == 1 && data->slideLeft)
// {
// 	moveUp(data->m_ptr);
// 	moveSlideLeft(data->m_ptr);
// }
// else if (data->moveUp == 1 && data->slideRight)
// {
// 	moveUp(data->m_ptr);
// 	moveSlideRight(data->m_ptr);
// }
// else if (data->moveDown == 1 && data->slideLeft)
// {
// 	moveDown(data->m_ptr);
// 	moveSlideLeft(data->m_ptr);
// }
// else if (data->moveDown == 1 && data->slideRight)
// {
// 	moveDown(data->m_ptr);
// 	moveSlideRight(data->m_ptr);
// }
// else if (data->moveUp == 1)
// 	moveUp(data->m_ptr);
// else if (data->moveDown == 1)
// 	moveDown(data->m_ptr);
// else if (data->moveLeft == 1)
// 	moveLeft(data->m_ptr);
// else if (data->moveRight == 1)
// 	moveRight(data->m_ptr);
// else if (data->slideLeft == 1)
// 	moveSlideLeft(data->m_ptr);
// else if (data->slideRight == 1)
// 	moveSlideRight(data->m_ptr);

/*
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

		
		int pitch = 10;

		//calculate lowest and highest pixel to fill in current stripe
		data->drawStart = -data->lineHeight / 2 + screenHeight / 2 + pitch;
		
		if(data->drawStart < 0)
			data->drawStart = 0;
		
		data->drawEnd = data->lineHeight / 2 + screenHeight / 2 + pitch;
		if(data->drawEnd >= screenHeight)
			data->drawEnd = screenHeight - 1;



		//calculate value of wallX
		if (data->side == '0')
			map->wallX = data->posY + data->perpWallDist * data->rayDirY; //where exactly the wall was hit
		else
			map->wallX = data->posX + data->perpWallDist * data->rayDirX; //where exactly the wall was hit
		map->wallX -= floor((map->wallX));

		// int wallColor = map->worldMap[data->mapX][data->mapY];

		// x coordinate on the texture
		int texX = (int)(map->wallX * (double)texWidth);
		if(data->side == '0' && data->rayDirX > 0)
			texX = texWidth - texX - 1;
		if(data->side == '1' && data->rayDirY < 0)
			texX = texWidth - texX - 1;
		// if(data->side == '0' && data->rayDirX < 0)
		// 	texX = texWidth - texX - 1;
		// if(data->side == '1' && data->rayDirY > 0)
		// 	texX = texWidth - texX - 1;

		// How much to increase the texture coordinate per screen pixel
		map->step = 1.0 * texHeight / data->lineHeight;
		
		map->texPos = (data->drawStart - pitch - (double)screenHeight / 2 + (double)data->lineHeight / 2) * map->step;
		for (int y = data->drawStart; y < data->drawEnd; y++)
		{
			int texY = (int)map->texPos & (texHeight - 1);  //(texHeight - 1)
			map->texPos += map->step;
			if (data->side == '0' && data->rayDirX > 0)
				ft_pixel_put(data->m_ptr, x, y, ft_pixel_get(&data->txt_ptr[south], texX, texY));
			else if (data->side == '0' && data->rayDirX < 0)
				ft_pixel_put(data->m_ptr, x, y, ft_pixel_get(&data->txt_ptr[1], texX, texY));
			else if (data->side == '1' && data->rayDirY > 0)
				ft_pixel_put(data->m_ptr, x, y, ft_pixel_get(&data->txt_ptr[2], texX, texY));
			else if (data->side == '1' && data->rayDirY < 0)
				ft_pixel_put(data->m_ptr, x, y, ft_pixel_get(&data->txt_ptr[3], texX, texY));
		}
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

static void     draw_ground(t_mlx m, int color)
{
	int		x;
	int		y;
	
	x = 0;
	y = screenHeight / 2;
	while (y < screenHeight)
	{
		x = 0;
		while (x < screenWidth)
		{
			ft_pixel_put(&m, x, y, color);
			x++;
		}
		y++;
	}
}

static void     draw_sky(t_mlx m, int color)
{
	int		x;
	int		y;
	
	x = 0;
	y = 0;
	while (y < screenHeight / 2)
	{
		x = 0;
		while (x < screenWidth)
		{
			ft_pixel_put(&m, x, y, color);
			x++;
		}
		y++;
	}
}

*/
/*
void	get_elements(t_map *map)
{
	char	**line_arr;
	
	while (map->get_line)
	{
		line_arr = ft_split(map->get_line, ' ');
		if (!map->north_texture)
			if (!ft_strncmp("N", line_arr[0], 2) || !ft_strncmp("NO", line_arr[0], 3))
				map->north_texture = ft_strdup(line_arr[1]);
		if (!map->south_texture)
			if (!ft_strncmp("S", line_arr[0], 2) || !ft_strncmp("SO", line_arr[0], 3))
				map->south_texture = ft_strdup(line_arr[1]);
		if (!map->west_texture)
			if (!ft_strncmp("W", line_arr[0], 2) || !ft_strncmp("WE", line_arr[0], 3))
				map->west_texture = ft_strdup(line_arr[1]);
		if (!map->east_texture)
			if (!ft_strncmp("E", line_arr[0], 2) || !ft_strncmp("EA", line_arr[0], 3))
				map->east_texture = ft_strdup(line_arr[1]);
		if (!map->ceiling_texture)
			if (!ft_strncmp("C", line_arr[0], 2))
				map->ceiling_texture = ft_strdup(line_arr[1]);
		if (!map->floor_texture)
			if (!ft_strncmp("F", line_arr[0], 2))
				map->floor_texture = ft_strdup(line_arr[1]);
		if (map->north_texture && map->south_texture && map->west_texture && map->east_texture && map->ceiling_texture && map->floor_texture)
			break ;
		map->get_line = get_next_line(map->fd);
	}
}*/