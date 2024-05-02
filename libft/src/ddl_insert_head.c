/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ddl_insert_head.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:18:21 by lagea             #+#    #+#             */
/*   Updated: 2024/05/02 13:28:25 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"
#include "../../inc/push_swap.h"

void ddl_insert_head(void *data)
{
	t_node *new;
	
	new = ddl_new_node(data);
	if (head == NULL)
	{
		head = new;
		tail = new;
	}
	else
	{
		new->next = head;
		head->prev = new;
		head = new;	
	}
}
