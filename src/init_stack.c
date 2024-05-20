/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:40:03 by lagea             #+#    #+#             */
/*   Updated: 2024/05/20 18:30:37 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/push_swap.h"

t_stack	*stack_init(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->tail = NULL;
	return (stack);
}

void	index_init(t_stack *stack)
{
	int		index;
	t_node	*current;

	index = 1;
	current = stack->head;
	while (current != NULL)
	{
		current->index = index;
		index++;
		current = current->next;
	}
}

void	index_init_stack(t_stack *stack_a, t_stack *stack_b)
{
	int		index;
	t_node	*current;

	index = 1;
	current = stack_a->head;
	while (current != NULL)
	{
		current->index = index++;
		current = current->next;
	}
	index = 1;
	current = stack_b->head;
	while (current != NULL)
	{
		current->index = index++;
		current = current->next;
	}
}

void	find_median(t_stack *stack)
{
	int		dll_len;
	int		median_stack;
	t_node	*current;

	dll_len = dll_size(stack);
	median_stack = (dll_len / 2) + 1;
	current = stack->head;
	while (current != NULL)
	{
		if (current->index <= median_stack)
			current->median = true;
		else
			current->median = false;
		current = current->next;
	}
}

void	print_stack(t_stack *stack)
{
	t_node	*temp;

	temp = stack->head;
	if (temp == NULL)
	{
		ft_printf("Liste vide");
		return ;
	}
	while (temp != NULL)
	{
		printf("[%zd]\n", temp->value);
		temp = temp->next;
	}
}
