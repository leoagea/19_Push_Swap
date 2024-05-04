/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 20:44:30 by lagea             #+#    #+#             */
/*   Updated: 2024/05/04 20:49:51 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/push_swap.h"

void move_sa(t_stack *stack)
{
	t_node *temp;

	temp = dll_new_node(stack->a->head->value);
	stack->a->head->value = stack->a->head->next->value;
	stack->a->head->next->value = temp->value;
	free(temp);
}