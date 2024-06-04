/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:22:51 by lagea             #+#    #+#             */
/*   Updated: 2024/06/04 17:45:59 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/push_swap.h"

bool	is_sort(t_stack *stack_a)
{
	t_node	*current;

	if (stack_a == NULL)
		return (false);
	current = stack_a->head;
	while (current->next != NULL)
	{
		if (current->value > current->next->value)
			return (false);
		current = current->next;
	}
	return (true);
}

void	checker(t_stack *stack_a, t_stack *stack_b)
{
	while (true)
	{
		stack_a->line = get_next_line(0);
		if (stack_a->line == NULL)
			break ;
		if (ft_strncmp(stack_a->line, "\n", 1) == 0)
		{
			free(stack_a->line);
			break ;
		}
		else if (!is_command(stack_a->line))
		{
			free(stack_a->line);
			write(2, "Error\n", 6);
			exit_stack(stack_a, stack_b);
		}
		else
			execute_command(stack_a->line, stack_a, stack_b);
		free(stack_a->line);
	}
}

int	is_command(char *cmd)
{
	if (ft_strncmp(cmd, "sa\n", 3) == 0 || ft_strncmp(cmd, "sb\n", 3) == 0
		|| ft_strncmp(cmd, "ss\n", 3) == 0)
		return (1);
	else if (ft_strncmp(cmd, "pa\n", 3) == 0 || ft_strncmp(cmd, "pb\n", 3) == 0)
		return (1);
	else if (ft_strncmp(cmd, "ra\n", 3) == 0 || ft_strncmp(cmd, "rb\n", 3) == 0
		|| ft_strncmp(cmd, "rr\n", 3) == 0)
		return (1);
	else if (ft_strncmp(cmd, "rra\n", 4) == 0 || ft_strncmp(cmd, "rrb\n",
			4) == 0 || ft_strncmp(cmd, "rrr\n", 4) == 0)
		return (1);
	return (0);
}

void	execute_command(char *cmd, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strncmp(cmd, "sa\n", 3) == 0)
		swap_a(stack_a, stack_b, false);
	else if (ft_strncmp(cmd, "sb\n", 3) == 0)
		swap_b(stack_b, stack_a, false);
	else if (ft_strncmp(cmd, "ss\n", 3) == 0)
		swap_ss(stack_a, stack_b);
	else if (ft_strncmp(cmd, "pa\n", 3) == 0)
		push_a(stack_a, stack_b, false);
	else if (ft_strncmp(cmd, "pb\n", 3) == 0)
		push_b(stack_a, stack_b, false);
	else if (ft_strncmp(cmd, "ra\n", 3) == 0)
		rotate_a(stack_a, stack_b, false);
	else if (ft_strncmp(cmd, "rb\n", 3) == 0)
		rotate_b(stack_b, stack_a, false);
	else if (ft_strncmp(cmd, "rr\n", 3) == 0)
		rotate_rr(stack_a, stack_b);
	else if (ft_strncmp(cmd, "rra\n", 4) == 0)
		reverse_rotate_a(stack_a, stack_b, false);
	else if (ft_strncmp(cmd, "rrb\n", 4) == 0)
		reverse_rotate_b(stack_b, stack_a, false);
	else if (ft_strncmp(cmd, "rrr\n", 4) == 0)
		reverse_rotate_rr(stack_a, stack_b);
}
