/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 11:34:17 by ialves-m          #+#    #+#             */
/*   Updated: 2023/10/27 17:12:24 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	set_larger_line(t_data *d)
{
	int	i;

	i = 0;
	while (i < d->map_ptr->m_end - d->map_ptr->m_start)
	{
		if (ft_strlen(d->map_ptr->world_map[i]) > d->map_ptr->larger_line)
			d->map_ptr->larger_line = ft_strlen(d->map_ptr->world_map[i]);
		i++;
	}
}

void	fill_5_lines(t_data *d, int i, int end)
{
	int	j;
	int	len;

	len = d->map_ptr->larger_line + 21;
	while (i < end)
	{
		d->mini_map_ptr->big_map[i] = malloc(sizeof(char) * len);
		j = 0;
		while (j < len - 1)
		{
			d->mini_map_ptr->big_map[i][j] = '#';
			j++;
		}
		d->mini_map_ptr->big_map[i][j] = '\0';
		i++;
	}
}

char	*fill_end(int size)
{
	char	*s;
	int		i;

	s = malloc(sizeof(char) * size + 1);
	i = 0;
	while (i < size)
	{
		s[i] = '*';
		i++;
	}
	s[i] = '\0';
	return (s);
}

void	add_spaces(t_data *d)
{
	int		i;
	char	*s;
	int		space_diff;
	char	*s_end;
	char	*temp;

	fill_5_lines(d, 0, 5);
	s = "**********";
	i = 5;
	while (i < (d->map_ptr->m_end - d->map_ptr->m_start) + 5)
	{
		temp = ft_strjoin2(s, ft_strtrim(d->map_ptr->world_map[i - 5], "\n"));
		space_diff = (d->map_ptr->larger_line + 20) - ft_strlen(temp);
		s_end = fill_end(space_diff);
		d->mini_map_ptr->big_map[i] = ft_strjoin(temp, s_end);
		i++;
		free(s_end);
	}
	fill_5_lines(d, i, d->map_ptr->m_end - d->map_ptr->m_start + 10);
}
