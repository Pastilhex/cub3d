/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:25:08 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/08 20:20:20 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	flood_fill(char **arr, int i, int j, char c)
{
	if (arr[i][j] == '1')
	{
		arr[i][j] = c;
		if ( isValidChar(arr[i][j + 1]))
			flood_fill(arr, i, j + 1, c);
		if (isValidChar(arr[i][j - 1]))
			flood_fill(arr, i, j - 1, c);
		if (isValidChar(arr[i + 1][j]))
			flood_fill(arr, i + 1, j, c);
		if (isValidChar(arr[i - 1][j]))
			flood_fill(arr, i - 1, j, c);
	}
}
