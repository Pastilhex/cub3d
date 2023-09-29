/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 22:01:59 by ialves-m          #+#    #+#             */
/*   Updated: 2023/04/23 22:02:00 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	len(char *word)
{
	int	i;

	i = 0;
	if (!word)
		return (0);
	while (word[i])
		i++;
	return (i);
}

int	find(char *str, char c)
{
	int	i;
	int	flag;
	int	length;

	i = 0;
	flag = 0;
	length = len(str);
	while (i < length)
	{
		if (str[i] == c)
			flag = 1;
		i++;
	}
	return (flag);
}

char	*join(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*joinstr;

	i = 0;
	j = 0;
	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	joinstr = malloc((len(s1) + len(s2) + 1) * sizeof(char));
	if (!joinstr || !s2)
		return (NULL);
	joinstr[(len(s1) + len(s2))] = '\0';
	while (i < len(s1))
	{
		joinstr[i] = s1[i];
		i++;
	}
	while (i < (len(s1) + len(s2)))
		joinstr[i++] = s2[j++];
	joinstr[i] = '\0';
	free (s1);
	return (joinstr);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*a;
	size_t	index;

	a = malloc(nmemb * size);
	if (!a)
	{
		free (a);
		return (NULL);
	}
	index = 0;
	while (index < (nmemb))
	{
		a[index] = '\0';
		index++;
	}
	return ((int *)a);
}
