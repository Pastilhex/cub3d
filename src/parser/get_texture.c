/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:23:50 by joaoalme          #+#    #+#             */
/*   Updated: 2023/09/29 18:27:08 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*get_texture(char *line)
{
	int		i;
	int		j;
	int		size;
	char	*str;

	size = ft_strlen(line);
	i = 0;
	j = 0;
	while (i < size - 1 && (line[i] != '.' && line[i + 1] != '/'))
		i++;
	if (line[i + 1] == '\n' || line[i + 1] == '\0')
		return (NULL);
	str = malloc((ft_strlen(line) - i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (line[i])
		str[j++] = line[i++];
	str[j] = '\0';
	return (str);
}