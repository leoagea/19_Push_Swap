/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:40:03 by lagea             #+#    #+#             */
/*   Updated: 2024/05/13 14:35:39 by lagea            ###   ########.fr       */
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
		if (current_a != NULL)
			current_a = current_a->next;
		else if (current_b != NULL)
			current_b = current_b->next;
	}
}
// trouve la median de la stack et assigne 1 si above median
// ou 0 si under median
void find_median(struct dll_edge *stack)
{
	int dll_len;
	int median_stack;
	t_node *current;
	
	dll_len = dll_size(stack);
	median_stack = (dll_len / 2) + 1;
	current = stack->head;
	while (current != NULL)
	{
		// printf("median : %d, current index = %d ", median_stack, current->index);
		if(current->index <= median_stack)
		{
			// printf("test\n");
			current->median = true;
		}
		else{
			// printf("test 1\n");
			current->median = false;
		}
		current = current->next;
	}
}

// int find_cost_b(t_stack *stack, t_node *node)
// {
// 	int index_clos;
// 	int temp;
	
// 	temp = 0;
// 	index_clos = find_closest(stack, node->value);
// 	printf("index_clos : %d\n",index_clos);
// 	if (index_clos == 1)
// 		return 0;
// 	// printf("value : %zd ,index closest : %d\n",node->value,index_clos);
// 	if (index_clos > stack->b->head->median)
// 		temp = dll_size(stack->b) + 1;
// 	else if (index_clos <= stack->b->head->median)
// 		temp = index_clos - 1;
// 	printf("temp : %d\n",temp);
// 	return temp;
// }

// void find_cost(t_stack *stack,t_node *node)
// {
// 	int dll_len;
// 	int temp;
	
// 	temp = 0;
// 	dll_len = dll_size(stack->a);
// 	if (node->index <= node->median)
// 	{
// 		temp = node->index - 1;
// 	}
// 	else if(node->index > node->median)
// 	{		
// 		temp = dll_len - node->index + 1;
// 	}
// 	// printf("value : %zd, cost_b : %d\n",node->value,find_cost_b(stack,node));
// 	temp += find_cost_b(stack,node);
// 	temp += 1;
// 	node->cost = temp;
// }

// void cost_stack(t_stack *stack)
// {
// 	t_node *current;
	
// 	find_median(stack->a);
// 	current = stack->a->head;
// 	while (current != NULL)
// 	{
// 		if (current->value < smallest_b(stack))
// 		{
// 			current->cost = 1;
// 			current = current->next;
// 		}
// 		else
// 		{
// 			find_cost(stack, current);
// 			current = current->next;
// 		}
// 	}
// }

// int find_min_cost(t_stack *stack)
// {
// 	int min_cost;
// 	t_node *current;

// 	current = stack->a->head;
// 	min_cost = current->cost;
// 	current = current->next;
// 	while (current != NULL)
// 	{
// 		if (current->cost < min_cost)
// 			min_cost = current->cost;
// 		current = current->next;
// 	}
// 	current = stack->a->head;
// 	while (current != NULL)
// 	{
// 		if (current->cost == min_cost)
// 			return current->index;
// 		current = current->next;
// 	}
// 	return current->index;
// }

// int find_closest(t_stack *stack,int value)
// {
// 	t_node *current;
// 	int closest;
// 	int index;
	
// 	current = stack->b->head;
// 	closest = -1;
// 	index = 0;
// 	while(current != NULL)
// 	{
// 		if (current->value < value)
// 		{
// 			if (closest == -1 || current->value > closest)
// 			{
// 				closest = current->value;
// 				index = current->index;
// 			}
// 		}
// 		current = current->next;
// 	}
// 	return index;
// }

// int biggest_b(t_stack *stack)
// {
// 	int biggest_b;
// 	t_node *current;

// 	biggest_b = 0;
// 	current = stack->b->head;
// 	while (current != NULL)
// 	{
// 		if(biggest_b < current->value)
// 			biggest_b = current->value;
// 		current = current->next;
// 	}	
// 	return biggest_b;
// }

// int smallest_b(t_stack *stack)
// {
// 	int smallest_b;
// 	t_node *current;

// 	current = stack->b->head;
// 	smallest_b = current->value;
// 	while (current != NULL)
// 	{
// 		if(smallest_b < current->value)
// 			current = current->next;
// 		else
// 		{
// 			smallest_b = current->value;
// 			current = current->next;
// 		}
// 	}	
// 	return smallest_b;
// }
