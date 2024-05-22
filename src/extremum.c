/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extremum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:03:02 by lagea             #+#    #+#             */
/*   Updated: 2024/05/22 17:58:15 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/push_swap.h"

t_node	*find_biggest_b(t_stack *stack_b)
{
	int		bigest_b;
	t_node	*current;
	t_node	*bigest;

	bigest_b = 0;
	current = stack_b->head;
	while (current != NULL)
	{
		if (bigest_b < current->value)
		{
			bigest_b = current->value;
			bigest = current;
		}
		current = current->next;
	}
	return (bigest);
}

t_node	*find_smallest_b(t_stack *stack_b)
{
	int		smallest_b;
	t_node	*current;
	t_node	*smallest;

	current = stack_b->head;
	smallest_b = current->value;
	while (current != NULL)
	{
		if (smallest_b < current->value)
			current = current->next;
		else
		{
			smallest_b = current->value;
			smallest = current;
			current = current->next;
		}
	}
	return (smallest);
}

t_node	*find_biggest_a(t_stack *stack_a)
{
	int		biggest_a;
	t_node	*current;
	t_node	*biggest;

	current = stack_a->head;
	biggest_a = current->value;
	biggest = NULL;
	while (current != NULL)
	{
		if (biggest_a > current->value)
			current = current->next;
		else
		{
			biggest_a = current->value;
			biggest = current;
			current = current->next;
		}
	}
	return (biggest);
}

t_node	*find_smallest_a(t_stack *stack_a)
{
	int		smallest_a;
	t_node	*current;
	t_node	*smallest;

	current = stack_a->head;
	smallest_a = current->value;
	smallest = NULL;
	while (current != NULL)
	{
		if (smallest_a < current->value)
			current = current->next;
		else
		{
			smallest_a = current->value;
			smallest = current;
			current = current->next;
		}
	}
	return (smallest);
}

void	push_smallest(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*smallest;

	find_median(stack_a);
	smallest = find_smallest_a(stack_a);
	while (smallest->index != 1)
	{
		if (smallest->median)
			rotate_a(stack_a, stack_b, true);
		else
			reverse_rotate_a(stack_a, stack_b, true);
		smallest = find_smallest_a(stack_a);
		index_init(stack_a);
	}
	push_b(stack_a, stack_b);
}
