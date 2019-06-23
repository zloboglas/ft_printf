/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_switch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 07:32:35 by dlabadie          #+#    #+#             */
/*   Updated: 2019/05/03 13:51:38 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "switch.h"

void	init_tab(int (**write_t)(va_list ap, t_pattern *pattern))
{
	write_t['F'] = write_double;
	write_t['f'] = write_double;
	write_t['g'] = write_double;
	write_t['c'] = write_char;
	write_t['C'] = write_char;
	write_t['s'] = write_string;
	write_t['S'] = write_string;
	write_t['x'] = write_hex;
	write_t['o'] = write_octal;
	write_t['O'] = write_octal;
	write_t['p'] = write_pointer;
	write_t['X'] = write_hex;
	write_t['i'] = write_int;
	write_t['d'] = write_int;
	write_t['u'] = write_decimal;
	write_t['I'] = write_int;
	write_t['D'] = write_int;
	write_t['U'] = write_decimal;
	write_t['%'] = write_per;
}

int		pf_switch(va_list ap, t_pattern *pattern, char type)
{
	int		(*write_t[256])(va_list ap, t_pattern *pattern);

	init_tab(write_t);
	return (write_t[(int)type](ap, pattern));
}
