/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:31:01 by lagea             #+#    #+#             */
/*   Updated: 2024/05/15 17:18:46 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h> //Macro INT_MAX
# include <stdbool.h>
# include <stdio.h> //printf

typedef struct s_node
{
	int				cost;
	int 			index; 
	bool 			median;
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

void				parse_mul_arg(int ac, char **av, t_stack *stack);
void				parse_solo_arg(char **av, t_stack *stack);
size_t				d_array_len(char **lst);

/*--------------------Init_Stack--------------------*/

t_stack				*stack_init(void);
void				index_init(struct dll_edge *edge);
void				index_init_stack(t_stack *stack);
void				stack_print_forward(t_stack *stack, char c);
void				print_2_stack(t_stack *stack);

void				find_median(struct dll_edge *a);
// int find_cost_b(t_stack *stack, t_node *node);
// void find_cost(t_stack *stack,t_node *node);
// void cost_stack(t_stack *stack);
// int find_min_cost(t_stack *stack);
// int find_closest(t_stack *stack,int value);

// int biggest_b(t_stack *stack);
// int smallest_b(t_stack *stack);

// struct dll_edge* stack_cpy(t_stack *stack);
// /*struct dll_edge**/void stack_cpy(t_stack *stack);

/*-------------------Check_error--------------------*/

size_t				check_error_arg(char **lst, size_t i);
void				check_dupes_stack(t_stack *stack);
int nbr_word_arg(char const *s, char c);

/*----------------------Exit-----------------------*/

void				exit_error(t_stack *stack, char **lst, size_t i);
void				exit_error_array(char **lst, size_t i);

/*----------------------Cost-----------------------*/

t_node				*find_bigest_b(t_stack *stack);
t_node				*find_smallest_b(t_stack *stack);
t_node				*find_closest(t_stack *stack, t_node *node);
int					cost_calcul(int temp_a, int temp_b, int temp_c, int temp_d);
void				find_cost(t_stack *stack, t_node *current, t_node *closest);
void				find_cost_stack(t_stack *stack);

/*----------------------Sort-----------------------*/

// void sort_a(t_stack *stack);
// void sort_b(t_stack *stack);
t_node				*find_min_cost(t_stack *stack);
t_node				*find_biggest_a(t_stack *stack);
t_node				*find_smallest_a(t_stack *stack);
void				sort(t_stack *stack, t_node *closest, t_node *min_cost);
bool				is_sort(t_stack *stack);
void				sort_three_elements(t_stack *stack);
void				push_swap(t_stack *stack);
void				final_sort(t_stack *stack);
t_node				*find_target_pushback(t_stack *stack, t_node *node);
void				final_rotate(t_stack *stack);

/*----------------------Move-----------------------*/

void				swap_a(t_stack *stack);
void				swap_b(t_stack *stack);
void				swap_ss(t_stack *stack);
void				push_a(t_stack *stack);
void				push_b(t_stack *stack);

/*---------------------Rotate----------------------*/

void				rotate_a(t_stack *stack);
void				rotate_b(t_stack *stack);
void				rotate_rr(t_stack *stack);

/*----------------Reverse Rotate-------------------*/

void				reverse_rotate_a(t_stack *stack);
void				reverse_rotate_b(t_stack *stack);
void				reverse_rotate_rr(t_stack *stack);

#endif