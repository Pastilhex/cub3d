/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 09:51:58 by ialves-m          #+#    #+#             */
/*   Updated: 2023/10/11 23:57:55 by ialves-m         ###   ########.fr       */
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
# include <fcntl.h>

# define SCREENWIDTH 640
# define SCREENHEIGHT 480
# define TEXWIDTH 64
# define TEXHEIGHT 64

typedef struct s_texture
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			txt_w;
	int			txt_h;
}	t_texture;

typedef struct s_mlx
{
	char			*mlx;
	void			*mlx_win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	struct s_data	*data_ptr;
}	t_mlx;

typedef struct s_rgb
{
	int		r;
	int		g;
	int		b;
}	t_rgb;

typedef struct s_data
{
	int				move_up;
	int				move_down;
	int				move_left;
	int				move_right;
	int				slide_left;
	int				slide_right;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			move_speed;
	double			rot_speed;
	double			move_margin;
	double			time;
	double			old_time;
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	double			old_dir_x;
	double			old_plane_x;
	double			frame_time;
	int				fps;
	double			tps;
	int				tex_x;
	int				pitch;
	t_texture		*txt_ptr;
	struct s_map	*map_ptr;
	t_mlx			*m_ptr;
}	t_data;

typedef struct s_map {
	int			fd;
	int			ttl_nbr_lines;
	char		*extension;
	char		*get_line;
	char		*map_path;
	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;
	char		*floor_texture;
	char		*ceiling_texture;
	char		**world_map;
	double		wall_x;
	double		step;
	double		tex_pos;
	int			tex_y;
	char		start_dir;
	int			nbr;
	int			comma;
	int			rest;
	int			border_begin_x;
	int			border_begin_y;
	int			inside_checked;
	int			map_start;
	int			map_end;
	int			line_nbr;
	int			map_copy_x;
	int			map_copy_y;
	int			has_player;
	t_data		*data_ptr;
	uint32_t	color;
	t_rgb		ceiling_colors;
	t_rgb		floor_colors;
}	t_map;

enum e_direction
{
	south = 0,
	north = 1,
	east = 2,
	west = 3
};

/*-----> Utils <-----*/
int			ft_atoi(const char *str);
char		*ft_itoa(int n);
void		ft_bzero(void *s, size_t n);
char		*ft_strjoin(char *s1, char *s2);
bool		ft_is_numeric(char *str);
int			ft_strlen(char *str);
char		*ft_strnstr(const char *big, const char *little, size_t len);
int			ft_isdigit(int c);
char		**ft_split(char const *s, char c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strdup(char *s);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		free_arr(char **arr, t_map *m);
void		free_arr1(char **arr);
void		ft_put_nbr(long long int nbr, int base, int *len);
int			get_arr_size(char **arr);
bool		is_valid_colors(t_rgb *colors);
bool		is_only_digit_or_comma(char *str);
void		flood_fill(char **arr, int i, int j, char c);
bool		is_valid_char(char c);
bool		is_direction(char c);
char		*ft_strtrim(char *s1, char *set);
char		*ft_strchr(char *s, int c);
char		*ft_substr(char *s, unsigned int start, unsigned int len);
char		*get_next_line(int fd);
void		*ft_calloc(size_t nmemb, size_t size);
void		access_path(t_map *map, char *texture);
void		free_total(char **arr, char *str);
char		**ft_split_set(char *str, char *charset);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strrchr(const char *s, int c);

/*-----> Cub3d <-----*/
void		ft_pixel_put(t_mlx *data, int x, int y, int color);
void		open_window(t_mlx *m, int screen_width, int screen_height, \
	char *window_description);
uint64_t	get_actual_time(void);
int			handle_keypress(int keysym, t_mlx *m);
int			handle_keyrelease(int keysym, t_mlx *m);
int			close_window(t_data *d);
void		init_data(t_data *d, struct s_map *map_ptr, t_mlx *m);
int			render_frames(void *arg);
void		render_frames2(t_data *data, int *x);
void		background(t_mlx m, int ground_color, int sky_color);
void		init_textures_img(t_data *d);
void		init_mlx(t_mlx *m);
void		perror_close(char *msg, t_map *map);
void		perror_close2(char *msg, t_map *map, int fd);
void		check_map_integrity(t_map *map);
int			ft_pixel_get(t_texture *txt, int x, int y);

/*-----> Parser <-----*/
void		read_cub_file(t_map *map);
void		init_t_map(t_map *m, t_data *d);
int			access_file(t_map *map);
bool		check_map_extension(t_map *map, char *filename);
void		get_elements(t_map *map);
void		get_map_size(t_map *map);
void		get_map_to_array(t_map *map);
void		get_ttl_nbr_lines(t_map *map);
int			check_input(int ac, char *path_str, t_map *m);
void		check_map_inside(t_map *map, char **floor, int i, int j);
char		*get_texture(char *line);
void		get_elements_textures(t_map *map, char **line_arr);
void		check_line_for_digit(char *line, char **arr, t_map *m);
int			is_coordinate(char *line);

/*-----> Player Movement <-----*/
void		move_p_up(t_mlx *m);
void		move_p_down(t_mlx *m);
void		move_p_left(t_mlx *m);
void		move_p_right(t_mlx *m);
void		move_p_slide_left(t_mlx *m);
void		move_p_slide_right(t_mlx *m);
void		move_player(t_data *data);

/*-----> Debug <-----*/
void		ft_print_array(char **arr, int nb_lines);
void		t_print_t_map(t_map *m);

#endif