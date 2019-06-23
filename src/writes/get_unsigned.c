/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_unsigned.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 09:21:52 by dlabadie          #+#    #+#             */
/*   Updated: 2019/04/17 09:24:41 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned char			get_unsigned_char(va_list ap)
{
	unsigned char		n;

	n = (unsigned char)va_arg(ap, unsigned int);
	return (n);
}

unsigned short			get_unsigned_short(va_list ap)
{
	unsigned short		n;

	n = (unsigned short)va_arg(ap, unsigned int);
	return (n);
}

unsigned int			get_unsigned_int(va_list ap)
{
	unsigned int		n;

	n = va_arg(ap, unsigned int);
	return (n);
}

unsigned long			get_unsigned_long(va_list ap)
{
	unsigned long		n;

	n = va_arg(ap, unsigned long);
	return (n);
}

unsigned long long		get_unsigned_long_long(va_list ap)
{
	unsigned long long	n;

	n = va_arg(ap, unsigned long long);
	return (n);
}
