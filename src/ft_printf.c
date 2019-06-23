/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgueren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 14:03:27 by wgueren           #+#    #+#             */
/*   Updated: 2019/04/13 11:31:28 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	char	*fmt;
	int		res;
	va_list ap;

	res = 0;
	fmt = (char*)format;
	va_start(ap, format);
	res = pf_parser(fmt, ap);
	va_end(ap);
	return (res);
}
