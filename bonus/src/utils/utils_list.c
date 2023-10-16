/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:50:40 by joaoalme          #+#    #+#             */
/*   Updated: 2023/10/16 22:02:18 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_s_list	*creat_node(t_data *d, int x)
{
    t_s_list	*new_elm;
    t_map       *m;

    m = d->map_ptr;    
    new_elm = malloc(sizeof(t_s_list));
	if (!new_elm)
		exit(EXIT_FAILURE);
	new_elm->order = x;
	new_elm->distance = ((d->pos_x - m->sprite_arr[x].x) *
        (d->pos_x - m->sprite_arr[x].x) + (d->pos_y -m->sprite_arr[x].y) *
        (d->pos_y - m->sprite_arr[x].y));;
	new_elm->next = 0;
	new_elm->previous = 0;
	return (new_elm);
}



t_s_list	*find_tail(t_s_list **stack)
{
	
    
    t_s_list	*tail;

	tail = *stack;
	while (tail->next != NULL)
		tail = tail->next;
	return (tail);
}

t_s_list	*add_element_back(t_s_list *head, t_data *d, int x)
{
	t_s_list	*new_node;
	t_s_list	*tail;

	tail = find_tail(&head);
	new_node = creat_node(d, x);
	tail->next = new_node;
	new_node->previous = tail;
	return (new_node);
}

void swap_nodes(t_s_list **head, t_s_list *node1, t_s_list *node2)
{
    t_s_list temp;
    (void)head;
    
    // node1->previous->next = node1->next;
    // node1->next->previous = node1->previous;
    // node2->next = node1;
    // node2->previous = node1->previous;
    // (void)temp;
    // node1->previous = node2;
    // node1->next->previous = node1;
    

    temp.distance = node1->distance;
    temp.order = node1->order;
    node1->distance = node2->distance;
    node1->order = node2->order;
    node2->distance = temp.distance;
    node2->order = temp.order;
}

void    order_list(t_s_list **head)
{
    t_s_list    *ptr_1;
    t_s_list    *ptr_2;
    t_s_list    *temp;
    int         swapped;

    if(*head == NULL || (*head)->next == NULL)  
        return;
    temp = NULL;
    ptr_1 = *head;
    
    while (1) {
        swapped = 0;
        ptr_1 = *head;
        ptr_2 = (*head)->next;

        while (ptr_2 != temp) 
        {
            if (ptr_1->distance < ptr_2->distance) {
                swap_nodes(head, ptr_1, ptr_2);
                swapped = 1;
            }

            ptr_1 = ptr_2;
            ptr_2 = ptr_2->next;
        }
        temp = ptr_1;
        if (!swapped) {
            break; 
        }
    }
}

void    print_list(t_s_list *head)
{
    if (head == NULL)
    {
        printf("Null head\n");
    }
    t_s_list *current  = head;
    
    while (current != NULL)
    {
        printf("order: %d\ndistance: %d\n", current->order, current->distance);
        current = current->next;
    }
}
    
    
    
    
    
    
    
   