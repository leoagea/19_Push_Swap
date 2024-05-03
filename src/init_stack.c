/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:40:03 by lagea             #+#    #+#             */
/*   Updated: 2024/05/03 18:39:23 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../inc/libft.h"

// t_node fill_stack(char **lst ,size_t len)
// {
// 	size_t i;
// 	ssize_t value;
// 	t_node first;

// 	i = 0;
// 	value = 0;
// 	while(lst [i] != NULL)
// 	{
// 		value = ft_atoi(lst [i]);
// 		if (i == 0)
// 			first = ft_lstnew(value);
// 		else
// 		{
// 		}
// 		i++;
// 	}
// }

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

void exit_error(t_stack *stack, char **lst)
{
	size_t i;

	i = 0;
	while (*lst != NULL)
		free(lst[i++]);
	free(lst);
	if (stack)
	{
		free(stack);
		write(2, "Error Parsing\n", 14);
    	system("leaks a.out");
		exit(0);
	}
	exit(0);
}

size_t check_error(t_stack *stack, char **lst)
{
	size_t i;
	size_t j;

	i = -1;
	j = -1;
	while (lst [++i])
	{
		while (lst [i][++j])
			if (ft_isalpha((int)lst [i][j]))
				exit_error(stack,lst);
		if (ft_atoi(lst [i]) > INT_MAX)
			exit_error(stack,lst);
	}
	return 1;
}