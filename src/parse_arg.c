/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:29:30 by lagea             #+#    #+#             */
/*   Updated: 2024/05/03 15:27:34 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/push_swap.h"

size_t d_array_len (char **lst)
{
	size_t i;
	size_t len;
	
	i = 0;
	len = 0;
	if(!lst)
		return 0;
	while (lst[i] != NULL)
	{
		len++;
		i++;
	}
	return len;
}

char **parse_arg(int ac, char **av, t_stack *stack)
{
	size_t i;
	size_t j;
	size_t len;
	char **lst;
	
	i = -1;
	j = -1;
	if (ac == 2)
	{
		lst = ft_split(av[1],' ');
		len = d_array_len(lst);
		while(++i < len)
		{
			while (lst[++j])
				if (ft_isalpha((int)lst[j]))
					exit_error(stack);
			dll_insert_tail(ft_atoi(lst[i]),stack->a);
			free(lst[i]);
		}
		free(lst);
	}
	stack_print_forward(stack, 'a');
	return lst;
}
