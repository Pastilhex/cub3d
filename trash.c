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
