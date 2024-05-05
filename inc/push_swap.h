/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea < lagea@student.s19.be >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:31:01 by lagea             #+#    #+#             */
/*   Updated: 2024/05/05 23:39:59 by lagea            ###   ########.fr       */
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

/* --------------------Init_Stack--------------------*/

t_stack				*stack_init(void);
void				stack_print_forward(t_stack *stack, char c);
void print_2_stack(t_stack *stack);
struct dll_edge* stack_cpy(t_stack *stack);

/* -------------------Check_error--------------------*/

size_t check_error_arg(char **lst, size_t i);
void exit_error_array(char **lst, size_t i);
void exit_error(t_stack *stack, char **lst, size_t i);
size_t check_quote_arg(char **av, size_t i);

/* ----------------------Move-----------------------*/

void move_sa(t_stack *stack);
void move_sb(t_stack *stack);
void move_ss(t_stack *stack);

#endif