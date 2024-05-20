/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:56:47 by lagea             #+#    #+#             */
/*   Updated: 2024/05/20 13:18:09 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/push_swap.h"

void push_swap(t_stack *stack_a, t_stack *stack_b)
{
	t_node *min_cost;
	t_node *bestfriend;
	
	if (dll_size(stack_a) == 3)
		sort_three_elements(stack_a,stack_b);
	else if (dll_size(stack_a) == 5)
	{
		sort_five_elements(stack_a, stack_b);}
	else
	{
		sort_until_5(stack_a, stack_b);
		sort_five_elements(stack_a, stack_a);
		sort(stack_a, stack_b);
		// final_rotate(stack_a);
	}
}

void sort_until_5(t_stack *stack_a, t_stack *stack_b)
{
	int dll_len;
	float average;
	
	dll_len = dll_size(stack_a);
	while(dll_len > 5)
	{
		average = find_average(stack_a);	
		if (stack_a->head->value < average)
		{
			push_b(stack_a, stack_b);
			find_average(stack_a);
		}
		else
			rotate_a(stack_a, true);
		dll_len = dll_size(stack_a);
	}
}