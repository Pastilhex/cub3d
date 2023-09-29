/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:23:31 by joaoalme          #+#    #+#             */
/*   Updated: 2023/09/29 18:27:17 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	find_texture(char *line, char *texture)
{
	// int 	i;
	int		size;
	char	*texture_found;

	// i = 0;
	size = ft_strlen(line);
	texture_found = ft_strnstr(line, texture, size);
	if (texture_found)
		return (true);
	return (false);
}