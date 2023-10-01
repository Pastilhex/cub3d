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
