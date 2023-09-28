#include "../includes/cub3d.h"

void	ft_pix_put(t_mlx *m, int x, int y, int color)
{
	char	*dst;

	dst = m->addr + (y * m->line_length + x * (m->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}