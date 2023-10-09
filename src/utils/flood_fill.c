/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:25:08 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/09 15:25:41 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	flood_fill(char **arr, int i, int j, char c)
{
	if (arr[i][j] == '1')
	{
		arr[i][j] = c;
		if (is_valid_char(arr[i][j + 1]))
			flood_fill(arr, i, j + 1, c);
		if (is_valid_char(arr[i][j - 1]))
			flood_fill(arr, i, j - 1, c);
		if (is_valid_char(arr[i + 1][j]))
			flood_fill(arr, i + 1, j, c);
		if (is_valid_char(arr[i - 1][j]))
			flood_fill(arr, i - 1, j, c);
	}
}
