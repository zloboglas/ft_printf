/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_hex_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgueren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 16:01:48 by wgueren           #+#    #+#             */
/*   Updated: 2019/04/19 16:01:54 by wgueren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hex.h"

void	hex_with_hash_minus(t_pattern *pattern, char *output, int nul, int sp)
{
	if (pattern->point == 1)
		nul = 0;
	else
		nul = pattern->width - ft_strlen(output) - 3;
	sp = pattern->width - 2 - ft_strlen(output);
	if (*output == '0')
	{
		sp += 2;
		print_spacess(nul);
		inhexademical(output, pattern);
		ishash(output, pattern);
	}
	else
	{
		ishash(output, pattern);
		inhexademical(output, pattern);
	}
	print_nulss(sp);
}

void	hex_without_prec(t_pattern *pattern, char *output, int nul, int sp)
{
	if (pattern->zero == 1 && pattern->minus == 0)
		hex_without_minus(pattern, output);
	else if (pattern->hash == 1 && pattern->minus == 0)
	{
		nul = nul - 2;
		print_nulss(pattern->width - 2 - ft_strlen(output));
		ishash(output, pattern);
		inhexademical(output, pattern);
		print_spacess(nul);
	}
	else if (pattern->hash == 1 && pattern->minus == 1)
		hex_with_hash_minus(pattern, output, nul, sp);
	else if (pattern->minus == 1)
	{
		ishash(output, pattern);
		inhexademical(output, pattern);
		print_nulss(pattern->width - ft_strlen(output));
	}
	else
	{
		print_nulss(pattern->width - ft_strlen(output));
		ishash(output, pattern);
		inhexademical(output, pattern);
	}
}

void	hex_with_prec(t_pattern *pattern, char *output, int sp)
{
	if (pattern->precision <= (int)ft_strlen(output) && pattern->minus)
	{
		ishash(output, pattern);
		inhexademical(output, pattern);
		print_nulss(sp - 2);
	}
	else if (pattern->minus == 0)
	{
		print_nulss(sp - 2);
		ishash(output, pattern);
		inhexademical(output, pattern);
	}
	else
	{
		ishash(output, pattern);
		inhexademical(output, pattern);
		print_nulss(pattern->width - 2 - ft_strlen(output));
	}
}

void	more_prec(t_pattern *pattern, char *output, int sp, int nul)
{
	sp = pattern->width - ft_strlen(output);
	nul = 0;
	if (pattern->hash)
		hex_with_prec(pattern, output, sp);
	else if (pattern->precision <= (int)ft_strlen(output) && pattern->minus)
	{
		ishash(output, pattern);
		inhexademical(output, pattern);
		print_nulss(sp);
	}
	else
	{
		print_nulss(sp);
		ishash(output, pattern);
		inhexademical(output, pattern);
	}
}
