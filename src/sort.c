/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:14:07 by lagea             #+#    #+#             */
/*   Updated: 2024/05/13 18:20:26 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../inc/libft.h"

// void sort_a(t_stack *stack)
// {
// 	int index;
// 	t_node *node;
	
// 	index = find_min_cost(stack);
// 	printf("\n\nindex min cost : %d\n\n",index);
// 	node = stack->a->head;
// 	while (node->index != index)
// 		node = node->next;
// 	int dll_len;

// 	dll_len = dll_size(stack->a);
// 	while (node->index != 1)
// 	{
// 		if (node->index <= node->median && index != 1)
// 		{
// 			rotate_a(stack);
// 		}
// 		else if(node->index > node->median)
// 		{		
// 			reverse_rotate_a(stack);
// 		}
// 		index_init(stack->a);
// 	}
// }

// void sort_b(t_stack *stack)
// {
// 	int index;
// 	int dll_len;
// 	t_node *node;
	
// 	index = find_closest(stack, stack->a->head->value);
// 	find_median(stack->b);
// 	printf("\n\nindex stack b : %i\n\n", index);
// 	dll_len = dll_size(stack->b);
// 	node = stack->b->head;
// 	while (node->index != index)
// 		node = node->next;
// 	while (node->index != 1)
// 	{
// 		if (node->index <= node->median && index != 1)
// 		{
// 			rotate_b(stack);
// 		}
// 		else if(node->index > node->median)
// 		{		
// 			reverse_rotate_b(stack);
// 		}
// 		index_init(stack->a);
// 	}
// }

// implementer sort a et sort b en meme temps pour pouvoir faire des rotate r et rev rotate r

t_node *find_min_cost(t_stack *stack)
{
	t_node *current;
	t_node *min_cost;
	
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
	return min_cost;
}

void sort(t_stack *stack, t_node *closest, t_node *min_cost)
{
	int i;
	t_node *current;
	
	i = 0;
	current = min_cost;
	while (stack->a->head != min_cost)
	{
		if (min_cost->median && closest->median && min_cost->index != 1 && closest->index != 1)
			rotate_rr(stack);
		else if (min_cost->median && closest->median && min_cost->index != 1 && closest->index != 1)
			reverse_rotate_rr(stack);
		else if (min_cost->median && closest->median && min_cost->index != 1 && closest->index != 1)
			rotate_a(stack);
		else if (min_cost->median && closest->median && min_cost->index != 1 && closest->index != 1)
			reverse_rotate_a(stack);
		else if (min_cost->median && closest->median && min_cost->index != 1 && closest->index != 1)
			rotate_b(stack);
		else if (min_cost->median && closest->median && min_cost->index != 1 && closest->index != 1)
			reverse_rotate_b(stack);
		index_init(stack->a);
		index_init(stack->b);
		find_median(stack->a);		
		find_median(stack->b);		
	}
	push_b(stack);
}
