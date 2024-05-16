/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:14:07 by lagea             #+#    #+#             */
/*   Updated: 2024/05/16 18:04:32 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/push_swap.h"

t_node	*find_min_cost(t_stack *stack)
{
	t_node	*current;
	t_node	*min_cost;

	current = stack->a->head;
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

void	sort(t_stack *stack, t_node *closest, t_node *min_cost)
{
	t_node	*current;

	current = stack->a->head;
	while (stack->a->head != min_cost || stack->b->head != closest)
	{
		if (min_cost->median && closest->median && min_cost->index != 1
			&& closest->index != 1)
			rotate_rr(stack);
		else if (!min_cost->median && !closest->median && min_cost->index != 1
			&& closest->index != 1)
			reverse_rotate_rr(stack);
		else if (min_cost->median && min_cost->index != 1)
			rotate_a(stack);
		else if (!min_cost->median && min_cost->index != 1)
			reverse_rotate_a(stack);
		else if (closest->median && closest->index != 1)
			rotate_b(stack);
		else if (!closest->median && closest->index != 1)
			reverse_rotate_b(stack);
		index_init_stack(stack);
		find_median(stack->a);
		find_median(stack->b);
	}
	push_b(stack);
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

void	push_swap(t_stack *stack)
{
	int		dll_len;

	dll_len = dll_size(stack->a);
	if (dll_len == 3)
	{
		sort_three_elements(stack);
		exit_stack(stack);
	}
	if (dll_len == 5)
	{
		sort_five_elements(stack);
		exit_stack(stack);
	}
	push_b(stack);
	push_b(stack);
	while (dll_len != 3)
		sort_until_3(stack);
	sort_three_elements(stack);
	dll_len = dll_size(stack->b);
	while (dll_len != 0)
	{
		final_sort(stack);
		dll_len = dll_size(stack->b);
	}
	final_rotate(stack);
}

void sort_until_3(t_stack *stack)
{
	size_t dll_len;
	t_node	*closest;
	t_node	*min_cost;
	
	index_init_stack(stack);
	find_median(stack->a);
	find_median(stack->b);
	find_cost_stack(stack);
	min_cost = find_min_cost(stack);
	closest = find_closest(stack, min_cost);
	sort(stack, closest, min_cost);
	dll_len = dll_size(stack->a);
	exit(1);
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

void	final_sort(t_stack *stack)
{
	t_node	*head_a;
	t_node	*head_b;
	t_node	*target;

	head_a = stack->a->head;
	head_b = stack->b->head;
	target = find_target_pushback(stack, stack->b->head);
	// printf("closest de %zd : %zd\n",stack->b->head->value,target->value);
	if (target == stack->a->tail)
	{
		// printf("test if\n");
		push_a(stack);
	}
	else
	{
		// printf("test else\n");
		while (stack->a->tail != target)
		{
			// printf("test 10\n");
			reverse_rotate_a(stack);
		}
		push_a(stack);
	}
}

t_node	*find_target_pushback(t_stack *stack, t_node *node)
{
	t_node	*biggest;
	t_node	*smallest;
	t_node	*current;
	t_node	*closest;

	biggest = find_biggest_a(stack);
	smallest = find_smallest_a(stack);
	if (node->value < smallest->value)
		return (biggest);
	else if (node->value > biggest->value)
		return (biggest);
	closest = smallest;
	current = stack->a->head;
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

void	final_rotate(t_stack *stack)
{
	t_node *smallest;

	smallest = find_smallest_a(stack);
	find_median(stack->a);
	if (smallest->median)
	{
		while (stack->a->head != smallest)
			rotate_a(stack);
	}
	else if (!smallest->median)
	{
		while (stack->a->head != smallest)
			reverse_rotate_a(stack);
	}
	
}
