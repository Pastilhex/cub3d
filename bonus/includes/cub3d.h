/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 09:51:58 by ialves-m          #+#    #+#             */
/*   Updated: 2023/10/27 16:06:20 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define SCREENWIDTH 1280
# define SCREENHEIGHT 960
# define TEXWIDTH 64
# define TEXHEIGHT 64

typedef struct s_texture
{
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
	int					txt_w;
	int					txt_h;
}						t_texture;

typedef struct s_mlx
{
	char				*mlx;
	void				*mlx_win;
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
	struct s_data		*data_ptr;
}						t_mlx;

typedef struct s_rgb
{
	int					r;
	int					g;
	int					b;
}						t_rgb;

typedef struct s_sprite
{
	int					x;
	int					y;
	t_texture			*txt;
}						t_sprite;

typedef struct sprite_list
{
	int					order;
	int					distance;
	struct sprite_list	*next;
	struct sprite_list	*previous;
}						t_s_list;

typedef struct s_minimap
{
	double				start_x;
	double				start_y;
	double				end_x;
	double				end_y;
	int					x;
	int					y;
	int					world_map_size;
	char				**big_map;
}						t_minimap;

typedef struct s_miniplayer
{
	int					i_center;
	int					j_center;
	int					pl_radius;
	int					line_length;
	int					dx;
	int					dy;
	int					sx;
	int					sy;
	int					err;
	int					e2;
	int					x2;
	int					y2;
}						t_miniplayer;

typedef struct s_rend_sprite
{
	int					x;
	int					y;
	int					d;
	double				sprite_x;
	double				sprite_y;
	double				inv_det;
	double				transform_x;
	double				transform_y;
	int					sprite_screen_x;
	int					sprite_height;
	int					sprite_width;
	int					draw_start_y;
	int					draw_end_y;
	int					draw_start_x;
	int					draw_end_x;
	int					stripe;
	int					tex_y;

}						t_rend_sprite;

typedef struct s_data
{
	int					door_state;
	int					press_space;
	int					move_up;
	int					move_down;
	int					move_left;
	int					move_right;
	int					slide_left;
	int					slide_right;
	double				pos_x;
	double				pos_y;
	double				dir_x;
	double				dir_y;
	double				plane_x;
	double				plane_y;
	double				move_speed;
	double				rot_speed;
	double				move_margin;
	double				time;
	double				old_time;
	double				camera_x;
	double				ray_dir_x;
	double				ray_dir_y;
	int					map_x;
	int					map_y;
	double				side_dist_x;
	double				side_dist_y;
	double				delta_dist_x;
	double				delta_dist_y;
	double				perp_wall_dist;
	int					step_x;
	int					step_y;
	int					hit;
	int					side;
	int					line_height;
	int					draw_start;
	int					draw_end;
	double				old_dir_x;
	double				old_plane_x;
	double				frame_time;
	double				wallXOffset;
	double				wallYOffset;
	int					fps;
	double				tps;
	int					tex_x;
	int					pitch;
	int					swap_img;
	int					swap_hands;
	int					close_door;
	int					open_door;
	double				z_buffer[SCREENWIDTH];
	// char				**big_map_copy;
	t_s_list			*head;
	t_s_list			*temp_head;
	t_texture			*txt_ptr;
	t_texture			*txt_head;
	t_texture			*txt_hands;
	t_texture			*txt_door;
	struct s_map		*map_ptr;
	struct s_draw		*draw_ptr;
	t_mlx				*m_ptr;
	t_rend_sprite		*t_rend_ptr;
	t_minimap			*mini_map_ptr;
}						t_data;

typedef struct s_map
{
	int					fd;
	int					ttl_nbr_lines;
	char				*extension;
	char				*get_line;
	char				*map_path;
	char				*north_texture;
	char				*south_texture;
	char				*west_texture;
	char				*east_texture;
	char				*floor_texture;
	char				*ceiling_texture;
	char				**world_map;
	char				*hud_texture;
	char				*eagle_wall_texture;
	char				*flag_wall_texture;
	char				*blue1_wall_texture;
	char				*blue2_wall_texture;
	char				*blueskeleton_wall_texture;
	char				*blueempty_wall_texture;
	char				*ceilinglamp_texture;
	char				*barrel_texture;
	char				*hands;
	char				*door_texture;
	char				*soldier_texture;
	char				*bed_texture;
	char				*redflag_texture;
	char				*hangskeleton_texture;
	char				*kitchenware_texture;
	char				*oven_texture;
	char				*pilar_texture;
	char				*table_texture;
	char				*weapons_texture;
	char				*knight_texture;
	char				*bush_texture;
	char				*groundlamp_texture;
	char				*lamp_texture;
	char				*sink_texture;
	char				**animated_head;
	char				**animated_hands;
	char				**animated_door;
	char				*miniplayer_texture;
	double				wall_x;
	double				step;
	double				tex_pos;
	int					tex_y;
	char				start_dir;
	int					nbr;
	int					comma;
	int					rest;
	int					border_begin_x;
	int					border_begin_y;
	int					inside_checked;
	int					map_start;
	int					map_end;
	int					larger_line;
	int					line_nbr;
	int					map_copy_x;
	int					map_copy_y;
	int					has_player;
	double				sprite_x;
	double				sprite_y;
	int					sprites_nb;
	int					sprite_index;
	int					*sprite_order;
	int					*sprite_distance;
	time_t				start_time_head;
	time_t				start_time_hand;
	time_t				start_time_door;
	time_t				current_time;
	t_data				*data_ptr;
	t_sprite			*sprite_arr;
	uint32_t			color;
	t_rgb				ceiling_colors;
	t_rgb				floor_colors;
}						t_map;

typedef struct s_draw
{
	int					*x;
	int					y;
	int					tex_y;
	int					wall;
}						t_draw;

typedef struct s_aux
{
	int					i;
	int					j;
	double				a;
	double				b;
	double				begin_i;
	double				begin_j;
}						t_aux;

enum					e_direction
{
	south = 0,
	north = 1,
	east = 2,
	west = 3,
	hud = 4,
	eagle = 5,
	flag = 6,
	blue1 = 7,
	blue2 = 8,
	blueskeleton = 9,
	blueempty = 10,
	ceilinglamp = 11,
	barrel = 12,
	miniplayer = 13,
	soldier = 14,
	bed = 15,
	redflag = 16,
	hangskeleton = 17,
	kitchenware = 18,
	oven = 19,
	pilar = 20,
	table = 21,
	weapons = 22,
	knight = 23,
	bush = 24,
	groundlamp = 25,
	lamp = 26,
	sink = 27,
};

/*-----> Bonus <-----*/
void					init_bonus(t_map *map, t_data *d);
void					draw_hud(t_data *data);
void					draw_hands(t_data *data);
void					draw_head_hud(t_data *data);
void					img_head(t_data *d);
void					img_hands(t_data *d);
int						handle_mouse(int x, int y, t_data *d);
int						handle_mouse_fire(int button, int x, int y, t_data *d);
void					create_big_map(t_data *d);
void					draw_square(char c, t_data *d, int x, int y);
void					draw_circle(t_mlx *mlx, int x, int y, int radius);
void					init_t_miniplayer(t_miniplayer *mp);
void					draw_line(t_data *d, t_miniplayer mp, int x2, int y2);
void					draw_miniplayer(t_data *d);
void					init_t_minimap(t_minimap *mm, t_data *d);
void					get_minimap(t_data *d);
void					set_larger_line(t_data *d);
void					fill_5_lines(t_data *d, int i, int end);
char					*fill_end(int size);
void					add_spaces(t_data *d);
void					get_minimap(t_data *d);
void					init_t_rend(t_rend_sprite *r);
void					draw_hands(t_data *data);
void					draw_head_hud(t_data *data);
void					draw_hud(t_data *data);
void					draw_sprites(t_data *data, t_map *m, t_rend_sprite *r);
void					draw_wall(t_data *d, char c, t_texture *txt_ns,
							t_texture *txt_we);
void					draw_doors(t_data *d, int *x);
void					calculate_cols(t_data *data);
void					calc_doors(t_data *data, int *x);
void					img_head(t_data *d);
void					img_hands(t_data *d);
void					new_img(t_data *d, enum e_direction var, char *txt);
void					img_door(t_data *d);
void					init_textures_extra_img(t_data *d);
void					init_extra_bonus(t_map *map, t_data *d);
void					set_sprite_extra(t_map *m, int i, int j, char c);
int						allowed_sprites(int c);
bool					dont_hit(t_data *data);
void					check_hit_doors(t_data *data);
void					door_animation(t_data *d);



/*-----> Utils <-----*/
int						ft_atoi(const char *str);
char					*ft_itoa(int n);
void					ft_bzero(void *s, size_t n);
char					*ft_strjoin(char *s1, char *s2);
bool					ft_is_numeric(char *str);
int						ft_strlen(char *str);
char					*ft_strnstr(const char *big, const char *little,
							size_t len);
int						ft_isdigit(int c);
char					**ft_split(char const *s, char c);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
char					*ft_strdup(char *s);
void					*ft_memcpy(void *dest, const void *src, size_t n);
void					free_arr(char **arr, t_map *m);
void					free_arr1(char **arr);
void					free_arr2(char **arr, int size);
void					ft_put_nbr(long long int nbr, int base, int *len);
int						get_arr_size(char **arr);
bool					is_valid_colors(t_rgb *colors);
bool					is_only_digit_or_comma(char *str);
void					flood_fill(char **arr, int i, int j, char c);
bool					is_valid_char(char c);
bool					is_direction(char c);
char					*ft_strtrim(char *s1, char *set);
char					*ft_strchr(char *s, int c);
char					*ft_substr(char *s, unsigned int start,
							unsigned int len);
char					*get_next_line(int fd);
void					*ft_calloc(size_t nmemb, size_t size);
void					access_path(t_map *map, char *texture);
void					free_total(char **arr, char *str);
char					**ft_split_set(char *str, char *charset);
int						ft_strcmp(char *s1, char *s2);
char					*ft_strjoin2(char *s1, char *s2);
void					fps(t_data *data);
int						get_rgb(int r, int g, int b);


/*-----> Cub3d <-----*/
void					ft_pixel_put(t_mlx *data, int x, int y, int color);
void					open_window(t_mlx *m, int screen_width,
							int screen_height, char *window_description);
uint64_t				get_actual_time(void);
int						handle_keypress(int keysym, t_mlx *m);
int						handle_keyrelease(int keysym, t_mlx *m);
int						close_window(t_data *d);
void					init_data(t_data *d, struct s_map *map_ptr, t_mlx *m);
int						render_frames(void *arg);
void					draw_walls(t_data *data, int *x);
void					background(t_mlx m, int ground_color, int sky_color);
void					init_textures_img(t_data *d);
void					init_mlx(t_mlx *m);
void					perror_close(char *msg, t_map *map);
void					perror_close2(char *msg, t_map *map, int fd);
void					check_map_integrity(t_map *map);
int						ft_pixel_get(t_texture *txt, int x, int y);

/*-----> Parser <-----*/
void					read_cub_file(t_map *map);
void					init_t_map(t_map *m, t_data *d);
int						access_file(t_map *map);
bool					check_map_extension(t_map *map, char *filename);
void					get_elements(t_map *map);
void					get_map_size(t_map *map);
void					get_map_to_array(t_map *map);
void					get_ttl_nbr_lines(t_map *map);
int						check_input(int ac, char *path_str, t_map *m);
void					check_map_inside(t_map *map, char **floor, int i,
							int j);
char					*get_texture(char *line);
void					get_elements_textures(t_map *map, char **line_arr);
void					check_line_for_digit(char *line, char **arr, t_map *m);
int						is_coordinate(char *line);
bool					is_sprite(char c);
void					set_start(double i, double k, char c, t_map *m);

/*-----> Player Movement <-----*/
void					move_p_up(t_mlx *m);
void					move_p_down(t_mlx *m);
void					move_p_left(t_mlx *m);
void					move_p_right(t_mlx *m);
void					move_p_slide_left(t_mlx *m);
void					move_p_slide_right(t_mlx *m);
void					move_player(t_data *data);

/*-----> Linked listt <-----*/
t_s_list				*creat_node(t_data *d, int x);
t_s_list				*find_tail(t_s_list **stack);
t_s_list				*add_element_back(t_s_list *head, t_data *d, int x);
void					print_list(t_s_list *head);
void					order_list(t_s_list **head);
void					clear_list(t_s_list *node);

/*-----> Debug <-----*/
void					ft_print_array(char **arr, int nb_lines);
void					ft_print_t_map(t_map *m);

#endif
