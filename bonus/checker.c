/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:22:51 by lagea             #+#    #+#             */
/*   Updated: 2024/05/21 18:09:10 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/push_swap.h"

bool	is_sort(t_stack *stack_a)
{
	t_node	*current;

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
	char	*cmd;

	while (true)
	{
		cmd = get_next_line(0);
		if (ft_strncmp(cmd, "\n", 1) == 0)
			break ;
		else if (!is_command(cmd))
		{
			write(1, "Error\n", 6);
			exit_stack(stack_a, stack_b);
		}
		else
			execute_command(cmd, stack_a, stack_b);
	}
}

int	is_command(char *cmd)
{
	if (ft_strncmp(cmd, "sa\n", 3) == 0 || ft_strncmp(cmd, "sb\n", 3) == 0 || ft_strncmp(cmd, "ss\n", 3) == 0)
		return (1);
	else if (ft_strncmp(cmd, "pa\n", 3) == 0 || ft_strncmp(cmd, "pb\n", 3) == 0)
		return (1);
	else if (ft_strncmp(cmd, "ra\n", 3) == 0 || ft_strncmp(cmd, "rb\n", 3) == 0
		|| ft_strncmp(cmd, "rr\n", 3) == 0)
		return (1);
	else if (ft_strncmp(cmd, "rra\n", 4) == 0 || ft_strncmp(cmd, "rrb\n",
			4) == 0 || ft_strncmp(cmd, "rrr\n", 4) == 0)
		return (1);
	return 0;
}

void execute_command(char *cmd, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strncmp(cmd, "sa\n", 3) == 0)
		swap_a(stack_a, stack_b, false);
	else if (ft_strncmp(cmd, "sb\n", 3) == 0)
		swap_b(stack_b, stack_a, false);
	else if (ft_strncmp(cmd, "ss\n", 3) == 0)
		swap_ss(stack_a, stack_b);
	else if (ft_strncmp(cmd, "pa\n", 3) == 0)
		push_a(stack_a, stack_b);
	else if (ft_strncmp(cmd, "pb\n", 3) == 0)
		push_b(stack_a, stack_b);
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
