/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:03:02 by lagea             #+#    #+#             */
/*   Updated: 2024/05/17 14:05:52 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/push_swap.h"

t_node	*find_bigest_b(t_stack *stack)
{
	int		bigest_b;
	t_node	*current;
	t_node	*bigest;

	bigest_b = 0;
	current = stack->b->head;
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

t_node	*find_smallest_b(t_stack *stack)
{
	int		smallest_b;
	t_node	*current;
	t_node	*smallest;

	current = stack->b->head;
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

t_node	*find_biggest_a(t_stack *stack)
{
	int		biggest_a;
	t_node	*current;
	t_node	*biggest;

	current = stack->a->head;
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

t_node	*find_smallest_a(t_stack *stack)
{
	int		smallest_a;
	t_node	*current;
	t_node	*smallest;

	current = stack->a->head;
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
t_node	*find_closest(t_stack *stack, t_node *node)
{
	t_node	*bigest;
	t_node	*smallest;
	t_node	*current;
	t_node	*closest;

	bigest = find_bigest_b(stack);
	smallest = find_smallest_b(stack);
	if (node->value < smallest->value)
		return (bigest);
	else if (node->value > bigest->value)
		return (bigest);
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
	return (closest);
}

float find_average(t_stack *stack)
{
	int count;
	float average;
	t_node *current;
	
	count = 0;
	average = 0;
	current = stack->a->head;
	while (current != NULL)
	{
		average += current->value;
		count++;
		current = current->next;
	}
	return average/count;
}

t_node	*find_best_friend(t_stack *stack, t_node *node)
{
	t_node	*biggest;
	t_node	*smallest;
	t_node	*current;
	t_node	*closest;

	biggest = find_biggest_a(stack);
	smallest = find_smallest_a(stack);
	// if (node->value < smallest->value)
	// 	return (biggest);
	// else if (node->value > bigest->value)
	// 	return (biggest);
	closest = biggest;
	current = stack->a->head;
	while (current != NULL)
	{
		if (current->value < closest->value && current->value > node->value)
		{
			closest = current;
			current = current->next;
		}
		else
			current = current->next;
	}
	return (closest);
}

void find_cost(t_stack *stack)
{
	t_node *current;
	t_node *best;

	current = stack->b->head;
	while (current != NULL)
	{
		best = find_best_friend(stack, current);
		find_moves_bestfriend(stack,best);
		printf("current : %zd, best friend : %zd, cost best : %d\n", current->value,best->value,best->cost);
		current = current->next;
	}
}

void find_moves_bestfriend(t_stack *stack, t_node *bestfriend)
{
	int cost;
	int dll_len = dll_size(stack->a);
	find_median(stack->a);
	index_init(stack->a);
	
	cost = 0;
	if (bestfriend->median && bestfriend->index != 1)
		cost = bestfriend->index - 1;
	else if (!bestfriend->median)
		cost = dll_len - bestfriend->index + 1;
	bestfriend->cost = cost;
}
