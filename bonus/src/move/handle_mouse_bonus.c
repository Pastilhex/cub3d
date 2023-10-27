/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 21:46:33 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/23 22:18:49 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	handle_mouse(int x, int y, t_data *d)
{
	static int	prev;

	if (x < 0 || x > SCREENWIDTH)
		x = SCREENWIDTH / 2;
	if (x < prev)
		move_p_left(d->m_ptr);
	else if (x > prev)
		move_p_right(d->m_ptr);
	prev = x;
	(void)x;
	(void)y;
	(void)d;
	return (1);
}

int	handle_mouse_fire(int button, int x, int y, t_data *d)
{
	if (button == 1)
		d->press_space = 1;
	(void)x;
	(void)y;
	(void)d;
	return (0);
}
