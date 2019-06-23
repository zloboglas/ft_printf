/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgueren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 10:26:01 by wgueren           #+#    #+#             */
/*   Updated: 2019/04/17 11:21:29 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "write.h"

int			write_octal(va_list ap, t_pattern *pattern)
{
	unsigned long long		nbr;

	nbr = write_unsigned(ap, pattern->specifier, pattern->liter);
	return (print_octal(nbr, pattern));
}
