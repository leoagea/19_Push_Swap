/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:20:50 by lagea             #+#    #+#             */
/*   Updated: 2024/05/04 17:56:29 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"
#include "inc/push_swap.h"
// int main(int ac, char **av)
// {
	
// }

int main(int ac, char **av) 
{
    t_stack *stack;
    
    int i = 0;
    stack = stack_init();
    if (ac == 2)
		parse_arg(ac,av,stack);
    else
    {
        write(2, "Error Parsing\n", 14);
        system("leaks a.out");
        exit(EXIT_FAILURE);
    }
    dll_clear(stack->a);
    system("leaks a.out");
    return 0; 
}


//echo $? pour check le code erreur


// TEST dll
    // struct dll_edge *edge;
    
    // edge = dll_init();
    // printf("%zu\n",dll_size(edge));
    // dll_insert_head(10,edge);
    // dll_insert_head(20,edge); 
    // dll_insert_tail(30,edge); 
    // dll_print_forward(edge); // expected output: 20 10 30 
    // printf("%zu\n",dll_size(edge));

// TEST Stack
    //  t_stack *stack;
        
    //     stack = stack_init();
    //     dll_insert_head(10,stack->a);
    //     dll_insert_head(20,stack->a); 
    //     dll_insert_tail(30,stack->a); 
    //     stack_print_forward(stack, 'a');


    