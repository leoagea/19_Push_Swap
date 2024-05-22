/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:20:50 by lagea             #+#    #+#             */
/*   Updated: 2024/05/22 17:53:53 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		dll_len;

	stack_a = stack_init();
	stack_b = stack_init();
	if (!stack_a || !stack_b)
		exit(EXIT_FAILURE);
	if (ac == 1)
		return (free(stack_a), free(stack_b), write(2, "Error\n", 6), 1);
	else if (ac == 2)
		parse_solo_arg(av, stack_a, stack_b);
	else
	{
		parse_mul_arg(ac, av, stack_a, stack_b);
	}
	push_swap(stack_a, stack_b);
	// print_stack(stack_a);
	dll_clear(stack_a);
	dll_clear(stack_b);
	return (0);
}
