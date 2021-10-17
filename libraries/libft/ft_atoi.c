/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 23:42:26 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/16 12:58:36 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *str)
{
	long		i;
	long		sign;
	long		result;
	char		*str1;

	sign = 1;
	i = 0;
	result = 0;
	str1 = (char *)str;
	while (str1[i] == ' ' || str1[i] == '\t' || str1[i] == '\f'
		|| str1[i] == '\r' || str1[i] == '\n' || str1[i] == '\v')
		i++;
	if (str1[i] == '-' || str1[i] == '+')
	{
		if (str1[i] == '-')
			sign *= -1;
		i++;
	}
	while (48 <= str1[i] && str1[i] <= 57)
	{
		result = result * 10 + (str1[i] - '0');
		i++;
	}
	return (sign * result);
}
