/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:14:07 by lagea             #+#    #+#             */
/*   Updated: 2024/05/14 18:33:44 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/push_swap.h"

// void sort_a(t_stack *stack)
// {
// 	int index;
// 	t_node *node;

// 	index = find_min_cost(stack);
// 	printf("\n\nindex min cost : %d\n\n",index);
// 	node = stack->a->head;
// 	while (node->index != index)
// 		node = node->next;
// 	int dll_len;

// 	dll_len = dll_size(stack->a);
// 	while (node->index != 1)
// 	{
// 		if (node->index <= node->median && index != 1)
// 		{
// 			rotate_a(stack);
// 		}
// 		else if(node->index > node->median)
// 		{
// 			reverse_rotate_a(stack);
// 		}
// 		index_init(stack->a);
// 	}
// }

// void sort_b(t_stack *stack)
// {
// 	int index;
// 	int dll_len;
// 	t_node *node;

// 	index = find_closest(stack, stack->a->head->value);
// 	find_median(stack->b);
// 	printf("\n\nindex stack b : %i\n\n", index);
// 	dll_len = dll_size(stack->b);
// 	node = stack->b->head;
// 	while (node->index != index)
// 		node = node->next;
// 	while (node->index != 1)
// 	{
// 		if (node->index <= node->median && index != 1)
// 		{
// 			rotate_b(stack);
// 		}
// 		else if(node->index > node->median)
// 		{
// 			reverse_rotate_b(stack);
// 		}
// 		index_init(stack->a);
// 	}
// }

// implementer sort a et sort b en meme temps pour pouvoir faire des rotate r et rev rotate r

t_node	*find_min_cost(t_stack *stack)
{
	t_node	*current;
	t_node	*min_cost;

	current = stack->a->head;
	min_cost = current;
	current = current->next;
	while (current != NULL)
	{
		if (min_cost->cost <= current->cost)
			current = current->next;
		else
		{
			min_cost = current;
			current = current->next;
		}
	}
	return (min_cost);
}

void	sort(t_stack *stack, t_node *closest, t_node *min_cost)
{
	int		i;
	t_node	*current;

	i = 0;
	current = stack->a->head;
	while (stack->a->head != min_cost || stack->b->head != closest)
	{
		if (min_cost->median && closest->median && min_cost->index != 1
			&& closest->index != 1)
			rotate_rr(stack);
		else if (!min_cost->median && !closest->median && min_cost->index != 1 
			&& closest->index != 1)
			reverse_rotate_rr(stack);
		else if (min_cost->median && min_cost->index != 1)
			rotate_a(stack);
		else if (!min_cost->median && min_cost->index != 1)
			reverse_rotate_a(stack);
		else if (closest->median && closest->index != 1)
			rotate_b(stack);
		else if (!closest->median && closest->index != 1)
			reverse_rotate_b(stack);
		index_init_stack(stack);
		find_median(stack->a);
		find_median(stack->b);
	}
	push_b(stack);
}

t_node *find_biggest_a(t_stack *stack)
{
	int biggest_a;
	t_node *current;
	t_node *biggest;

	biggest_a = 0;
	current = stack->a->head;
	while (current != NULL)
	{
		if(biggest_a < current->value)
		{
			biggest_a = current->value;
			biggest = current;
		}
		current = current->next;
	}	
	return biggest;
}

t_node *find_smallest_a(t_stack *stack)
{
	int smallest_a;
	t_node *current;
	t_node *smallest;

	current = stack->a->head;
	smallest_a = current->value;
	while (current != NULL)
	{
		if(smallest_a < current->value)
			current = current->next;
		else
		{
			smallest_a = current->value;
			smallest = current;
			current = current->next;
		}
	}	
	return smallest;
}

void sort_three_elements(t_stack *stack)
{
	t_node *biggest;
	t_node *smallest;
	
	if (is_sort(stack))
	{
		// printf("Is already sorted\n");
		return ;}
	biggest = find_biggest_a(stack);
	smallest = find_smallest_a(stack);
	// printf("Biggest stack a : %zu\n", biggest->value);
	// printf("Smallest stack a : %zd\n", smallest->value);
	if (smallest->index == 2 && biggest->index == 3)
	{
		// printf("Test 1\n");
		swap_a(stack);
	}
	else if (smallest->index == 2 && biggest->index == 1){
		// printf("Test 2\n");
		rotate_a(stack);}
	else if (smallest->index == 3 && biggest->index == 2){
		// printf("Test 3\n");
		reverse_rotate_a(stack);}
	else if (smallest->index == 1 && biggest->index == 2)
	{
		// printf("Test 4\n");
		reverse_rotate_a(stack);
		swap_a(stack);
	}
	else if (smallest->index == 3 && biggest->index == 1)
	{
		// printf("Test 4\n");
		rotate_a(stack);
		swap_a(stack);
	}
	// printf("Test\n");
}

bool is_sort(t_stack *stack)
{
	t_node *current;

	current = stack->a->head;
	while (current->next != NULL)
	{
		if (current->value > current->next->value)
			return false;
		current = current->next;
	}
	return true;
}

void push_swap(t_stack *stack)
{
	int dll_len;
	t_node *closest;
    t_node *min_cost;
	
	dll_len = dll_size(stack->a);
    while (dll_len != 3)
    {
        index_init_stack(stack);
        find_median(stack->a);
        find_median(stack->b);
        find_cost_stack(stack);
        min_cost = find_min_cost(stack);
        closest = find_closest(stack,min_cost);
        sort(stack,closest,min_cost);
        dll_len = dll_size(stack->a);
    }
    sort_three_elements(stack);
	dll_len = dll_size(stack->b);
	while (dll_len != 0)
	{
		final_sort(stack);
		dll_len = dll_size(stack->b);
	}
	final_rotate(stack);
}

void final_sort(t_stack *stack)
{
	t_node *head_a;
	t_node *head_b;
	t_node *biggest_b;
	t_node *target;

	head_a = stack->a->head;
	head_b = stack->b->head;
	target = find_target_pushback(stack,stack->b->head);
	// printf("closest de %zd : %zd\n",stack->b->head->value,target->value);
	if (target == stack->a->tail){
		// printf("test if\n");
		push_a(stack);
	}
	else
	{
		// printf("test else\n");
		while (stack->a->tail != target)
		{	
			// printf("test 10\n");
			reverse_rotate_a(stack);
		}
		push_a(stack);
	}
	
}

t_node *find_target_pushback(t_stack *stack, t_node *node)
{
	t_node *biggest;
	t_node *smallest;
	t_node *current;
	t_node *closest;
	
	biggest = find_biggest_a(stack);
	smallest = find_smallest_a(stack);

	if (node->value < smallest->value)
		return biggest;
	else if (node->value > biggest->value)
		return biggest;
	closest = smallest;
	current = stack->a->head;
	while (current != NULL)
	{
		if (current->value > closest->value && current->value < node->value)
		{
			closest = current;
			current = current->next;
		}
		else
			current = current->next;
	}
	return closest;
}

void final_rotate(t_stack *stack)
{
	t_node *smallest;

	smallest = find_smallest_a(stack);
	while (stack->a->head != smallest)
	{	
		rotate_a(stack);
	}
}