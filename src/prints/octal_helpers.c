/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgueren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 11:50:35 by wgueren           #+#    #+#             */
/*   Updated: 2019/04/19 11:50:38 by wgueren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "octal.h"

void	octal_hash(t_pattern *pattern, int nul, int sp, char *output)
{
	if (pattern->minus == 1)
	{
		sp = pattern->width - pattern->precision;
		nul = pattern->precision - ft_strlen(output) -
		(pattern->hash && *output != '0');
		print_space(nul);
		print_and_hash(output, pattern);
		print_nul(sp);
	}
	else
	{
		sp = pattern->width - pattern->precision;
		nul = pattern->precision - ft_strlen(output)
		- (pattern->hash && *output != '0');
		print_nul(sp);
		print_space(nul);
		print_and_hash(output, pattern);
	}
}

void	without_minus(t_pattern *pattern, int nul, int sp, char *output)
{
	if (pattern->point == 1)
	{
		sp = pattern->width - ft_strlen(output) -
		(pattern->hash == 1 && *output != '0');
		print_nul(sp);
		print_space(nul);
		print_and_hash(output, pattern);
	}
	else if (pattern->point == 0)
	{
		nul = pattern->width - ft_strlen(output) -
		(pattern->hash == 1 && *output != '0');
		print_space(nul);
		print_nul(sp);
		print_and_hash(output, pattern);
	}
	else
	{
		nul = pattern->width - ft_strlen(output);
		print_nul(sp);
		print_space(nul);
		print_and_hash(output, pattern);
	}
}

void	without_width(t_pattern *pattern, int nul, int sp, char *output)
{
	if (pattern->precision < (int)ft_strlen(output))
	{
		if (pattern->hash == 1)
			sp = pattern->width - ft_strlen(output) -
		(pattern->hash && *output != '0');
		else
			sp = pattern->width - ft_strlen(output);
		print_nul(sp);
		print_space(nul);
		print_and_hash(output, pattern);
	}
	else
	{
		if (pattern->hash == 1)
			nul = pattern->precision - ft_strlen(output) -
		(pattern->hash && *output != '0');
		else
			nul = pattern->precision - ft_strlen(output);
		print_nul(sp);
		print_space(nul);
		print_and_hash(output, pattern);
	}
}

void	prec_hash(t_pattern *pattern, int sp, char *output)
{
	if (pattern->precision <= (int)ft_strlen(output) && pattern->minus)
	{
		print_and_hash(output, pattern);
		print_nul(sp - (pattern->hash && *output != '0'));
	}
	else if (pattern->minus == 0)
	{
		print_nul(sp - (pattern->hash && *output != '0'));
		print_and_hash(output, pattern);
	}
	else
	{
		print_and_hash(output, pattern);
		print_nul(pattern->width - (pattern->hash && *output != '0')
			- ft_strlen(output));
	}
}

void	with_precision(t_pattern *pattern, int sp, char *output)
{
	if (pattern->hash)
		prec_hash(pattern, sp, output);
	else if (pattern->precision <= (int)ft_strlen(output) && pattern->minus)
	{
		print_and_hash(output, pattern);
		print_nul(sp);
	}
	else
	{
		print_nul(sp);
		print_and_hash(output, pattern);
	}
}
