/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgueren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 10:27:10 by wgueren           #+#    #+#             */
/*   Updated: 2019/04/17 11:19:02 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "write.h"

int		write_decimal(va_list ap, t_pattern *pattern)
{
	unsigned long long		nbr;

	nbr = write_unsigned(ap, pattern->specifier, pattern->liter);
	return (print_decimal(nbr, pattern));
}
