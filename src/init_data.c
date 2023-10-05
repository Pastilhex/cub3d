/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:42:45 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/05 12:56:54 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void     init_data2(t_data *d, struct s_map *map_ptr, t_mlx *m)
{
	d->sideDistX = 0.0;
	d->sideDistY = 0.0;
	d->deltaDistX = 0.0;
	d->deltaDistY = 0.0;
	d->perpWallDist = 0.0;
	d->stepX = 0;
	d->stepY = 0;
	d->hit = 0;
	d->side = 0;
	d->lineHeight = 0;
	d->drawStart = 0;
	d->drawEnd = 0;
	d->oldDirX = 0.0;
	d->oldPlaneX = 0.0;
	d->frameTime = 0.0;
	d->fps = 0;
	d->tps = 0.0;
	d->texX = 0;
	d->txt_ptr = malloc(sizeof(t_texture) * 4); 
	if (!d->txt_ptr)
		exit(EXIT_FAILURE);
	d->map_ptr = map_ptr;
	d->m_ptr = m;
}

void	init_data(t_data *d, struct s_map *map_ptr, t_mlx *m)
{
	d->moveUp = 0;
	d->moveDown = 0;
	d->moveLeft = 0;
	d->moveRight = 0;
	d->slideLeft = 0;
	d->slideRight = 0;
	d->posX = 0.0;
	d->posY = 0.0;
	d->dirX = 0.0;
	d->dirY = 0.0;
	d->planeX = 0.0;
	d->planeY = 0.0;
	d->moveSpeed = 0.0;
	d->rotSpeed = 0.0;
	d->time = 0.0;
	d->oldTime = 0.0;
	d->cameraX = 0.0;
	d->rayDirX = 0.0;
	d->rayDirY = 0.0;
	d->mapX = 0;
	d->mapY = 0;
	init_data2(d, map_ptr, m);
}
