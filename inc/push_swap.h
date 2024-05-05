/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea < lagea@student.s19.be >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:31:01 by lagea             #+#    #+#             */
/*   Updated: 2024/05/06 00:57:54 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h> //Macro INT_MAX
# include <stdio.h>  //printf

typedef struct s_node
{
	ssize_t			value;
	struct s_node	*prev;
	struct s_node	*next;

}					t_node;

struct				dll_edge
{
	t_node			*head;
	t_node			*tail;
};

typedef struct s_stack
{
	struct dll_edge	*a;
	struct dll_edge	*b;
}					t_stack;

/*---------------------Parse_Arg---------------------*/

char **parse_mul_arg(int ac, char **av, t_stack *stack);
char **parse_solo_arg(char **av, t_stack *stack);
size_t				d_array_len(char **lst);

/*--------------------Init_Stack--------------------*/

t_stack				*stack_init(void);
void				stack_print_forward(t_stack *stack, char c);
void print_2_stack(t_stack *stack);
struct dll_edge* stack_cpy(t_stack *stack);

/*-------------------Check_error--------------------*/

size_t check_error_arg(char **lst, size_t i);
void exit_error_array(char **lst, size_t i);
void exit_error(t_stack *stack, char **lst, size_t i);
size_t check_quote_arg(char **av, size_t i);

/*----------------------Move-----------------------*/

void swap_a(t_stack *stack);
void swap_b(t_stack *stack);
void swap_ss(t_stack *stack);
void push_a(t_stack *stack);
void push_b(t_stack *stack);

/*---------------------Rotate----------------------*/

void rotate_a(t_stack *stack);
void rotate_b(t_stack *stack);
void rotate_rr(t_stack *stack);

/*----------------Reverse Rotate-------------------*/

void reverse_rotate_a(t_stack *stack);
void reverse_rotate_b(t_stack *stack);
void reverse_rotate_rr(t_stack *stack);

#endif