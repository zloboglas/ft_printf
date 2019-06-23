/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgueren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 10:25:11 by wgueren           #+#    #+#             */
/*   Updated: 2019/04/17 11:19:34 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "write.h"

int		write_double(va_list ap, t_pattern *pattern)
{
	double														dig;
	long double													ldig;

	if (pattern->specifier == LLL)
	{
		ldig = va_arg(ap, long double);
		dig = (double)ldig;
	}
	else
		dig = va_arg(ap, double);
	return (print_double(dig, pattern));
}
