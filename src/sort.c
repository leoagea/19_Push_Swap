/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:14:07 by lagea             #+#    #+#             */
/*   Updated: 2024/05/21 18:16:30 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/push_swap.h"

t_node	*find_min_cost(t_stack *stack_b)
{
	t_node	*current;
	t_node	*min_cost;

	current = stack_b->head;
	min_cost = current;
	current = current->next;
	while (current != NULL)
	{
		if (min_cost->cost <= current->cost)
			current = current->next;
		else
		{
			min_cost = current;
			current = current->next;
		}
	}
	return (min_cost);
}

bool	is_sort(t_stack *stack_a)
{
	t_node	*current;

	current = stack_a->head;
	while (current->next != NULL)
	{
		if (current->value > current->next->value)
			return (false);
		current = current->next;
	}
	return (true);
}

void	put_best_node_top(t_stack *stack_a, t_stack *stack_b, t_node *min,
		t_node *best)
{
	int	i;

	i = 0;
	if (min->median)
		while (min->index != 1)
			rotate_b(stack_b, stack_a, true);
	else
	{
		i = dll_size(stack_b) - min->index + 1;
		while (i > 0)
		{
			reverse_rotate_b(stack_b, stack_a, true);
			i--;
		}
	}
	if (best->median)
		while (best->index != 1)
			rotate_a(stack_a, stack_b, true);
	else
	{
		i = dll_size(stack_a) - best->index + 1;
		while (i > 0)
		{
			reverse_rotate_a(stack_a, stack_b, true);
			i--;
		}
	}
	push_a(stack_a, stack_b);
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	int		dll_len;
	t_node	*min_cost;
	t_node	*bestfriend;

	dll_len = dll_size(stack_b);
	while (dll_len != 1)
	{
		find_cost(stack_a, stack_b);
		min_cost = find_min_cost(stack_b);
		bestfriend = find_best_friend(stack_a, min_cost);
		put_best_node_top(stack_a, stack_b, min_cost, bestfriend);
		dll_len = dll_size(stack_b);
	}
	find_cost(stack_a, stack_b);
	min_cost = find_min_cost(stack_b);
	bestfriend = find_best_friend(stack_a, min_cost);
	put_best_node_top(stack_a, stack_b, min_cost, bestfriend);
}

void	final_rotate(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	t_node	*smallest;

	smallest = find_smallest_a(stack_a);
	index_init(stack_a);
	find_median(stack_a);
	i = dll_size(stack_a) - smallest->index + 1;
	while (i > 0)
	{
		if (smallest->median)
			rotate_a(stack_a, stack_b, true);
		else
			reverse_rotate_a(stack_a, stack_b, true);
		index_init(stack_a);
		find_median(stack_a);
		i--;
	}
}
