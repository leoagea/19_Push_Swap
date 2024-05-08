/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:14:07 by lagea             #+#    #+#             */
/*   Updated: 2024/05/08 12:40:55 by lagea            ###   ########.fr       */
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