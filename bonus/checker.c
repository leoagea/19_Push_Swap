/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:22:51 by lagea             #+#    #+#             */
/*   Updated: 2024/05/21 13:39:02 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/push_swap.h"

void	checker(t_stack *stack_a, t_stack *stack_b)
{
	char	*cmd;

	while (true)
	{
		cmd = get_next_line(0);
		if (ft_strncmp(cmd, "\n", 1) == 0)
			break ;
		else if (is_command(cmd))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
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
