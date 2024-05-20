/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:14:07 by lagea             #+#    #+#             */
/*   Updated: 2024/05/20 17:04:57 by lagea            ###   ########.fr       */
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
		swap_a(stack_a, stack_b);
	else if (smallest->index == 2 && biggest->index == 1)
		rotate_a(stack_a, true);
	else if (smallest->index == 3 && biggest->index == 2)
		reverse_rotate_a(stack_a, true);
	else if (smallest->index == 3 && biggest->index == 1)
	{
		rotate_a(stack_a, true);
		swap_a(stack_a, true);
	}
	else if (smallest->index == 1 && biggest->index == 2)
	{
		reverse_rotate_a(stack_a, true);
		swap_a(stack_a, true);
	}
}

void sort_five_elements(t_stack *stack_a, t_stack *stack_b)
{
	t_node *smallest;
	
	// printf("\nIN Sort 5");
	// printf("\nStack a\n");
	// print_stack(stack_a);
	// printf("\nStack b\n");
	// print_stack(stack_b);
	
	find_median(stack_a);
	smallest = find_smallest_a(stack_a);
	while (smallest->index != 1)
	{
		if (smallest->median)
			rotate_a(stack_a, true);
		else
			reverse_rotate_a(stack_a,true);
	}
	push_b(stack_a,stack_b);
	find_median(stack_a);
	smallest = find_smallest_a(stack_a);
	while (smallest->index != 1)
	{
		if (smallest->median)
			rotate_a(stack_a, true);
		else
			reverse_rotate_a(stack_a,true);
	}
	push_b(stack_a,stack_b);
	sort_three_elements(stack_a, stack_b);
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
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

void put_best_node_top(t_stack *stack_a, t_stack *stack_b, t_node *min, t_node *best)
{
	int i;
	// int j;
	
	i = 0;
	// j = 0;
	if (min->median)
	{
		// i = min->index - 1;
		while(min->index != 1)
			rotate_b(stack_b, true);
	}
	else
	{
		i = dll_size(stack_b) - min->index + 1;
		while(i > 0)
		{
			// printf("%d \n",i);
			// write (1 , "1\n", 1);
			// index_init(stack_b);
			// printf("%d \n",min->index);
			reverse_rotate_b(stack_b, true);
			i--;
		}
	}
	if (best->median)
	{
		// i = best->index - 1;
		while (best->index != 1)
		{
			// printf("%d \n",i);
			rotate_a(stack_a, true);
		}
	}
	else
	{
		i = dll_size(stack_a) - best->index + 1;
		while (i > 0)
		{
			// index_init(stack_a);
			// printf("%d \n",best->index);
			reverse_rotate_a(stack_a, true);
			i--;
		}
	}
	push_a(stack_a, stack_b);
}

void sort(t_stack *stack_a, t_stack *stack_b)
{
	int dll_len;
	t_node *min_cost;
	t_node *bestfriend;

	dll_len = dll_size(stack_b);
	while (dll_len != 1)
	{
		find_cost(stack_a, stack_b);
		min_cost = find_min_cost(stack_b);
		bestfriend = find_best_friend(stack_a,min_cost);
		// printf("min cost : %zd, bestfriend : %zd", min_cost->value,bestfriend->value);
		put_best_node_top(stack_a, stack_b, min_cost, bestfriend);
		dll_len = dll_size(stack_b);
	}
	find_cost(stack_a, stack_b);
	min_cost = find_min_cost(stack_b);
	bestfriend = find_best_friend(stack_a, min_cost);
	put_best_node_top(stack_a, stack_b, min_cost, bestfriend);
}


void final_rotate(t_stack *stack_a)
{
	t_node *smallest;

	smallest = find_smallest_a(stack_a);
	index_init(stack_a);
	find_median(stack_a);
	while (smallest->index != 1)
	{
		// printf("smal val : %zd, index : %d\n", smallest->value,smallest->index);
		if (smallest->median)
			rotate_a(stack_a, true);
		else 
			reverse_rotate_a(stack_a, true);
		index_init(stack_a);
		find_median(stack_a);
		// printf("smal val : %zd, index : %d\n", smallest->value,smallest->index);
	}
}