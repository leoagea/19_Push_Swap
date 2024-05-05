/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea < lagea@student.s19.be >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 20:44:30 by lagea             #+#    #+#             */
/*   Updated: 2024/05/05 23:53:38 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/push_swap.h"

void move_sa(t_stack *stack)
{
	t_node *temp;

	if (dll_size(stack->a) <= 2)
		return ;
	temp = dll_new_node(stack->a->head->value);
	stack->a->head->value = stack->a->head->next->value;
	stack->a->head->next->value = temp->value;
	free(temp);
}

void move_sb(t_stack *stack)
{
	t_node *temp;

	if (dll_size(stack->b) <= 2)
		return ;
	temp = dll_new_node(stack->b->head->value);
	stack->b->head->value = stack->b->head->next->value;
	stack->b->head->next->value = temp->value;
	free(temp);
}

void move_ss(t_stack *stack)
{
	if (dll_size(stack->a) <= 2 || dll_size(stack->b) <= 2)
		return ;
	move_sa(stack);
	move_sb(stack);
}

void push_a(t_stack *stack)
{
	t_node *temp;
	
	if(dll_size(stack->b) == 0)
		return ;
	temp = stack->b->head;
	dll_insert_head(temp->value,stack->a);
	stack->b->head = temp->next;
}
