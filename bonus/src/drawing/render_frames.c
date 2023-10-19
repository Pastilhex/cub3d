/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frames.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:11:26 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/19 19:1:03 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	render_frames1(t_data *data, int *x)
{
	data->camera_x = 2 * *x / (double)SCREENWIDTH - 1;
	data->ray_dir_x = data->dir_x + data->plane_x * data->camera_x;
	data->ray_dir_y = data->dir_y + data->plane_y * data->camera_x;
	data->map_x = (int)data->pos_x;
	data->map_y = (int)data->pos_y;
	if (data->ray_dir_x == 0)
		data->delta_dist_x = 1e30;
	else
		data->delta_dist_x = fabs(1.0 / data->ray_dir_x);
	if (data->ray_dir_y == 0)
		data->delta_dist_y = 1e30;
	else
		data->delta_dist_y = fabs(1.0 / data->ray_dir_y);
	data->hit = '0';
	if (data->ray_dir_x < 0)
	{
		data->step_x = -1;
		data->side_dist_x = (data->pos_x - data->map_x) * data->delta_dist_x;
	}
	else
	{
		data->step_x = 1;
		data->side_dist_x = (data->map_x + 1.0 - data->pos_x) * \
			data->delta_dist_x;
	}
}

static void	fps(t_data *data)
{
	data->old_time = data->time;
	data->time = get_actual_time();
	data->frame_time = (data->time - data->old_time) / 1000.0;
	if (data->tps <= 1.0)
	{
		data->fps++;
		data->tps += data->frame_time;
	}
	else
	{
		// printf("FPS: %d\n", data->fps);
		data->fps = 0;
		data->tps = 0.0;
	}
}

int	get_rgb(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

void	init_t_rend(t_rend_sprite *r)
{
	r->x = 0;
	r->y = 0;
	r->d = 0;
	r->sprite_x = 0.0;
	r->sprite_y = 0.0;
	r->inv_det = 0.0;
	r->transform_x = 0.0;
	r->transform_y = 0.0;
	r->sprite_screen_x = 0;
	r->sprite_height = 0;
	r->sprite_width = 0;
	r->draw_start_y = 0;
	r->draw_end_y = 0;
	r->draw_start_x = 0;
	r->draw_end_x = 0;
	r->stripe = 0;
	r->tex_y = 0;
}

void	calc_sprites(t_map *m, t_data *data, t_rend_sprite *r)
{
	r->x = 0;
	m->sprite_x = m->sprite_arr[data->head->order].x;
	m->sprite_y = m->sprite_arr[data->head->order].y;
	r->sprite_x = m->sprite_x - data->pos_x + 0.5;
	r->sprite_y = m->sprite_y - data->pos_y + 0.5;
	r->inv_det = 1.0 / (data->plane_x * data->dir_y - data->dir_x * data->plane_y);
	r->transform_x = r->inv_det * (data->dir_y * r->sprite_x - data->dir_x * r->sprite_y);
	r->transform_y = r->inv_det * (-data->plane_y * r->sprite_x + data->plane_x * r->sprite_y); 
	r->sprite_screen_x = (int)((SCREENWIDTH / 2.0) * (1 + r->transform_x / r->transform_y));
	r->sprite_height = abs((int)(SCREENHEIGHT / r->transform_y));
	r->draw_start_y = -r->sprite_height / 2 + SCREENHEIGHT / 2;
	if (r->draw_start_y < 0)
		r->draw_start_y = 0;
	r->draw_end_y = r->sprite_height / 2 + SCREENHEIGHT / 2;
	if (r->draw_end_y >= SCREENHEIGHT)
		r->draw_end_y = SCREENHEIGHT - 1;
	r->sprite_width = abs((int)(SCREENWIDTH / r->transform_y));
	r->draw_start_x = -r->sprite_width / 2 + r->sprite_screen_x;
	if (r->draw_start_x < 0)
		r->draw_start_x = 0;
	r->draw_end_x = r->sprite_width / 2 + r->sprite_screen_x;
	if(r->draw_end_x >= SCREENWIDTH)
		r->draw_end_x = SCREENWIDTH - 1;
	r->stripe = r->draw_start_x;
}

void	rend_sprites(t_map *m, t_data *data, t_rend_sprite *r)
{
	data->tex_x = (int)(256 * (r->stripe - (-r->sprite_width / 2 + r->sprite_screen_x)) * TEXWIDTH / r->sprite_width) / 256;
	if ((r->transform_y > 0 && r->stripe > 0 && r->stripe < SCREENWIDTH && r->transform_y < data->z_buffer[r->stripe]))
	{
		r->y = r->draw_start_y;
		while (r->y < r->draw_end_y)
		{
			r->d = r->y * 256 - SCREENHEIGHT * 128 + r->sprite_height * 128;
			r->tex_y = ((r->d * TEXHEIGHT) / r->sprite_height) / 256;
			ft_pixel_put(data->m_ptr, r->stripe, r->y, (unsigned int)ft_pixel_get(m->sprite_arr[data->head->order].txt, data->tex_x, r->tex_y));
			r->y++;
		}
	}
	r->stripe++;	
}
// void	init_t_minimap(t_minimap *mm)
// {
// 	mm->start_x = 0.0;
// 	mm->start_y = 0.0;
// 	mm->end_x = 0.0;
// 	mm->end_y = 0.0;
// 	mm->x = 0;
// 	mm->y = 0;
// }
void	set_larger_line(t_data *d)
{
	int	i;
	
	i = 0;
	while (i < d->map_ptr->map_end - d->map_ptr->map_start)
	{
		if(ft_strlen(d->map_ptr->world_map[i]) > d->map_ptr->larger_line)
			d->map_ptr->larger_line = ft_strlen(d->map_ptr->world_map[i]);
		i++;
	}
}

void	fill_5_lines(t_data *d, int i, int end)
{
	int		j;
	int		len;

	len = d->map_ptr->larger_line + 21;
	while (i < end)
	{
		d->mini_map_ptr->big_map[i] = malloc(sizeof(char) * len);
		j = 0;
		while (j < len - 1)
		{
			d->mini_map_ptr->big_map[i][j] = '#';
			j++;
		}
		d->mini_map_ptr->big_map[i][j] = '\0';
		i++;
	}
}

char	 *fill_end(int size)
{
	char	*s;
	int		i;

	s = malloc(sizeof(char) * size + 1 );
	i = 0;
	while (i < size)
	{
		s[i] = '*';
		i++;
	}
	s[i] = '\0';
	return(s);
}

	
void	add_spaces(t_data *d)
{
	int	i;
	char	 *s;
	int		space_diff;
	char	*s_end;
	char	*temp;
	
	fill_5_lines(d, 0, 5);
	s = "**********";
	i = 5;
	while (i < (d->map_ptr->map_end - d->map_ptr->map_start) + 5)
	{
		temp = ft_strjoin2(s, ft_strtrim(d->map_ptr->world_map[i - 5], "\n"));
		space_diff = (d->map_ptr->larger_line + 20) - ft_strlen(temp);
		s_end = fill_end(space_diff);
		d->mini_map_ptr->big_map[i] = ft_strjoin(temp, s_end);
		i++;
		// free(temp);
		free(s_end);
	}
	fill_5_lines(d, i, d->map_ptr->map_end - d->map_ptr->map_start + 10);
}

void	copy_large_world_map(t_data *d)
{
	set_larger_line(d);
	add_spaces(d);
	
}

void	draw_square(char c, t_data *d, int x, int y)
{
	unsigned int	color;
	int				x_end;
	int				y_end;
	int				start_y;

	(void)		c;
	x_end = x + (0.0125 * SCREENHEIGHT);
	y_end = y + (0.009375 * SCREENWIDTH);
	start_y = y;
	color = 0xA4A4A4;
	if (c != '0')
		color = 0x646464;
	while (x < x_end)
	{
		y = start_y;
		while (y < y_end)
		{
			ft_pixel_put(d->m_ptr, y, x, color);
			y++;
		}
		x++;
	}
}
void	draw_miniplayer(t_data *data)
{
	int		i;
	int		j;
	double	a;
    double	b;
    double	begin_i;
    double	begin_j;

    a = 6 / ((double) SCREENWIDTH / 106.666666667);
    b = (6 / ((double) SCREENHEIGHT / 80));
    begin_i = (SCREENWIDTH * 0.86875);
    begin_j = (SCREENHEIGHT * 0.9125);

	i = SCREENWIDTH * 0.86875;
	while (i < SCREENWIDTH * 0.878125)
	{
		j = SCREENHEIGHT * 0.9125;
		while (j < SCREENHEIGHT * 0.925)
		{
			ft_pixel_put(data->m_ptr, i, j, (unsigned int)ft_pixel_get(&data->txt_ptr[miniplayer], (int)((i - begin_i) * a), (int)((j - begin_j) * b)));
			j++;
		}
		i++;
	}
}


void	get_minimap(t_data *d)
{	
		t_minimap mm;

		d->mini_map_ptr = &mm;
		mm.start_x = d->pos_x;
		mm.end_x = d->pos_x + 10 + 10;
		mm.start_y = d->pos_y;
		mm.end_y = d->pos_y + 5 + 5;
		mm.x = ((double)SCREENHEIGHT * 0.85);
		mm.big_map = ft_calloc((d->map_ptr->map_end - d->map_ptr->map_start + 10), sizeof(char *));
		copy_large_world_map(d);
		// ft_print_array(d->mini_map_ptr->big_map, d->map_ptr->map_end - d->map_ptr->map_start + 10);
		while (mm.start_x <= d->pos_x + 10)
		{	
			mm.start_y = d->pos_y;
			mm.y = SCREENWIDTH * 0.775;
			while(mm.start_y <= d->pos_y + 20)
			{
				draw_square(mm.big_map[(int)mm.start_x][(int)mm.start_y], d, mm.x, mm.y);
				mm.start_y++;
				mm.y += 0.009375 * SCREENWIDTH;
			}
			mm.start_x++;
			mm.x += (0.0125 * SCREENHEIGHT);
		}
		free_arr2(d->mini_map_ptr->big_map, d->map_ptr->map_end - d->map_ptr->map_start + 10);
		draw_miniplayer(d);
}

void	main_render(t_map *m, t_data *data, t_rend_sprite *r)
{
	t_s_list *head2;
	
	r->x = 0;
	while (r->x < SCREENWIDTH)
	{
		render_frames1(data, &r->x);
		render_frames2(data, &r->x);
		data->z_buffer[r->x] = data->perp_wall_dist;
		r->x++;
	}
	r->x = 0;
	data->head = creat_node(data, r->x);
	head2 = data->head;
	while (++r->x < m->sprites_nb )
		add_element_back(data->head, data, r->x);
	order_list(&data->head);
	while (data->head != NULL)
	{
		calc_sprites(m, data, r);
		while (r->stripe < r->draw_end_x)
			rend_sprites(m, data, r);
		data->head = data->head->next;
	}
	clear_list(head2);
	draw_hands(data);
	draw_hud(data);
	draw_head_hud(data);
	get_minimap(data);	
}


int	render_frames(void *arg)
{
	t_data			*data;
	t_rgb			*sky;
	t_rgb			*floor;
	t_map			*m;
	t_rend_sprite	*r;

	r = (t_rend_sprite *) malloc(sizeof(t_rend_sprite));
	init_t_rend(r);
	data = arg;
	data->t_rend_ptr = r;
	m = data->map_ptr;
	sky = &data->map_ptr->ceiling_colors;
	floor = &data->map_ptr->floor_colors;
	background(*data->m_ptr, get_rgb(sky->r, sky->g, sky->b), \
		get_rgb(floor->r, floor->g, floor->b));
	main_render(m, data, r);
	mlx_put_image_to_window(data->m_ptr->mlx, \
	data->m_ptr->mlx_win, data->m_ptr->img, 0, 0);
	fps(data);
	data->move_speed = data->frame_time * 3;
	if (m->data_ptr->move_left == 1 || m->data_ptr->move_right == 1)
		data->rot_speed = data->frame_time * 2.75;
	else
		data->rot_speed = data->frame_time * 1;
	data->move_margin = 0.4;
	move_player(data);
	free(r);
	return (0);
}

