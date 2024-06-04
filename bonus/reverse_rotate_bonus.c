/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 00:50:04 by lagea             #+#    #+#             */
/*   Updated: 2024/06/04 12:56:44 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/push_swap.h"

void	reverse_rotate_a(t_stack *stack_a, t_stack *stack_b, bool print)
{
	ssize_t	temp;

	(void)stack_b;
	if (stack_a->head == NULL)
		return ;
	temp = stack_a->tail->value;
	dll_delete_tail(stack_a);
	dll_insert_head(temp, stack_a);
	index_init(stack_a);
	if (print)
		write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_stack *stack_b, t_stack *stack_a, bool print)
{
	ssize_t	temp;

	(void)stack_a;
	if (stack_b->head == NULL)
		return ;
	temp = stack_b->tail->value;
	dll_delete_tail(stack_b);
	dll_insert_head(temp, stack_b);
	index_init(stack_b);
	if (print)
		write(1, "rrb\n", 4);
}

void	reverse_rotate_rr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate_a(stack_a, stack_b, false);
	reverse_rotate_b(stack_b, stack_a, false);
	write(1, "rrr\n", 4);
}
