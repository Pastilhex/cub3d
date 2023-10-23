/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:55:59 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/23 20:02:58 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void calc_sprites2(t_rend_sprite *r)
{
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

static void calc_sprites(t_map *m, t_data *data, t_rend_sprite *r)
{
	r->x = 0;
	m->sprite_x = m->sprite_arr[data->head->order].x;
	m->sprite_y = m->sprite_arr[data->head->order].y;
	r->sprite_x = m->sprite_x - data->pos_x + 0.5;
	r->sprite_y = m->sprite_y - data->pos_y + 0.5;
	r->inv_det = 1.0 / (data->plane_x * data->dir_y - \
        data->dir_x * data->plane_y);
	r->transform_x = r->inv_det * (data->dir_y * r->sprite_x - \
        data->dir_x * r->sprite_y);
	r->transform_y = r->inv_det * (-data->plane_y * \
        r->sprite_x + data->plane_x * r->sprite_y); 
	r->sprite_screen_x = (int)((SCREENWIDTH / 2.0) * \
        (1 + r->transform_x / r->transform_y));
	r->sprite_height = abs((int)(SCREENHEIGHT / r->transform_y));
	r->draw_start_y = -r->sprite_height / 2 + SCREENHEIGHT / 2;
	calc_sprites2(r);
}

static void	rend_sprites(t_map *m, t_data *data, t_rend_sprite *r)
{
	data->tex_x = (int)(256 * (r->stripe - (-r->sprite_width / \
        2 + r->sprite_screen_x)) * TEXWIDTH / r->sprite_width) / 256;
	if ((r->transform_y > 0 && r->stripe > 0 && r->stripe < SCREENWIDTH && \
        r->transform_y < data->z_buffer[r->stripe]))
	{
		r->y = r->draw_start_y;
		while (r->y < r->draw_end_y)
		{
			r->d = r->y * 256 - SCREENHEIGHT * 128 + r->sprite_height * 128;
			r->tex_y = ((r->d * TEXHEIGHT) / r->sprite_height) / 256;
			ft_pixel_put(data->m_ptr, r->stripe, r->y, \
                (unsigned int)ft_pixel_get(m->sprite_arr[data->head->order].txt, \
                data->tex_x, r->tex_y));
			r->y++;
		}
	}
	r->stripe++;	
}

void	draw_sprites(t_data *data, t_map *m, t_rend_sprite *r)
{
	r->x = 0;
	data->head = creat_node(data, r->x);
	data->temp_head = data->head;
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
}