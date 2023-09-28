#include "../includes/cub3d.h"

void	draw_sky(t_mlx m, int color)
{
	int		x;
	int		y;
	
	x = 0;
	y = 0;
	while(y < screenHeight / 2)
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