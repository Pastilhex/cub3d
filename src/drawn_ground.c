#include "../includes/cub3d.h"

void	draw_ground(t_mlx m, int color)
{
	int		x;
	int		y;
	
	x = 0;
	y = screenHeight / 2;
	while(y < screenHeight)
	{
		x = 0;
		while(x < screenWidth)
		{
			ft_pix_put(&m, x, y, color);
			x++;
		}
		y++;
	}
}