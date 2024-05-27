/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:05:02 by lagea             #+#    #+#             */
/*   Updated: 2024/05/27 13:26:45 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/push_swap.h"

void	exit_error(t_stack *stack, char **lst, size_t i)
{
	while (lst[i] != NULL)
		free(lst[i++]);
	if (stack)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	exit_error_array(char **lst, size_t i)
{
	while (lst[i] != NULL)
		free(lst[i++]);
	lst = NULL;
	free(lst);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	exit_stack(t_stack *stack_a, t_stack *stack_b)
{
	dll_clear(stack_a);
	dll_clear(stack_b);
	exit(EXIT_FAILURE);
}

void	exit_error_cmd(t_stack *stack_a, t_stack *stack_b)
{
	dll_clear(stack_a);
	dll_clear(stack_b);
	if (stack_a->line)
		free(stack_a->line);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	exit_malloc(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a && !stack_b)
		exit(EXIT_FAILURE);
	if (!stack_a)
		dll_clear(stack_b);
	if (!stack_b)
		dll_clear(stack_a);
	exit(EXIT_FAILURE);
}
