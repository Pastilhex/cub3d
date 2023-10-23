/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_hands.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:21:48 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/23 19:47:25 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void    trigger(t_data *data)
{
    data->map_ptr->current_time = get_actual_time();
    if (data->press_space == 1)
	{
		if (data->map_ptr->current_time - data->map_ptr->start_time > 100)
		{
			data->swap_hands++;
			if (data->swap_hands == 3)
			{
				data->swap_hands = 0;
				data->press_space = 0;
			}	
			data->map_ptr->start_time = get_actual_time();
		}
	}
}

void    draw_hands(t_data *data)
{
    int i;
    int j;
    double a;
    double b;
    double begin_i;
    double begin_j;

    i = SCREENWIDTH * 0.4;
    a = 128.0 / ((double) SCREENWIDTH / 5);
    b = (128.0 / ((double) SCREENHEIGHT / 3.75));
    begin_i = (SCREENWIDTH * 0.4);
    begin_j = (SCREENHEIGHT - (SCREENHEIGHT / 6.0 + SCREENHEIGHT / 3.75));
    trigger(data);
    while (i < SCREENWIDTH * 0.6)
    {
        j = SCREENHEIGHT - (SCREENHEIGHT / 6.0 + SCREENHEIGHT / 3.75);
        while (j < SCREENHEIGHT - (SCREENHEIGHT / 6.0))
        {
            ft_pixel_put(data->m_ptr, i, j, (unsigned int)
                ft_pixel_get(&data->txt_hands[data->swap_hands],
                (int)((i - begin_i) * a), (int)((j - begin_j) * b)));
            j++;
        }
        i++;
    }
}
