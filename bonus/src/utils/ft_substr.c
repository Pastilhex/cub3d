/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:41:22 by ialves-m          #+#    #+#             */
/*   Updated: 2023/10/09 11:41:43 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*ft_substr(char *s, unsigned int start, unsigned int len)
{
	char	*subs;
	int		i;

	i = 0;
	subs = (char *)malloc(len * sizeof(char) + 1);
	if (!s || !len || start >= (unsigned int)ft_strlen(s))
	{
		subs[0] = '\0';
		return (subs);
	}
	else if (!subs)
		return (NULL);
	while (i < (int)len)
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}

/*
int main(void)
{
	char str[] = "uma bem frase comprida";
	
	printf("%s", ft_substr(str, 14, 3));
}
*/
