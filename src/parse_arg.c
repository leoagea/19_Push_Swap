/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:29:30 by lagea             #+#    #+#             */
/*   Updated: 2024/05/22 15:37:13 by lagea            ###   ########.fr       */
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

void	parse_mul_arg(int ac, char **av, t_stack *stack_a, t_stack *stack_b)
{
	size_t	i;

	i = 1;
	while (i < ac)
	{
		if (nbr_word_arg(av[i], ' ') != 1)
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		if (check_error_arg(av, i))
			dll_insert_tail(ft_atoi(av[i]), stack_a);
		i++;
	}
	check_dupes_stack(stack_a, stack_b);
}

void	parse_solo_arg(char **av, t_stack *stack_a, t_stack *stack_b)
{
	size_t	i;
	size_t	len;
	char	**lst;

	i = -1;
	lst = ft_split(av[1], ' ');
	len = d_array_len(lst);
	while (++i < len)
	{
		if (check_error_arg(lst, i))
			dll_insert_tail(ft_atoi(lst[i]), stack_a);
		free(lst[i]);
	}
	check_dupes_stack(stack_a, stack_b);
	free(lst);
}
