/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:31:01 by lagea             #+#    #+#             */
/*   Updated: 2024/05/20 13:16:07 by lagea            ###   ########.fr       */
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
	int				index;
	bool			median;
	ssize_t			value;
	struct s_node	*prev;
	struct s_node	*next;

}					t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
}					t_stack;

/*---------------------Parse_Arg---------------------*/

void	parse_mul_arg(int ac, char **av, t_stack *stack_a, t_stack *stack_b);
void parse_solo_arg(char **av, t_stack *stack_a ,t_stack *stack_b);
size_t				d_array_len(char **lst);

/*--------------------Init_Stack--------------------*/

t_stack				*stack_init(void);
void	index_init(t_stack *stack);
void	index_init_stack(t_stack *stack_a, t_stack * stack_b);

void	find_median(t_stack *stack);
// int find_cost_b(t_stack *stack, t_node *node);
// void find_cost(t_stack *stack,t_node *node);
// void cost_stack(t_stack *stack);
// int find_min_cost(t_stack *stack);
// int find_closest(t_stack *stack,int value);

// int biggest_b(t_stack *stack);
// int smallest_b(t_stack *stack);

// struct dll_edge* stack_cpy(t_stack *stack);
// /*struct dll_edge**/void stack_cpy(t_stack *stack);

void	print_stack(t_stack *stack);

/*-------------------Check_error--------------------*/

size_t				check_error_arg(char **lst, size_t i);
void check_dupes_stack(t_stack *stack_a ,t_stack *stack_b);
int					nbr_word_arg(char const *s, char c);

/*----------------------Exit-----------------------*/

void				exit_error(t_stack *stack, char **lst, size_t i);
void				exit_error_array(char **lst, size_t i);
void exit_stack(t_stack *stack_a, t_stack *stack_b);

/*----------------------Algo-----------------------*/

void push_swap(t_stack *stack_a, t_stack *stack_b);
void sort_until_5(t_stack *stack_a, t_stack *stack_b);

/*----------------------Utils----------------------*/

t_node	*find_biggest_b(t_stack *stack_b);
t_node	*find_smallest_b(t_stack *stack_b);
t_node	*find_biggest_a(t_stack *stack_a);
t_node	*find_smallest_a(t_stack *stack_a);
t_node	*find_closest(t_stack *stack_b, t_node *node);

float find_average(t_stack *stack_a);
t_node	*find_best_friend(t_stack *stack_a, t_node *node);
void find_cost(t_stack *stack_a, t_stack *stack_b);
int find_moves_bestfriend(t_stack *stack_a, t_node *bestfriend);
int find_moves_node(t_stack *stack_b, t_node *node);

/*----------------------Sort-----------------------*/

t_node	*find_min_cost(t_stack *stack_b);
bool				is_sort(t_stack *stack);
void	sort_three_elements(t_stack *stack_a, t_stack *stack_b);
void sort_five_elements(t_stack *stack_a, t_stack *stack_b);
void put_best_node_top(t_stack *stack_a, t_stack *stack_b, t_node *min, t_node *best);
void sort(t_stack *stack_a, t_stack *stack_b);
void final_rotate(t_stack *stack_a);

/*----------------------Move-----------------------*/

void	swap_a(t_stack *stack_a, bool print);
void	swap_b(t_stack *stack_b, bool print);
void	swap_ss(t_stack *stack_a, t_stack *stack_b);
void	push_a(t_stack *stack_a, t_stack *stack_b);
void	push_b(t_stack *stack_a, t_stack *stack_b);

/*---------------------Rotate----------------------*/

void	rotate_a(t_stack *stack_a, bool print);
void	rotate_b(t_stack *stack_b, bool print);
void				rotate_rr(t_stack *stack);

/*----------------Reverse Rotate-------------------*/

void	reverse_rotate_a(t_stack *stack_a, bool print);
void	reverse_rotate_b(t_stack *stack_b, bool print);
void				reverse_rotate_rr(t_stack *stack);

#endif