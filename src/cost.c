/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:03:02 by lagea             #+#    #+#             */
/*   Updated: 2024/05/08 12:28:07 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../inc/libft.h"

void find_cost_a(t_stack *stack, t_node *node)
{
	int cost_a;
	t_node current;
	
	if(node->index < node->median){}
	
}
t_node *bigest_b(t_stack *stack)
{
	int bigest_b;
	t_node *current;
	t_node *bigest;

	bigest_b = 0;
	current = stack->b->head;
	while (current != NULL)
	{
		if(bigest_b < current->value)
		{
			bigest_b = current->value;
			bigest = current;
		}
		current = current->next;
	}	
	return bigest;
}

t_node *smallest_b(t_stack *stack)
{
	int smallest_b;
	t_node *current;
	t_node *smallest;

	current = stack->b->head;
	smallest_b = current->value;
	while (current != NULL)
	{
		if(smallest_b < current->value)
			current = current->next;
		else
		{
			smallest_b = current->value;
			smallest = current;
			current = current->next;
		}
	}	
	return smallest;
}
