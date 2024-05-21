/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:38:39 by lagea             #+#    #+#             */
/*   Updated: 2024/05/21 18:09:12 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/push_swap.h"

size_t	check_error_arg(char **lst, size_t i)
{
	long	res_atol;

	res_atol = ft_atol(lst[i]);
	if (res_atol > INT_MAX || res_atol < INT_MIN)
		exit_error_array(lst, i);
	return (1);
}

void	check_dupes_stack(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*check;
	t_node	*current;

	check = stack_a->head->next;
	current = stack_a->head;
	while (current != NULL)
	{
		while (check != NULL)
		{
			if (current->value == check->value)
			{
				dll_clear(stack_a);
				dll_clear(stack_b);
				write(2, "Error Duplicate\n", 16);
				exit(EXIT_FAILURE);
			}
			check = check->next;
		}
		current = current->next;
		if (current != NULL)
			check = current->next;
	}
}

int	nbr_word_arg(char const *s, char c)
{
	int	i;
	int	index;
	int	len_word;

	i = 0;
	index = 0;
	len_word = 1;
	while (s[index])
	{
		if (ft_isdigit((int)s[index]))
			index++;
		else if (s[index] == '-' || s[index] == '+')
			index++;
		else
		{
			len_word++;
			index++;
		}
	}
	return (len_word);
}
