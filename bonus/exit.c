/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:05:02 by lagea             #+#    #+#             */
/*   Updated: 2024/05/21 15:13:40 by lagea            ###   ########.fr       */
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
		write(2, "Error Parsing\n", 14);
		exit(EXIT_FAILURE);
	}
	write(2, "Error Parsing\n", 14);
	exit(EXIT_FAILURE);
}

void	exit_error_array(char **lst, size_t i)
{
	while (lst[i] != NULL)
		free(lst[i++]);
	write(2, "Error Parsing\n", 14);
	exit(EXIT_FAILURE);
}

void	exit_stack(t_stack *stack_a, t_stack *stack_b)
{
	dll_clear(stack_a);
	dll_clear(stack_b);
	exit(EXIT_SUCCESS);
}

void exit_error_cmd(t_stack *stack_a, t_stack *stack_b)
{
	dll_clear(stack_a);
	dll_clear(stack_b);
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}
