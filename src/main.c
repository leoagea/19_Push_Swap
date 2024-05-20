/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:20:50 by lagea             #+#    #+#             */
/*   Updated: 2024/05/20 13:18:57 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../inc/libft.h"

int main(int ac, char **av) 
{
    t_stack *stack_a;
    t_stack *stack_b;
    int dll_len;
    
    stack_a = stack_init();
    stack_b = stack_init();
    if (!stack_a || !stack_b)
        exit(EXIT_FAILURE);
    if (ac == 1)
        return (free(stack_a),free(stack_b),write(2, "Error Parsing 0 Arguments\n", 26),1);
    else if (ac == 2)
		parse_solo_arg(av,stack_a,stack_b);
    else
    {
        parse_mul_arg(ac,av, stack_a,stack_b);
    }

    // printf("mean value is : %f\n",find_average(stack));
    // printf("\nStack a\n");
    // dll_print_forward(stack->a);

    push_swap(stack_a, stack_a);
    
    // swap_a(stack_a,true);
    // push_b(stack_a, stack_b);
    print_stack(stack_a);
    
    index_init_stack(stack_a, stack_b);
    printf("\nStack a\n");
    dll_print_forward(stack_a);
    
    printf("\nStack b\n");
    dll_print_forward(stack_b);

    // dll_insert_tail(-22,stack->a);
    // dll_insert_tail(-58,stack->a);
    // dll_insert_tail(-64,stack->a);

    // sort_three_elements(stack);
    
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

    dll_clear(stack_a);
    dll_clear(stack_b);
    
    // // ft_split(av[1], ' ');
    // // system("leaks push_swap");

    return 0; 
} 

    