/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:18:36 by lagea             #+#    #+#             */
/*   Updated: 2025/01/09 14:14:10 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/push_swap.h"

t_node	*find_best_friend(t_stack *stack_a, t_node *node)
{
	t_node	*biggest;
	t_node	*current;
	t_node	*closest;

	biggest = find_biggest_a(stack_a);
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

float	find_average(t_stack *stack_a)
{
	int		count;
	float	average;
	t_node	*current;

	count = 0;
	average = 0;
	current = stack_a->head;
	while (current != NULL)
	{
		average += current->value;
		count++;
		current = current->next;
	}
	return (average / count);
}

void	find_cost(t_stack *stack_a, t_stack *stack_b)
{
	int		cost_n;
	int		cost_b;
	t_node	*current;
	t_node	*best;

	current = stack_b->head;
	index_init_stack(stack_a, stack_b);
	find_median(stack_a);
	find_median(stack_b);
	while (current != NULL)
	{
		best = find_best_friend(stack_a, current);
		cost_b = find_moves_bestfriend(stack_a, best);
		cost_n = find_moves_node(stack_b, current);
		current->cost = cost_b + cost_n;
		current = current->next;
	}
}

int	find_moves_node(t_stack *stack_b, t_node *node)
{
	int	cost;
	int	dll_len;

	cost = 0;
	dll_len = dll_size(stack_b);
	if (node->median && node->index != 1)
		cost = node->index - 1;
	else if (!node->median)
		cost = dll_len - node->index + 1;
	return (cost);
}

int	find_moves_bestfriend(t_stack *stack_a, t_node *bestfriend)
{
	int	cost;
	int	dll_len;

	cost = 0;
	dll_len = dll_size(stack_a);
	if (bestfriend->median && bestfriend->index != 1)
		cost = bestfriend->index - 1;
	else if (!bestfriend->median)
		cost = dll_len - bestfriend->index + 1;
	return (cost);
}
