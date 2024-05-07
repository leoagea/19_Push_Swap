/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_print_forward.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:41:18 by lagea             #+#    #+#             */
/*   Updated: 2024/05/07 13:55:08 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"
#include "../../inc/push_swap.h"

void dll_print_forward(struct dll_edge *edge)
{
	t_node *current;

	current = edge->head;
	while (current != NULL)
	{
		printf("index %d : %zd |	 cost : %d|	 median : %d\n",current->index,current->value,current->cost,current->median);
		current = current->next;
	}
}
