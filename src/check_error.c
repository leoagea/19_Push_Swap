/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:38:39 by lagea             #+#    #+#             */
/*   Updated: 2024/05/04 20:43:27 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/push_swap.h"

size_t check_error_arg(char **lst, size_t i)
{
	size_t j;

	j = -1;
	while (lst [++i])
	{
		while (lst [i][++j])
		{
			if (!ft_isdigit((int)lst [i][j]))
				exit_error_array(lst, i);
		}
		if (ft_atoi(lst [i]) > INT_MAX)
				exit_error_array(lst, i);
	}
	return 1;
}

void exit_error_array(char **lst, size_t i)
{
	while (lst[i] != NULL)
		free(lst[i++]);
	write(2, "Error Parsing\n", 14);
    system("leaks a.out");
	exit(EXIT_FAILURE);
}

void exit_error(t_stack *stack, char **lst, size_t i)
{
	while (lst[i] != NULL)
		free(lst[i++]);
	if (stack)
	{
		write(2, "Error Parsing\n", 14);
    	system("leaks a.out");
		exit(EXIT_FAILURE);
	}
	write(2, "Error Parsing\n", 14);
    system("leaks a.out");
	exit(EXIT_FAILURE);
}

size_t check_quote_arg(char **av, size_t i)
{
	char **lst;

	printf("test\n");
	printf("i : %zu\n",i);
	lst = ft_split(av[i], ' '); /// segfault check
	printf("test\n");
	if (d_array_len(lst) > 1)
	{
		write(2, "Error Parsing\n", 14);
		system("leaks a.out");
		exit(EXIT_FAILURE);
	}
	return 1;
}