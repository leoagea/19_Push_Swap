/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:03:02 by lagea             #+#    #+#             */
/*   Updated: 2024/05/20 16:11:56 by lagea            ###   ########.fr       */
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
t_node	*find_closest(t_stack *stack_b, t_node *node)
{
	t_node	*bigest;
	t_node	*smallest;
	t_node	*current;
	t_node	*closest;

	bigest = find_biggest_b(stack_b);
	smallest = find_smallest_b(stack_b);
	if (node->value < smallest->value)
		return (bigest);
	else if (node->value > bigest->value)
		return (bigest);
	closest = smallest;
	current = stack_b->head;
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

float find_average(t_stack *stack_a)
{
	int count;
	float average;
	t_node *current;
	
	count = 0;
	average = 0;
	current = stack_a->head;
	while (current != NULL)
	{
		average += current->value;
		count++;
		current = current->next;
	}
	return average/count;
}

t_node	*find_best_friend(t_stack *stack_a, t_node *node)
{
	t_node	*biggest;
	t_node	*smallest;
	t_node	*current;
	t_node	*closest;

	biggest = find_biggest_a(stack_a);
	smallest = find_smallest_a(stack_a);
	// if (node->value < smallest->value)
	// 	return (biggest);
	// else if (node->value > bigest->value)
	// 	return (biggest);
	closest = biggest;
	current = stack_a->head;
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

//improve la function pour si le bestfriend et le node doivent rotate dans le meme sens ne compter que 1 cost
void find_cost(t_stack *stack_a, t_stack *stack_b)
{
	int cost_n;
	int cost_b;
	t_node *current;
	t_node *best;

	current = stack_b->head;
	index_init_stack(stack_a, stack_b);
	find_median(stack_a);
	find_median(stack_b);
	while (current != NULL)
	{
		best = find_best_friend(stack_a, current);
		cost_b = find_moves_bestfriend(stack_a,best);
		cost_n = find_moves_node(stack_b,current);
		current->cost = cost_b + cost_n;
		// printf("cost : %d\n",current->cost);
		// printf("current : %zd, best friend : %zd, cost best : %d\n", current->value,best->value,current->cost);
		current = current->next;
	}
}

int find_moves_bestfriend(t_stack *stack_a, t_node *bestfriend)
{
	int cost;
	int dll_len;
	
	cost = 0;
	dll_len = dll_size(stack_a);
	if (bestfriend->median && bestfriend->index != 1)
		cost = bestfriend->index - 1;
	else if (!bestfriend->median)
		cost = dll_len - bestfriend->index + 1;
	return cost;
}

int find_moves_node(t_stack *stack_b, t_node *node)
{
	int cost;
	int dll_len;

	cost = 0;
	dll_len = dll_size(stack_b);
	if (node->median && node->index != 1)
		cost = node->index - 1;
	else if (!node->median)
		cost = dll_len - node->index + 1;
	return cost;
	
}
