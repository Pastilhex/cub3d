/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frames2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:05:09 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/05 13:09:07 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void     check_hit(t_data *data)
{
	while(data->hit == '0')
		{
			if(data->sideDistX < data->sideDistY)
			{
				data->sideDistX += data->deltaDistX;
				data->mapX += data->stepX;
				data->side = '0';
			}
			else
			{
				data->sideDistY += data->deltaDistY;
				data->mapY += data->stepY;
				data->side = '1';
			}
			if(data->map_ptr->worldMap[data->mapX][data->mapY] > '0')
				data->hit = '1';
		}
		if(data->side == '0')
			data->perpWallDist = (data->sideDistX - data->deltaDistX);
		else
			data->perpWallDist = (data->sideDistY - data->deltaDistY);
}
static void     calculate_cols(t_data *data)
{
	data->lineHeight = (int)(screenHeight / data->perpWallDist);
	int pitch = 10;
	data->drawStart = -data->lineHeight / 2 + screenHeight / 2 + pitch;
	if(data->drawStart < 0)
		data->drawStart = 0;
	data->drawEnd = data->lineHeight / 2 + screenHeight / 2 + pitch;
	if(data->drawEnd >= screenHeight)
		data->drawEnd = screenHeight - 1;
	if (data->side == '0')
		data->map_ptr->wallX = data->posY + data->perpWallDist * data->rayDirY; 
	else
		data->map_ptr->wallX = data->posX + data->perpWallDist * data->rayDirX; 
	data->map_ptr->wallX -= floor((data->map_ptr->wallX));
	data->texX = (int)(data->map_ptr->wallX * (double)texWidth);
	if(data->side == '0' && data->rayDirX > 0)
		data->texX = texWidth - data->texX - 1;
	if(data->side == '1' && data->rayDirY < 0)
		data->texX = texWidth - data->texX - 1;
	data->map_ptr->step = 1.0 * texHeight / data->lineHeight;
	data->map_ptr->texPos = (data->drawStart - pitch - (double)screenHeight / 2 + (double)data->lineHeight / 2) * data->map_ptr->step;
}
static void     draw_cols(t_data *data, int *x)
{
	int		y;
	
	y = data->drawStart;
	while (y < data->drawEnd)
	{
		int texY = (int)data->map_ptr->texPos & (texHeight - 1);
		data->map_ptr->texPos += data->map_ptr->step;
		if (data->side == '0' && data->rayDirX > 0)
			ft_pixel_put(data->m_ptr, *x, y, ft_pixel_get(&data->txt_ptr[south], data->texX, texY));
		else if (data->side == '0' && data->rayDirX < 0)
			ft_pixel_put(data->m_ptr, *x, y, ft_pixel_get(&data->txt_ptr[1], data->texX, texY));
		else if (data->side == '1' && data->rayDirY > 0)
			ft_pixel_put(data->m_ptr, *x, y, ft_pixel_get(&data->txt_ptr[2], data->texX, texY));
		else if (data->side == '1' && data->rayDirY < 0)
			ft_pixel_put(data->m_ptr, *x, y, ft_pixel_get(&data->txt_ptr[3], data->texX, texY));
		y++;
	}
}
void	render_frames2(t_data *data, int *x)
{
	if(data->rayDirY < 0)
	{
		data->stepY = -1;
		data->sideDistY = (data->posY - data->mapY) * data->deltaDistY;
	}
	else
	{
		data->stepY = 1;
		data->sideDistY = (data->mapY + 1.0 - data->posY) * data->deltaDistY;
	}
    check_hit(data);
	calculate_cols(data);
	draw_cols(data, x);
}