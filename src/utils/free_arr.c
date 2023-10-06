/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 19:33:08 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/06 09:45:39 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_arr(char **arr, t_map *m)
{
	int	i;

	i = 0;
	while (i < m->map_length)
	{
		if(arr[i])
            free(arr[i]);
		i++;
	}
	free(arr);
}
void	free_arr1(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if(arr[i])
            free(arr[i]);
		i++;
	}
	free(arr);
}