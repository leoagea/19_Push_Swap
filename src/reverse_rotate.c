/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 00:50:04 by lagea             #+#    #+#             */
/*   Updated: 2024/05/20 18:23:57 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/push_swap.h"

void	reverse_rotate_a(t_stack *stack_a, bool print)
{
	ssize_t	temp;

	temp = stack_a->tail->value;
	dll_delete_tail(stack_a);
	dll_insert_head(temp, stack_a);
	index_init(stack_a);
	if (print)
		write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_stack *stack_b, bool print)
{
	ssize_t	temp;

	temp = stack_b->tail->value;
	dll_delete_tail(stack_b);
	dll_insert_head(temp, stack_b);
	index_init(stack_b);
	if (print)
		write(1, "rrb\n", 4);
}

void	reverse_rotate_rr(t_stack *stack)
{
	reverse_rotate_a(stack, false);
	reverse_rotate_b(stack, false);
	write(1, "rrr\n", 4);
}
