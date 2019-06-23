/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:02:59 by dlabadie          #+#    #+#             */
/*   Updated: 2019/05/07 12:44:13 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "write.h"

unsigned long long		write_unsigned(va_list ap, char specifier, int liter)
{
	unsigned long long	nbr;

	nbr = 0;
	if (specifier == HH && liter != 2)
	{
		nbr = (unsigned long long)get_unsigned_char(ap);
	}
	else if (specifier == H && liter != 2)
	{
		nbr = (unsigned long long)get_unsigned_short(ap);
	}
	else if (specifier == L && liter != 2)
	{
		nbr = (unsigned long long)get_unsigned_long(ap);
	}
	else if (specifier == LL || liter == 2)
	{
		nbr = (unsigned long long)get_unsigned_long_long(ap);
	}
	else
	{
		nbr = (unsigned long long)get_unsigned_int(ap);
	}
	return (nbr);
}
