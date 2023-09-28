/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 09:51:58 by ialves-m          #+#    #+#             */
/*   Updated: 2023/09/27 20:58:21 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <X11/X.h>

# define screenWidth 640
# define screenHeight 480
# define mapWidth 24
# define mapHeight 24
# define BLUE 0x0000FF
# define RED 0xFF0000
# define GREEN 0x00FF00

typedef struct s_mlx 
{
	char	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_mlx;

/*unused for now*/
// typedef	struct s_win_data
// {
// 	int s_width;
// 	int s_height;
// }		t_win_data;



void	open_window(t_mlx *m, int screen_width, int screen_height, char * window_description);
void	ft_pix_put(t_mlx *data, int x, int y, int color);
void	draw_ground(t_mlx m, int color);
void	draw_sky(t_mlx m, int color);


int	handle_keypress(int keysym, t_mlx *m);
int	close_window(t_mlx *m);


#endif