/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:31:37 by lagea             #+#    #+#             */
/*   Updated: 2024/05/22 17:48:27 by lagea            ###   ########.fr       */
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

static int	is_check(const char *str)
{
	while (((*str >= 9 && *str <= 13) || *str == 32) || *str == '-'
		|| *str == '+')
	{
		str++;
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
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
