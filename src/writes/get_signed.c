/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_signed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 18:43:38 by dlabadie          #+#    #+#             */
/*   Updated: 2019/04/19 18:43:42 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		get_char(va_list ap)
{
	char		n;

	n = (char)va_arg(ap, int);
	return (n);
}

short		get_short(va_list ap)
{
	short		n;

	n = (short)va_arg(ap, int);
	return (n);
}

int			get_int(va_list ap)
{
	int		n;

	n = va_arg(ap, int);
	return (n);
}

long		get_long(va_list ap)
{
	long		n;

	n = va_arg(ap, long);
	return (n);
}

long long	get_long_long(va_list ap)
{
	long long	n;

	n = va_arg(ap, long long);
	return (n);
}
