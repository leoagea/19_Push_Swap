/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:31:01 by lagea             #+#    #+#             */
/*   Updated: 2024/05/02 18:38:37 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h> //printf

typedef struct s_node
{
	ssize_t value;
	struct s_node *prev;
	struct s_node *next;
		
}	t_node;

struct dll_edge
{
	t_node *head;
	t_node *tail;
	
};

typedef struct s_stack
{
	struct dll_edge *a;
	struct dll_edge *b;
}	t_stack;

/*---------------------Parse_Arg---------------------*/
char **parse_arg(int ac, char **av);
size_t d_array_len (char **lst);

/* -------------------- Init_Stack--------------------*/
t_stack *stack_init();

#endif