/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 09:51:58 by ialves-m          #+#    #+#             */
/*   Updated: 2023/09/28 20:48:38 by joaoalme         ###   ########.fr       */
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
# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>
# include <stdint.h>


# define screenWidth 640
# define screenHeight 480
# define mapWidth 24
# define mapHeight 24
# define BLUE 0x0000FF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define WHITE 0xFFFFFF
# define YELLOW 0xFFFF00
# define BLACK 0x000000
# define CUSTOM 0x00FFFF


typedef struct s_mlx 
{
	char			*mlx;
	void			*mlx_win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	struct	s_data	*data_ptr;
}	t_mlx;

typedef	struct s_data
{
	int	(*worldMap_ptr)[mapWidth][mapHeight];
    double	posX;		// Posição X do jogador
    double	posY;		// Posição Y do jogador
    double	dirX;		// Direção X do jogador
    double	dirY;		// Direção Y do jogador
    double	planeX;		// Plano X da câmera
    double	planeY;		// Plano Y da câmera
    double	moveSpeed;	// Velocidade de movimento
    double	rotSpeed;	// Velocidade de rotação
    double	time;		//time of current frame
    double	oldTime;	//time of previous frame
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	int		mapX;
	int		mapY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	int		stepX;
	int		stepY;
	int		hit; //was there a wall hit?
	int		side; //was a NS or a EW wall hit?
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	double	oldDirX;
	double	oldPlaneX;
	double	frameTime;
	int		fps;
	double	tps;
	t_mlx	*m_ptr;
}	t_data;


void		open_window(t_mlx *m, int screen_width, int screen_height, char * window_description);
void		ft_pix_put(t_mlx *data, int x, int y, int color);
void		draw_ground(t_mlx m, int color);
void		draw_sky(t_mlx m, int color);
uint64_t	get_actual_time(void);

void back2(t_mlx m);
void back1(t_mlx m);


int	handle_keypress(int keysym, t_mlx *m);
int	close_window(t_mlx *m);


#endif