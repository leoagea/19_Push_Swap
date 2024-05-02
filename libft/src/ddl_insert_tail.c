/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ddl_insert_tail.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:34:55 by lagea             #+#    #+#             */
/*   Updated: 2024/05/02 13:37:21 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"
#include "../../inc/push_swap.h"

void ddl_insert_tail(ssize_t data)
{
	t_node *new;

	new = ddl_new_node(data);
	if (tail == NULL)
	{
		head = new;
		tail = new;
	}
	else
	{
		new->prev = tail;
		tail->next = new;
		tail = new;
	}
}
