/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:40:03 by lagea             #+#    #+#             */
/*   Updated: 2024/05/06 17:15:45 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../inc/libft.h"

t_stack *stack_init()
{
	struct dll_edge *edge_a;
	struct dll_edge *edge_b;
	t_stack *stack;
	
	edge_a = dll_init();
	edge_b = dll_init();
	stack = malloc(sizeof(t_stack));
	stack->a = edge_a;
	stack->b = edge_b;
	return(stack);
}

void index_init(struct dll_edge *edge)
{
	int index;
	t_node *current;

	index = 1;
	current = edge->head;
	while (current != NULL)
	{
		current->index = index++;
		current = current->next;
	}
}

void index_init_stack(t_stack *stack)
{
	int index;
	t_node *current;

	index = 1;
	current = stack->a->head;
	while (current != NULL)
	{
		current->index = index++;
		current = current->next;
	}
	index = 1;
	current = stack->b->head;
	while (current != NULL)
	{
		current->index = index++;
		current = current->next;
	}
}

void stack_print_forward(t_stack *stack,char c)
{
	t_node *current;

	if (c == 'a')
	{
		current = stack->a->head;
		while (current != NULL)
		{
			printf("%zd\n",current->value);
			current = current->next;
		}
	}
	else if (c == 'b')
	{
		current = stack->b->head;
		while (current != NULL)
		{
			printf("%zd\n",current->value);
			current = current->next;
		}
	}
}

void print_2_stack(t_stack *stack)
{
	t_node *current_a;
	t_node *current_b;

	current_a = stack->a->head;
	current_b = stack->b->head;
	printf("Stack a			stack b\n");
	while (current_a != NULL && current_b != NULL)
	{
		printf("%zd			%zd\n",current_a->value, current_b->value);
		current_a = current_a->next;
		current_b = current_b->next;
	}
}



