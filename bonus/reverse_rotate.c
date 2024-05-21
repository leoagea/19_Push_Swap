/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 00:50:04 by lagea             #+#    #+#             */
/*   Updated: 2024/05/21 18:08:58 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/push_swap.h"

void	reverse_rotate_a(t_stack *stack_a, t_stack *stack_b, bool print)
{
	ssize_t	temp;

	if (stack_a->head == NULL)
		exit_error_cmd(stack_a, stack_b);
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

	if (stack_b->head == NULL)
		exit_error_cmd(stack_a, stack_b);
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
