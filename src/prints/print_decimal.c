/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgueren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 10:30:00 by wgueren           #+#    #+#             */
/*   Updated: 2019/05/03 14:06:50 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decimal.h"

void	more_pthen_l(t_pattern *pattern, char *output, int nul, int sp)
{
	if (pattern->minus == 1 && pattern->precision > pattern->width)
	{
		sp = pattern->width - pattern->precision;
		nul = pattern->precision - ft_strlen(output);
		print_spaces(nul);
		print_nuls(sp);
		printing_chars(output, pattern);
	}
	else if (pattern->minus)
	{
		sp = pattern->width - pattern->precision;
		nul = pattern->precision - ft_strlen(output);
		print_spaces(nul);
		printing_chars(output, pattern);
		print_nuls(sp);
	}
	else
		if_zero_here(pattern, output, nul, sp);
}

void	if_precision_is_nul(t_pattern *pattern, char *output, int nul, int sp)
{
	if (*output == '0' && !pattern->precision && pattern->point)
	{
		sp = pattern->width / 2 - 1;
		print_nuls(sp);
		printing_chars(output, pattern);
	}
	if (pattern->zero == 1 && pattern->minus == 0)
		if_min_is_nul(pattern, output, nul, sp);
	else if (pattern->minus == 1)
	{
		sp = pattern->width - ft_strlen(output);
		nul = 0;
		print_spaces(nul);
		printing_chars(output, pattern);
		print_nuls(sp);
	}
	else
	{
		sp = pattern->width - ft_strlen(output);
		nul = 0;
		print_nuls(sp);
		printing_chars(output, pattern);
		print_spaces(nul);
	}
}

void	if_precision_more_then_nul(t_pattern *pattern,
	char *output, int nul, int sp)
{
	sp = pattern->width - ft_strlen(output);
	nul = 0;
	if (pattern->precision <= (int)ft_strlen(output) && pattern->minus)
	{
		printing_chars(output, pattern);
		print_nuls(sp);
	}
	else
	{
		print_nuls(sp);
		printing_chars(output, pattern);
	}
}

void	if_width_is_nul(t_pattern *pattern, char *output, int nul, int sp)
{
	if (pattern->precision < (int)ft_strlen(output))
	{
		sp = pattern->width - ft_strlen(output);
		print_nuls(sp);
		print_spaces(nul);
		printing_chars(output, pattern);
	}
	else
	{
		nul = pattern->precision - ft_strlen(output);
		print_nuls(sp);
		print_spaces(nul);
		printing_chars(output, pattern);
	}
}

int		print_decimal(unsigned long long nbr, t_pattern *pattern)
{
	t_vars	var;

	var.nul = 0;
	var.sp = 0;
	var.output = ft_itoa_base_unsigned(nbr, 10);
	if (pattern->width > 0)
	{
		if (pattern->precision > (int)ft_strlen(var.output))
			more_pthen_l(pattern, var.output, var.nul, var.sp);
		else if (!pattern->precision)
			if_precision_is_nul(pattern, var.output, var.nul, var.sp);
		else if (pattern->width <= (int)ft_strlen(var.output))
			printing_chars(var.output, pattern);
		else if (pattern->precision > 0)
			if_precision_more_then_nul(pattern, var.output, var.nul, var.sp);
	}
	else if (pattern->precision > 0 && pattern->width == 0)
		if_width_is_nul(pattern, var.output, var.nul, var.sp);
	else
		printing_chars(var.output, pattern);
	var.sp = ft_strlen(var.output);
	free(var.output);
	return ((!pattern->width && !pattern->precision && !nbr && pattern->point)
	? 0 : ft_max(ft_max(pattern->width, pattern->precision
	+ pattern->hash), var.sp + pattern->hash));
}
