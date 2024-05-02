/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ddl_new_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:23:41 by lagea             #+#    #+#             */
/*   Updated: 2024/05/02 13:17:18 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"
#include "../../inc/push_swap.h"

t_node	*dll_new_node(void *content)
{
	t_node *new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = content;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
