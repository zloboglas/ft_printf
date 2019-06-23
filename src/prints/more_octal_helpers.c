/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_octal_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgueren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 12:39:44 by wgueren           #+#    #+#             */
/*   Updated: 2019/04/19 12:39:46 by wgueren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_and_hash(char *output, t_pattern *pattern)
{
	int i;

	i = 0;
	if (*output == '0' && pattern->precision == 0 && pattern->point == 1)
	{
		if (pattern->hash == 1)
			ft_putchar('0');
		else
		{
			if (pattern->width != 0)
				ft_putchar(' ');
		}
		return ;
	}
	if (pattern->hash == 1 && *output != '0')
		ft_putchar('0');
	while (i < (int)ft_strlen(output))
	{
		ft_putchar(output[i]);
		i++;
	}
}

void	print_nul(int sp)
{
	while (sp > 0)
	{
		ft_putchar(' ');
		sp--;
	}
}

void	print_space(int nul)
{
	while (nul > 0)
	{
		ft_putchar('0');
		nul--;
	}
}

void	with_minus_n_zero(t_pattern *pattern, char *output)
{
	if (pattern->minus == 1 && pattern->precision > pattern->width)
	{
		print_space(pattern->precision - ft_strlen(output));
		print_nul(pattern->width - pattern->precision);
		print_and_hash(output, pattern);
	}
	else if (pattern->minus == 1)
	{
		print_space(pattern->precision - ft_strlen(output));
		print_and_hash(output, pattern);
		print_nul(pattern->width - pattern->precision);
	}
	else
	{
		print_nul(pattern->width - pattern->precision);
		print_space(pattern->precision - ft_strlen(output));
		print_and_hash(output, pattern);
	}
}

void	with_hash_n_minus(t_pattern *pattern, int nul, int sp, char *output)
{
	if (pattern->point == 1)
	{
		sp = pattern->width - ft_strlen(output) - (pattern->hash == 1);
		if (*output == '0')
			sp = pattern->width - ft_strlen(output) - (pattern->hash == 1) + 1;
	}
	else
	{
		nul = pattern->width - ft_strlen(output);
		sp = pattern->width - (pattern->hash && *output != '0')
		- ft_strlen(output);
	}
	print_and_hash(output, pattern);
	print_nul(sp);
}
