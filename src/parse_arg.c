/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:29:30 by lagea             #+#    #+#             */
/*   Updated: 2024/05/02 11:43:50 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/push_swap.h"

char **parse_arg(int ac, char **av)
{
	char **lst;
	if (ac == 2)
	{
		lst = ft_split(av[1],' ');
	}
	for (int i = 0;i < 10;i++)
		printf("%s\n",lst[i]);
	return lst;
}

int main(int ac,char **av)
{
	if (ac == 2)
		parse_arg(ac,av);
	return 0;
}