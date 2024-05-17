/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea < lagea@student.s19.be >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:29:30 by lagea             #+#    #+#             */
/*   Updated: 2024/05/18 00:09:58 by lagea            ###   ########.fr       */
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
		// printf("Test\n");
		// int test = nbr_word_arg(av[i], ' ');
		// printf("nbr word arg %zu : %d\n",i,test);
		// printf("Test 2\n");
		if (nbr_word_arg(av[i], ' ') != 1)
		{
			// printf("Test \n");
			write(2, "Error Parsing\n", 14);
			// system("leaks push_swap");
			exit(EXIT_FAILURE);
		}
		// printf("Test 3\n");
		if (check_error_arg(av, i))
			dll_insert_tail(ft_atoi(av[i]), stack_a);
		// printf("Test 6\n");
		i++;
	}
	check_dupes_stack(stack_a,stack_b);
}

void parse_solo_arg(char **av, t_stack *stack_a ,t_stack *stack_b)
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
	check_dupes_stack(stack_a,stack_b);
	free(lst);
	// stack_print_forward(stack, 'a');
}
