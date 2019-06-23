/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_hex_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgueren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 15:54:56 by wgueren           #+#    #+#             */
/*   Updated: 2019/04/19 15:55:00 by wgueren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hex.h"

void	hex_without_hash(t_pattern *pattern, char *output)
{
	if (pattern->minus == 1 && pattern->precision > pattern->width)
	{
		print_spacess(pattern->precision - ft_strlen(output));
		print_nulss(pattern->width - pattern->precision);
		inhexademical(output, pattern);
	}
	else if (pattern->minus)
	{
		print_spacess(pattern->precision - ft_strlen(output));
		inhexademical(output, pattern);
		print_nulss(pattern->width - pattern->precision);
	}
	else
	{
		print_nulss(pattern->width - pattern->precision);
		print_spacess(pattern->precision - ft_strlen(output));
		inhexademical(output, pattern);
	}
}

void	hex_with_hash(t_pattern *pattern, char *output, int sp)
{
	if (pattern->minus == 1)
	{
		sp = pattern->width - pattern->precision - 2;
		if (*output == '0')
			sp += 2;
		ishash(output, pattern);
		print_spacess(pattern->precision - ft_strlen(output));
		inhexademical(output, pattern);
		print_nulss(sp);
	}
	else
	{
		sp = pattern->width - pattern->precision - 2;
		if (*output == '0' && pattern->zero)
			sp += 2;
		print_nulss(sp);
		ishash(output, pattern);
		print_spacess(pattern->precision - ft_strlen(output));
		inhexademical(output, pattern);
	}
}

void	hex_with_point_n_zero(t_pattern *pattern, char *output)
{
	if (pattern->hash == 1)
	{
		if (*output == '0')
			print_nulss(pattern->width - ft_strlen(output));
		else
			print_nulss(pattern->width - ft_strlen(output) - 2);
	}
	else
		print_nulss(pattern->width - ft_strlen(output));
	ishash(output, pattern);
	inhexademical(output, pattern);
}

void	hex_without_point_n_zero(t_pattern *pattern, char *output)
{
	int nul;

	if (pattern->hash == 1)
	{
		if (*output == '0')
			nul = pattern->width - 1;
		else
			nul = pattern->width - ft_strlen(output) - 2;
		ishash(output, pattern);
		print_spacess(nul);
		inhexademical(output, pattern);
	}
	else
	{
		print_spacess(pattern->width - ft_strlen(output));
		inhexademical(output, pattern);
	}
}

void	hex_without_minus(t_pattern *pattern, char *output)
{
	if (pattern->point == 1)
		hex_with_point_n_zero(pattern, output);
	else if (pattern->point == 0)
		hex_without_point_n_zero(pattern, output);
}
