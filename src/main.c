/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:20:50 by lagea             #+#    #+#             */
/*   Updated: 2024/05/16 17:47:37 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../inc/libft.h"

int main(int ac, char **av) 
{
    t_stack *stack;
    int dll_len;
    
    stack = stack_init();
    if (!stack)
        exit(EXIT_FAILURE);
    if (ac == 1)
        return (free(stack),write(2, "Error Parsing 0 Arguments\n", 26),1);
    else if (ac == 2)
		parse_solo_arg(av,stack);
    else
    {
        parse_mul_arg(ac,av, stack);
    }

    // index_init_stack(stack);
    // find_median(stack->a);
    // find_median(stack->b);
    // printf("\nStack a\n");
    // dll_print_forward(stack->a);
    // printf("\nStack b\n");
    // dll_print_forward(stack->b);
    // printf("\n\n\n");
    
    push_swap(stack);

    // dll_insert_tail(-22,stack->a);
    // dll_insert_tail(-58,stack->a);
    // dll_insert_tail(-64,stack->a);

    // sort_three_elements(stack);
    
    index_init_stack(stack);
    // printf("\nStack a\n");
    // dll_print_forward(stack->a);
    
    // printf("\nStack b\n");
    // dll_print_forward(stack->b);
    // printf("\n\n\n");

    // index_init_stack(stack);
    // printf("\nStack a\n");
    // dll_print_backward(stack->a);
    // printf("\nStack b\n");
    // dll_print_backward(stack->b);
    // printf("\n\n\n");
    
    // if (is_sort(stack))
    //     printf("Stack sorted\n");

    dll_clear(stack->a);
    dll_clear(stack->b);
    
    // // ft_split(av[1], ' ');
    // // system("leaks push_swap");

    return 0; 
} 

    