/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 00:37:33 by lagea             #+#    #+#             */
/*   Updated: 2024/05/17 16:19:07 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/push_swap.h"

void	rotate_a(t_stack *stack)
{
	ssize_t	temp;

	temp = stack->a->head->value;
	dll_delete_head(stack->a);
	dll_insert_tail(temp, stack->a);
	index_init(stack->a);
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack *stack)
{
	ssize_t	temp;

	temp = stack->b->head->value;
	dll_delete_head(stack->b);
	dll_insert_tail(temp, stack->b);
	index_init(stack->b);
	write(1, "rb\n", 3);
}

void	rotate_rr(t_stack *stack)
{
	rotate_a(stack);
	rotate_b(stack);
	write(1, "rr\n", 3);
}
