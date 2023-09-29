/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 09:51:58 by ialves-m          #+#    #+#             */
/*   Updated: 2023/09/29 14:15:01 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include "../gnl/get_next_line.h"
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

typedef struct s_map {
	int		fd;
	int		ttl_nbr_lines;
	int		map_width;
	int		map_length;
	char	*extension;
	char	*get_line;
	char	*map_path;
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	char	*floor_texture;
	char	*ceiling_texture;
	char	**worldMap;
}	t_map;

/*-----> Utils <-----*/
int			ft_atoi(const char *str);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
bool		ft_is_numeric(char *str);
int			ft_strlen(char *str);
char		*ft_strnstr(const char *big, const char *little, size_t len);

/*-----> Cub3d <-----*/
void		open_window(t_mlx *m, int screen_width, int screen_height, char * window_description);
void		ft_pix_put(t_mlx *data, int x, int y, int color);
void		draw_ground(t_mlx m, int color);
void		draw_sky(t_mlx m, int color);
uint64_t	get_actual_time(void);
int	handle_keypress(int keysym, t_mlx *m);
int	close_window(t_mlx *m);


#endif