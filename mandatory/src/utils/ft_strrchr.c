/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:39:34 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/12 16:39:35 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*str;

	str = (char *)s;
	len = ft_strlen(str);
	if (!s)
		return (NULL);
	if (*(str + len) == (char)c)
		return (str + len);
	while (len > 0)
	{
		if (*(str + len - 1) == (char)c)
			return (str + len - 1);
		len--;
	}
	return (NULL);
}
