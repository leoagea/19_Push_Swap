/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 00:37:33 by lagea             #+#    #+#             */
/*   Updated: 2024/05/22 14:37:08 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/push_swap.h"

void	rotate_a(t_stack *stack_a, t_stack *stack_b, bool print)
{
	ssize_t	temp;

	if (stack_a->head == NULL)
		exit_error_cmd(stack_a, stack_b);
	temp = stack_a->head->value;
	dll_delete_head(stack_a);
	dll_insert_tail(temp, stack_a);
	index_init(stack_a);
	if (print)
		write(1, "ra\n", 3);
}

void	rotate_b(t_stack *stack_b, t_stack *stack_a, bool print)
{
	ssize_t	temp;

	if (stack_b->head == NULL)
		exit_error_cmd(stack_a, stack_b);
	temp = stack_b->head->value;
	dll_delete_head(stack_b);
	dll_insert_tail(temp, stack_b);
	index_init(stack_b);
	if (print)
		write(1, "rb\n", 3);
}

void	rotate_rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate_a(stack_a, stack_b, false);
	rotate_b(stack_b, stack_a, false);
	write(1, "rr\n", 3);
}
