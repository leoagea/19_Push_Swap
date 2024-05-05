/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea < lagea@student.s19.be >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 00:37:33 by lagea             #+#    #+#             */
/*   Updated: 2024/05/06 00:46:27 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../inc/libft.h"

void rotate_a(t_stack *stack)
{
    ssize_t temp;

    temp = stack->a->head->value;
    dll_delete_head(stack->a);
    dll_insert_tail(temp,stack->a);
}

void rotate_b(t_stack *stack)
{
    ssize_t temp;

    temp = stack->b->head->value;
    dll_delete_head(stack->b);
    dll_insert_tail(temp,stack->b);
}

void rotate_rr(t_stack *stack)
{
    rotate_a(stack);
    rotate_b(stack);
}
