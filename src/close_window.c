/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:59:10 by ialves-m          #+#    #+#             */
/*   Updated: 2023/10/06 10:16:56 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void		free_t_map(t_map *m)
{
	free(m->north_texture);
	free(m->south_texture);
	free(m->east_texture);
	free(m->west_texture);
	free(m->ceiling_texture);
	free(m->floor_texture);
	free(m->get_line);
	free_arr(m->worldMap, m);
}
static void		cleaning(t_data *d, t_map* m)
{
	free(d->txt_ptr);
	free_t_map(m);
}
int	close_window(t_data *d)
{
	int		i;
	
	mlx_clear_window(d->m_ptr->mlx, d->m_ptr->mlx_win);
	if (d->m_ptr->mlx)
		mlx_destroy_window(d->m_ptr->mlx, d->m_ptr->mlx_win);
	mlx_destroy_image(d->m_ptr->mlx, d->m_ptr->img);
	i = -1;
	while (++i < 4)
		mlx_destroy_image(d->m_ptr->mlx, d->txt_ptr[i].img);
	if (d->m_ptr->mlx_win)
		mlx_destroy_display(d->m_ptr->mlx);
	cleaning(d->m_ptr->data_ptr, d->m_ptr->data_ptr->map_ptr);
	free(d->m_ptr->mlx);	
	exit(0);
	return (0);
}
