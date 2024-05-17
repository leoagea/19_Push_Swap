/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:14:07 by lagea             #+#    #+#             */
/*   Updated: 2024/05/17 15:09:23 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/push_swap.h"

t_node	*find_min_cost(t_stack *stack)
{
	t_node	*current;
	t_node	*min_cost;

	current = stack->b->head;
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

void	sort_three_elements(t_stack *stack)
{
	t_node	*biggest;
	t_node	*smallest;

	if (is_sort(stack))
		return ;
	index_init(stack->a);
	biggest = find_biggest_a(stack);
	smallest = find_smallest_a(stack);
	if (smallest->index == 2 && biggest->index == 3)
		swap_a(stack);
	else if (smallest->index == 2 && biggest->index == 1)
		rotate_a(stack);
	else if (smallest->index == 3 && biggest->index == 2)
		reverse_rotate_a(stack);
	else if (smallest->index == 3 && biggest->index == 1)
	{
		rotate_a(stack);
		swap_a(stack);
	}
	else if (smallest->index == 1 && biggest->index == 2)
	{
		reverse_rotate_a(stack);
		swap_a(stack);
	}
}

void sort_five_elements(t_stack *stack)
{
	t_node *smallest;

	find_median(stack->a);
	smallest = find_smallest_a(stack);
	while (smallest->index != 1)
	{
		if (smallest->median)
			rotate_a(stack);
		else
			reverse_rotate_a(stack);
	}
	push_b(stack);
	find_median(stack->a);
	smallest = find_smallest_a(stack);
	while (smallest->index != 1)
	{
		if (smallest->median)
			rotate_a(stack);
		else
			reverse_rotate_a(stack);
	}
	push_b(stack);
	sort_three_elements(stack);
	push_a(stack);
	push_a(stack);
}

bool	is_sort(t_stack *stack)
{
	t_node	*current;

	current = stack->a->head;
	while (current->next != NULL)
	{
		if (current->value > current->next->value)
			return (false);
		current = current->next;
	}
	return (true);
}

void put_best_node_top(t_stack *stack, t_node *min, t_node *best)
{
	if (min->median)
		while(min->index != 1)
		{
			rotate_b(stack);
			index_init(stack->b);
		}
	else
		while(min->index != 1)
		{
			reverse_rotate_b(stack);
			index_init(stack->b);
		}
	if (best->median)
		while (best->index != 1)
		{
			rotate_a(stack);
			index_init(stack->b);
		}
	else
		while (best->index != 1)
		{
			reverse_rotate_a(stack);
			index_init(stack->b);
		}
	push_a(stack);
}

void sort(t_stack *stack)
{
	int dll_len;
	t_node *min_cost;
	t_node *bestfriend;

	dll_len = dll_size(stack->b);
	while (dll_len != 1)
	{
		find_cost(stack);
		min_cost = find_min_cost(stack);
		bestfriend = find_best_friend(stack,min_cost);
		// printf("min cost : %zd, bestfriend : %zd", min_cost->value,bestfriend->value);
		put_best_node_top(stack,min_cost,bestfriend);
		dll_len = dll_size(stack->b);
	}
	find_cost(stack);
	min_cost = find_min_cost(stack);
	bestfriend = find_best_friend(stack,min_cost);
	put_best_node_top(stack,min_cost,bestfriend);
}

void final_rotate(t_stack *stack)
{
	t_node *smallest;

	smallest = find_smallest_a(stack);
	find_median(stack->a);
	while (smallest->index != 1)
	{
		if (smallest->median)
			rotate_a(stack);
		else 
			reverse_rotate_a(stack);
		find_median(stack->a);
		index_init(stack->a);
	}
}