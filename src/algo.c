/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:56:47 by lagea             #+#    #+#             */
/*   Updated: 2024/05/17 14:45:03 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/push_swap.h"

void push_swap(t_stack *stack)
{
	int dll_len;
	t_node *min_cost;
	t_node *bestfriend;
	
	dll_len = dll_size(stack->b);
	sort_until_5(stack);
	sort_five_elements(stack);
	sort(stack);
	final_rotate(stack);
}

void sort_until_5(t_stack *stack)
{
	int dll_len;
	float average;
	
	dll_len = dll_size(stack->a);
	while(dll_len != 5)
	{
		average = find_average(stack);	
		if (stack->a->head->value < average)
		{
			push_b(stack);
			find_average(stack);
		}
		else
			rotate_a(stack);
		dll_len = dll_size(stack->a);
	}
}