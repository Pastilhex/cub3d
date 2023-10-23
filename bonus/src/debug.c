/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:59:00 by ialves-m          #+#    #+#             */
/*   Updated: 2023/10/23 21:56:01 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void 	ft_print_array(char **arr, int nb_lines)
{
	for (int i = 0; i < nb_lines; i++)
	{
		printf("%s", arr[i]);
		printf("\n");
	}
	printf("\n");
}

void	print_list(t_s_list *head)
{
	t_s_list	*current;

	if (head == NULL)
	{
		printf("Null head\n");
	}
	current = head;
	while (current != NULL)
	{
		printf("order: %d\ndistance: %d\n", current->order, current->distance);
		current = current->next;
	}
}