/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:23:31 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/05 14:36:52 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	find_texture(char *line, char *texture)
{
	int		size;
	char	*texture_found;

	size = ft_strlen(line);
	texture_found = ft_strnstr(line, texture, size);
	if (texture_found)
		return (true);
	return (false);
}
