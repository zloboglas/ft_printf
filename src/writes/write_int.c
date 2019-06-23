/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgueren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 10:26:58 by wgueren           #+#    #+#             */
/*   Updated: 2019/05/07 12:53:48 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "write.h"

int		write_int(va_list ap, t_pattern *pattern)
{
	long long	nbr;
	char		*output;

	nbr = 0;
	if (pattern->specifier == HH && pattern->liter != 2)
		nbr = (long long)get_char(ap);
	else if (pattern->specifier == H && pattern->liter != 2)
		nbr = (long long)get_short(ap);
	else if (pattern->specifier == L && pattern->liter != 2)
		nbr = (long long)get_long(ap);
	else if (pattern->specifier == LL || pattern->liter == 2)
		nbr = (long long)get_long_long(ap);
	else
		nbr = (long long)get_int(ap);
	output = ft_itoa_base_unsigned((unsigned long long)\
	(nbr < 0) ? (-1) * nbr : nbr, 10);
	return (print_int(nbr, output, pattern));
}
