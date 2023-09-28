/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:56:22 by ialves-m          #+#    #+#             */
/*   Updated: 2023/09/28 13:16:55 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	handle_keypress(int keysym, t_mlx *m)
{
	(void) m;
	(void) keysym;
	// if (keysym == XK_W || keysym == XK_w)
	// 	move_player(0, -1, m);
	// else if (keysym == XK_A || keysym == XK_a)
	// 	move_player(-1, 0, m);
	// else if (keysym == XK_S || keysym == XK_s)
	// 	move_player(0, 1, m);
	// else if (keysym == XK_D || keysym == XK_d)
	// 	move_player(1, 0, m);
	if (keysym == XK_Escape)
		close_window(m);
	return (0);
}
