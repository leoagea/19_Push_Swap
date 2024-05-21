/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:59:20 by lagea             #+#    #+#             */
/*   Updated: 2024/05/21 18:09:04 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/push_swap.h"

int main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		dll_len;

	stack_a = stack_init();
	stack_b = stack_init();
	if (!stack_a || !stack_b)
		exit(EXIT_FAILURE);
	if (ac == 1)
		return (free(stack_a), free(stack_b), write(2,
				"Error Parsing 0 Arguments\n", 26), 1);
	else if (ac == 2)
		parse_solo_arg(av, stack_a, stack_b);
	else
	{
		parse_mul_arg(ac, av, stack_a, stack_b);
	}
	checker(stack_a, stack_b);
	if (is_sort(stack_a))
		return (write(0, "OK\n", 3),exit_stack(stack_a, stack_b),0);
	else
		return (write(0, "KO\n", 3),exit_stack(stack_a, stack_b),0);
}
