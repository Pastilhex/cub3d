/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:26:54 by ialves-m          #+#    #+#             */
/*   Updated: 2023/10/06 14:47:10 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_put_nbr(long long int nbr, int base, int *len)
{
	char *hexa_base = "0123456789abcdef";

	if(nbr < 0)
	{
		nbr = -nbr;
		*len += write(1, "-", 1);
	}
	if (nbr >= base)
		ft_put_nbr((nbr/base), base, len);
	*len += write(1, &hexa_base[nbr % base], 1);

}
