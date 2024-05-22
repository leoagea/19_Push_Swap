/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 20:44:30 by lagea             #+#    #+#             */
/*   Updated: 2024/05/22 17:48:50 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/push_swap.h"

void	swap_a(t_stack *stack_a, t_stack *stack_b, bool print)
{
	t_node	*temp;

	if (dll_size(stack_a) < 2 && stack_b == NULL)
		return ;
	else if (dll_size(stack_a) < 2 && stack_b != NULL)
		exit_error_cmd(stack_a, stack_b);
	temp = dll_new_node(stack_a->head->value);
	stack_a->head->value = stack_a->head->next->value;
	stack_a->head->next->value = temp->value;
	index_init(stack_a);
	free(temp);
	if (print)
		write(1, "sa\n", 3);
}

void	swap_b(t_stack *stack_b, t_stack *stack_a, bool print)
{
	t_node	*temp;

	if (dll_size(stack_b) < 2 && stack_a == NULL)
		return ;
	else if (dll_size(stack_b) < 2 && stack_a != NULL)
		exit_error_cmd(stack_a, stack_b);
	temp = dll_new_node(stack_b->head->value);
	stack_b->head->value = stack_b->head->next->value;
	stack_b->head->next->value = temp->value;
	index_init(stack_b);
	free(temp);
	if (print)
		write(1, "sb\n", 3);
}

void	swap_ss(t_stack *stack_a, t_stack *stack_b)
{
	if (dll_size(stack_a) < 2 || dll_size(stack_b) < 2)
		return ;
	swap_a(stack_a, NULL, false);
	swap_b(stack_b, NULL, false);
	write(1, "ss\n", 3);
}

void	push_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp;

	if (dll_size(stack_b) == 0)
		return ;
	temp = stack_b->head;
	dll_insert_head(temp->value, stack_a);
	stack_b->head = temp->next;
	index_init_stack(stack_a, stack_b);
	free(temp);
	write(1, "pa\n", 3);
}

void	push_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp;

	if (dll_size(stack_a) == 0)
		return ;
	temp = stack_a->head;
	dll_insert_head(temp->value, stack_b);
	stack_a->head = temp->next;
	index_init_stack(stack_a, stack_b);
	free(temp);
	write(1, "pb\n", 3);
}
