/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:31:37 by lagea             #+#    #+#             */
/*   Updated: 2024/05/22 16:58:20 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static void	skip_whitespace_and_sign(const char **str, int *sign)
{
	while ((**str >= 9 && **str <= 13) || **str == 32)
		(*str)++;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			*sign = -1;
		(*str)++;
	}
}
static int is_check(const char *str)
{
	int flag;
	
	while (*str)
	{
		if((*str >= 9 && *str <= 13) || *str == 32)
			str++;
		else if (*str == '-' || *str == '+')
		{
			flag = 1;
			str++;
		}
		else if(!ft_isdigit(*str))
			return 0;
		else if (ft_isdigit(*str) && flag == 1)
			return 0;
		else 
			str++;
	}
	return 1;
}

long	ft_atol(const char *str)
{
	int		sign;
	long	res;
	long	overflow;

	res = 0;
	sign = 1;
	overflow = 0;
	if (!is_check(ft_strdup(str)))
		return (2147483647814);
	skip_whitespace_and_sign(&str, &sign);
	if (ft_isdigit(*str))
	{
		while (ft_isdigit(*str))
		{
			res *= 10;
			res += (*str - 48);
			str++;
			if (overflow > res)
				return (2147483647814);
			overflow = res;
		}	
	}
	else 
		return (2147483647814);
	return (res * sign);
}
