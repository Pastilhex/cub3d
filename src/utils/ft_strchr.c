/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:47:07 by ialves-m          #+#    #+#             */
/*   Updated: 2023/10/09 11:42:42 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*ft_strchr(char *s, int c)
{
	int		slen;
	char	*ptr;
	int		last;

	last = (unsigned int)ft_strlen(s);
	ptr = (char *)s;
	slen = 0;
	if (c == '\0')
		return (ptr + last);
	while (s[slen] != '\0')
	{
		if (s[slen] == c)
			return ((char *)s + slen);
		slen++;
	}
	return (NULL);
}
/*
int main(void)
{
	char str[] = "ivo daniel";

	printf("%s", ft_strchr(str, 'd'));

}
*/
