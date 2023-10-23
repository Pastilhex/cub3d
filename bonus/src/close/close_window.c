/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:59:10 by ialves-m          #+#    #+#             */
/*   Updated: 2023/10/23 22:18:08 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	free_t_map(t_map *m)
{
	if (m->north_texture)
		free(m->north_texture);
	if (m->south_texture)
		free(m->south_texture);
	if (m->east_texture)
		free(m->east_texture);
	if (m->west_texture)
		free(m->west_texture);
	if (m->ceiling_texture)
		free(m->ceiling_texture);
	if (m->floor_texture)
		free(m->floor_texture);
	if (m->get_line)
		free(m->get_line);
	if (m->world_map)
		free_arr(m->world_map, m);
}

static void	cleaning(t_data *d, t_map *m)
{
	if (d->txt_ptr)
		free(d->txt_ptr);
	if (m->animated_hands)
		free(m->animated_hands);
	if (m->animated_hands)
		free(m->animated_head);
	free_t_map(m);
	if (d->head)
		clear_list(d->head);
	free(d->txt_head);
	free(d->txt_hands);
	free(m->sprite_order);
	free(m->sprite_arr);
	free(m->sprite_distance);
}

void	destoy_img_arrays(t_data *d)
{
	int	i;

	i = -1;
	while (++i < 15)
		if (d->m_ptr->mlx)
			mlx_destroy_image(d->m_ptr->mlx, d->txt_ptr[i].img);
	i = -1;
	while (++i < 3)
	{
		if (d->m_ptr->mlx)
		{
			mlx_destroy_image(d->m_ptr->mlx, d->txt_hands[i].img);
			mlx_destroy_image(d->m_ptr->mlx, d->txt_head[i].img);
		}
	}
}

int	close_window(t_data *d)
{
	if (d->m_ptr->mlx)
		mlx_clear_window(d->m_ptr->mlx, d->m_ptr->mlx_win);
	if (d->m_ptr->mlx)
		mlx_destroy_window(d->m_ptr->mlx, d->m_ptr->mlx_win);
	if (d->m_ptr->mlx)
		mlx_destroy_image(d->m_ptr->mlx, d->m_ptr->img);
	destoy_img_arrays(d);
	if (d->m_ptr->mlx_win)
		mlx_destroy_display(d->m_ptr->mlx);
	cleaning(d, d->map_ptr);
	if (d->m_ptr->mlx)
		free(d->m_ptr->mlx);
	exit(0);
	return (0);
}

void	clear_list(t_s_list *node)
{
	t_s_list	*curr;

	curr = node;
	while (node != NULL && curr->next != NULL)
	{
		node = curr;
		curr = curr->next;
		free(node);
	}
	free(curr);
}
