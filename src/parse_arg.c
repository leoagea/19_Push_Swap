/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:29:30 by lagea             #+#    #+#             */
/*   Updated: 2024/05/15 15:09:30 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/push_swap.h"

size_t	d_array_len(char **lst)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	if (!lst)
		return (0);
	while (lst[i] != NULL)
	{
		len++;
		i++;
	}
	return (len);
}
char	**parse_mul_arg(int ac, char **av, t_stack *stack)
{
	size_t	i;
	char	**lst;

	i = 1;
	while (i < ac)
	{
		if (check_quote_arg(lst, i))
			dll_insert_tail(ft_atoi(lst[i]), stack->a);
				// change atoi pour qu il renvoie un long
		i++;
	}
	stack_print_forward(stack, 'a');
	return (lst);
}

void parse_solo_arg(char **av, t_stack *stack)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	**lst;

	i = -1;
	j = -1;
	lst = ft_split(av[1], ' ');
	len = d_array_len(lst);
	while (++i < len)
	{
		if (check_error_arg(lst, i))
			dll_insert_tail(ft_atoi(lst[i]), stack->a);
		free(lst[i]);
	}
	check_dupes_stack(stack);
	free(lst);
	// stack_print_forward(stack, 'a');
}
