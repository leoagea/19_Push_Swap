/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 20:44:30 by lagea             #+#    #+#             */
/*   Updated: 2024/05/14 18:49:17 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/push_swap.h"

void	swap_a(t_stack *stack)
{
	t_node	*temp;

	if (dll_size(stack->a) <= 2)
		return ;
	temp = dll_new_node(stack->a->head->value);
	stack->a->head->value = stack->a->head->next->value;
	stack->a->head->next->value = temp->value;
	index_init(stack->a);
	free(temp);
	write(1, "sa\n", 3);
}

void	swap_b(t_stack *stack)
{
	t_node	*temp;

	if (dll_size(stack->b) <= 2)
		return ;
	temp = dll_new_node(stack->b->head->value);
	stack->b->head->value = stack->b->head->next->value;
	stack->b->head->next->value = temp->value;
	index_init(stack->b);
	free(temp);
	write(1, "sb\n", 3);
}

void	swap_ss(t_stack *stack)
{
	if (dll_size(stack->a) <= 2 || dll_size(stack->b) <= 2)
		return ;
	swap_a(stack);
	swap_b(stack);
	write(1, "ss\n", 3);
}

void	push_a(t_stack *stack)
{
	t_node	*temp;

	if (dll_size(stack->b) == 0)
		return ;
	temp = stack->b->head;
	dll_insert_head(temp->value, stack->a);
	stack->b->head = temp->next;
	index_init_stack(stack);
	free(temp);
	write(1, "pa\n", 3);
}

void	push_b(t_stack *stack)
{
	t_node	*temp;

	if (dll_size(stack->a) == 0)
		return ;
	temp = stack->a->head;
	dll_insert_head(temp->value, stack->b);
	stack->a->head = temp->next;
	index_init_stack(stack);
	free(temp);
	write(1, "pb\n", 3);
}
