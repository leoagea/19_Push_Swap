/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:56:47 by lagea             #+#    #+#             */
/*   Updated: 2024/05/23 12:08:11 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/push_swap.h"

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*min_cost;
	t_node	*bestfriend;

	if (stack_a->head == NULL)
		return ;
	if (dll_size(stack_a) == 1)
		return ;
	else if (dll_size(stack_a) == 2)
	{
		if (stack_a->head->value > stack_a->head->next->value)
			swap_a(stack_a, stack_b, true);
	}
	else if (dll_size(stack_a) == 3)
		sort_three_elements(stack_a, stack_b);
	else if (dll_size(stack_a) == 4)
		sort_four_elements(stack_a, stack_b);
	else if (dll_size(stack_a) == 5)
		sort_five_elements(stack_a, stack_b);
	else
	{
		sort_until_5(stack_a, stack_b);
		sort_five_elements(stack_a, stack_b);
		sort(stack_a, stack_b);
		final_rotate(stack_a, stack_b);
	}
}

void	sort_until_5(t_stack *stack_a, t_stack *stack_b)
{
	int		dll_len;
	float	average;

	dll_len = dll_size(stack_a);
	while (dll_len > 5)
	{
		average = find_average(stack_a);
		if (stack_a->head->value < average)
		{
			push_b(stack_a, stack_b);
			average = find_average(stack_a);
		}
		else
			rotate_a(stack_a, stack_b, true);
		dll_len = dll_size(stack_a);
	}
}

void	sort_three_elements(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*biggest;
	t_node	*smallest;

	if (is_sort(stack_a))
		return ;
	index_init(stack_a);
	biggest = find_biggest_a(stack_a);
	smallest = find_smallest_a(stack_a);
	if (smallest->index == 2 && biggest->index == 3)
		swap_a(stack_a, stack_b, true);
	else if (smallest->index == 2 && biggest->index == 1)
		rotate_a(stack_a, stack_b, true);
	else if (smallest->index == 3 && biggest->index == 2)
		reverse_rotate_a(stack_a, stack_b, true);
	else if (smallest->index == 3 && biggest->index == 1)
	{
		rotate_a(stack_a, stack_b, true);
		swap_a(stack_a, NULL, true);
	}
	else if (smallest->index == 1 && biggest->index == 2)
	{
		reverse_rotate_a(stack_a, stack_b, true);
		swap_a(stack_a, NULL, true);
	}
}

void	sort_four_elements(t_stack *stack_a, t_stack *stack_b)
{
	push_smallest(stack_a, stack_b);
	sort_three_elements(stack_a, stack_b);
	push_a(stack_a, stack_b);
}

void	sort_five_elements(t_stack *stack_a, t_stack *stack_b)
{
	push_smallest(stack_a, stack_b);
	push_smallest(stack_a, stack_b);
	sort_three_elements(stack_a, stack_b);
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
}
