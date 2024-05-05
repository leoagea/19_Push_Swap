/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea < lagea@student.s19.be >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:20:50 by lagea             #+#    #+#             */
/*   Updated: 2024/05/05 23:27:06 by lagea            ###   ########.fr       */
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
    if (ac == 1)
        return (free(stack),write(2, "Error Parsing\n", 14),1);
    else if (ac == 2)
		parse_solo_arg(av,stack);
    else
    {
        parse_mul_arg(ac,av, stack);
    }
    printf("\nStack B\n");
    stack->b = stack_cpy(stack);
    dll_print_forward(stack->b);
    dll_clear(stack->a);
    dll_clear(stack->b);

    // ft_split(av[1], ' ');
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


    