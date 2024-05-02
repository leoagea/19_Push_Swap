/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:29:30 by lagea             #+#    #+#             */
/*   Updated: 2024/05/02 11:53:32 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/push_swap.h"

size_t d_array_len (char **lst)
{
	size_t i;
	size_t len;
	
	i = 0;
	len = 0;
	if(!lst)
		return 0;
	while (lst[i] != NULL)
	{
		len++;
		i++;
	}
	return len;
}

char **parse_arg(int ac, char **av)
{
	char **lst;
	if (ac == 2)
	{
		lst = ft_split(av[1],' ');
	}
	for (int i = 0;i < 12;i++)
		printf("%s\n",lst[i]);
	printf("\n%zu\n",d_array_len(lst));
	return lst;
}


int main(int ac,char **av)
{
	if (ac == 2)
		parse_arg(ac,av);
	return 0;
}