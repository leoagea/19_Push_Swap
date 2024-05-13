/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:03:02 by lagea             #+#    #+#             */
/*   Updated: 2024/05/13 18:50:49 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../inc/libft.h"

t_node *find_bigest_b(t_stack *stack)
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

t_node *find_smallest_b(t_stack *stack)
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

t_node *find_closest(t_stack *stack,t_node *node)
{
	t_node *bigest;
	t_node *smallest;
	t_node *current;
	t_node *closest;
	
	bigest = find_bigest_b(stack);
	smallest = find_smallest_b(stack);

	if (node->value < smallest->value)
		return bigest;
	else if (node->value > bigest->value)
		return bigest;
	closest = smallest;
	current = stack->b->head;
	while (current != NULL)
	{
		if (current->value > closest->value && current->value < node->value)
		{
			closest = current;
			current = current->next;
		}
		else
			current = current->next;
	}
	return closest;
}

void find_cost(t_stack *stack, t_node *current, t_node *closest)
{
	int temp;
	int dll_len;
	
	temp += 0;
	dll_len = dll_size(stack->a);
	if (current->median)
		temp = current->index - 1;
	else 
		temp = dll_len - current->index + 1;
	dll_len = dll_size(stack->b);
	if (closest->median)
		temp += closest->index - 1;
	else 
		temp += dll_len - closest->index + 1;
	// printf("temp : %d\n",temp);
	current->cost = temp;
}

void find_cost_stack(t_stack *stack)
{
	t_node *target;
	t_node *current;
	
	current = stack->a->head;
	while (current != NULL)
	{
		target = find_closest(stack,current);
		find_cost(stack,current,target);
		current = current->next;
	}
}