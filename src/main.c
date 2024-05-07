/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea < lagea@student.s19.be >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:20:50 by lagea             #+#    #+#             */
/*   Updated: 2024/05/07 23:48:18 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../inc/libft.h"

int main(int ac, char **av) 
{
    t_stack *stack;
    int dll_len;
    
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
    // swap_a(stack);
    push_b(stack);
    push_b(stack);
    
    dll_len = dll_size(stack->a);
    while (dll_size(stack->a) != 2)
    {
        find_median(stack->a);
        find_median(stack->b);
        cost_stack(stack);
        printf("\nStack a\n");
        index_init(stack->a);
        dll_print_forward(stack->a);
        printf("\nStack b\n");
        index_init(stack->b);
        dll_print_forward(stack->b);
        sort_a(stack);
        sort_b(stack);
        push_b(stack);
    }

    ////////////////////////////////*
    /*
        ajouter au cost 
            le nombre de rotate ou reverse rotate necessaire pour 
            push en haut du stack b
            le smallest de chaque index du stack a
            ex : 7 son smallest est 5 duoucp cost += 1

        ajouter une variable a la struct node pour le nombre de rotate
        de b necessaire
        pour povoir dans le sort faire si besoin des rotate r et rev rot r
        si index retourne par smallest est < median rotate
        si index retourne par smallest est > median rev rotate
    */
    ////////////////////////////////   
	// find_median(stack->a);
    // cost_stack(stack);

    // index_init(stack->a);
    // printf("Stack a avant\n");
    // dll_print_forward(stack->a);
    // find_median(stack->a);
    // cost_stack(stack);
    
    // printf("\nStack a\n");
    // index_init(stack->a);
    // dll_print_forward(stack->a);
    // printf("\nStack b\n");
    // index_init(stack->b);
    // dll_print_forward(stack->b);
    
    dll_clear(stack->a);
    dll_clear(stack->b);

    // ft_split(av[1], ' ');
    // system("leaks push_swap");
    return 0; 
}

// int main(void)
// {
//     t_stack *stack;

//     stack = stack_init();
//     dll_insert_tail(6,stack->b);
//     dll_insert_tail(5,stack->b);
//     dll_insert_tail(2,stack->b);
//     dll_insert_tail(1,stack->b);
//     dll_insert_tail(7,stack->b);
//     index_init_stack(stack);
//     dll_print_forward(stack->b);

//     printf("\n%d\n",find_closest(stack,3));
// }
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


    