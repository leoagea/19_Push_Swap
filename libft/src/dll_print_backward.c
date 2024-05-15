/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_print_backward.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:38:24 by lagea             #+#    #+#             */
/*   Updated: 2024/05/15 14:27:17 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"
#include "../../inc/push_swap.h"

void	dll_print_backward(struct dll_edge *edge)
{
	t_node *current;

	current = edge->tail;
	while (current != NULL)
	{
		// printf("index %d : %zd |		cost : %d|	 median :%d\n",current->index,current->value,current->cost,current->median);
		printf("index %d : %zd\n", current->index, current->value);
		current = current->prev;
	}
}
