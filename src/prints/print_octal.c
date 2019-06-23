/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgueren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 10:29:02 by wgueren           #+#    #+#             */
/*   Updated: 2019/05/03 14:22:02 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "octal.h"

void	when_prec_is_nul(t_pattern *pattern, int nul, int sp, char *output)
{
	if (pattern->zero == 1 && pattern->minus == 0)
		without_minus(pattern, nul, sp, output);
	else if (pattern->hash == 1 && pattern->minus == 0)
	{
		print_nul(pattern->width - (pattern->hash && *output != '0')
			- ft_strlen(output));
		print_and_hash(output, pattern);
	}
	else if (pattern->hash == 1 && pattern->minus == 1)
		with_hash_n_minus(pattern, nul, sp, output);
	else if (pattern->minus == 1)
	{
		print_space(nul);
		print_and_hash(output, pattern);
		print_nul(pattern->width - ft_strlen(output));
	}
	else
	{
		print_nul(pattern->width - ft_strlen(output));
		print_and_hash(output, pattern);
		print_space(nul);
	}
}

void	fundamental(t_pattern *pattern, int nul, int sp, char *output)
{
	if (pattern->precision > (int)ft_strlen(output))
	{
		if (pattern->hash == 1)
			octal_hash(pattern, nul, sp, output);
		else
			with_minus_n_zero(pattern, output);
	}
	else if (pattern->width > (int)ft_strlen(output) && pattern->precision == 0)
		when_prec_is_nul(pattern, nul, sp, output);
	else if (pattern->width <= (int)ft_strlen(output))
		print_and_hash(output, pattern);
	else if (pattern->precision > 0)
	{
		sp = pattern->width - ft_strlen(output);
		nul = 0;
		with_precision(pattern, sp, output);
	}
}

int		print_octal(unsigned long long nbr, t_pattern *pattern)
{
	t_vars	var;

	var.nul = 0;
	var.sp = 0;
	var.res = 1;
	var.output = ft_itoa_base_unsigned(nbr, 8);
	if (pattern->width > 0)
		fundamental(pattern, var.nul, var.sp, var.output);
	else if (pattern->precision > 0 && pattern->width == 0)
		without_width(pattern, var.nul, var.sp, var.output);
	else
		print_and_hash(var.output, pattern);
	if (*(var.output) == '0')
	{
		if ((pattern->precision == 0 && pattern->point == 1))
			if (!(pattern->hash == 1 || pattern->width != 0))
				var.res = 0;
	}
	else
		var.res = ft_strlen(var.output);
	free(var.output);
	return ((!nbr && pattern->hash && !pattern->width && !pattern->precision)
	? 1 : ft_max(ft_max(pattern->width, pattern->precision),
	var.res + pattern->hash));
}
