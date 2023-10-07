/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isOnlyDigitOrComma.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:16:03 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/07 15:16:15 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool		isOnlyDigitOrComma(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (((str[i] >= 48 && str[i] <= 57) || str[i] == ','))
			i++;
		else
			return (false);
	}
	return (true);
}