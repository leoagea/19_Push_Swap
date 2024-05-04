/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:40:03 by lagea             #+#    #+#             */
/*   Updated: 2024/05/04 21:09:53 by lagea            ###   ########.fr       */
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

void stack_cpy_a_to_b(t_stack *stack)
{

	// Segfault a corriger
	
	ssize_t cpy_value;
	t_node *current_a;
	t_node *current_b;
	

	current_a = stack->a->head;
	current_b = stack->b->head;
	while (current_a != NULL)
	{
		printf("test 1\n");
		cpy_value = current_a->value;
		printf("print value : %zd\n",cpy_value);
		current_b->value = cpy_value;
		printf("test 2\n");
		current_a = current_a->next;
		current_b = current_b->next;
	}
	printf("test 2\n");

	// free(current_a);
	// free(current_b);
}

