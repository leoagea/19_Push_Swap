/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_print_forward.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:41:18 by lagea             #+#    #+#             */
/*   Updated: 2024/05/02 16:59:57 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"
#include "../../inc/push_swap.h"

void dll_print_forward(struct dll_edge *edge)
{
	t_node *current;

	current = edge->head;
	while (current != NULL)
	{
		printf("%zd\n",current->value);
		current = current->next;
	}
}

// int main() 
// { 
//     dll_insert_head(10);
//     dll_insert_head(20); 
//     dll_insert_tail(30); 
//     dll_print_forward(); // expected output: 20 10 30 
  
//     return 0; 
// }
