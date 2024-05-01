/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 02:04:14 by lagea             #+#    #+#             */
/*   Updated: 2024/05/01 16:56:49 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

size_t	ft_strlen(const char *s)
{
	int	len;

	if (!s)
		return 0;
	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}
