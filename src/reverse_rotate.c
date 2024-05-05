/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea < lagea@student.s19.be >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 00:50:04 by lagea             #+#    #+#             */
/*   Updated: 2024/05/06 00:56:44 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../inc/libft.h"

void reverse_rotate_a(t_stack *stack)
{
    ssize_t temp;

    temp = stack->a->tail->value;
    dll_delete_tail(stack->a);
    dll_insert_head(temp,stack->a);
}

void reverse_rotate_b(t_stack *stack)
{
    ssize_t temp;

    temp = stack->b->tail->value;
    dll_delete_tail(stack->b);
    dll_insert_head(temp,stack->b);
}

void reverse_rotate_rr(t_stack *stack)
{
    reverse_rotate_a(stack);
    reverse_rotate_b(stack);
}
