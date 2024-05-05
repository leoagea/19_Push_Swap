/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea < lagea@student.s19.be >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 00:37:33 by lagea             #+#    #+#             */
/*   Updated: 2024/05/06 00:40:07 by lagea            ###   ########.fr       */
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