/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgueren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 10:56:49 by wgueren           #+#    #+#             */
/*   Updated: 2018/12/10 12:27:53 by wgueren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned long	res;
	int				sign;

	res = 0;
	sign = 1;
	while ((*str == ' ') || (*str == '\t') || (*str == '\n') ||
	(*str == '\v') || (*str == '\f') || (*str == '\r'))
		str += 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		if (res > 9223372036854775807 && sign < 0)
			return (0);
		if (res >= 9223372036854775807 && sign > 0)
			return (-1);
		str++;
	}
	return (sign * res);
}
