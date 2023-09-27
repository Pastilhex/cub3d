/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 09:51:58 by ialves-m          #+#    #+#             */
/*   Updated: 2023/09/27 13:56:34 by ialves-m         ###   ########.fr       */
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

typedef struct s_mlx {
	char	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} t_mlx;


void	open_window(t_mlx *m, int screen_width, int screen_height, char * window_description);

int	handle_keypress(int keysym, t_mlx *m);
int	close_window(t_mlx *m);


#endif