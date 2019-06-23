/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_sim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgueren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 08:16:58 by wgueren           #+#    #+#             */
/*   Updated: 2019/04/19 09:13:27 by wgueren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printing_chars(char *output, t_pattern *pattern)
{
	int		i;

	i = 0;
	if (*output == '0')
	{
		if (pattern->precision >= 1 || pattern->point == 0)
			ft_putchar('0');
		return ;
	}
	while (i < (int)ft_strlen(output))
	{
		ft_putchar(output[i]);
		i++;
	}
}

void	print_nuls(int sp)
{
	while (sp > 0)
	{
		ft_putchar(' ');
		sp--;
	}
}

void	print_spaces(int nul)
{
	while (nul > 0)
	{
		ft_putchar('0');
		nul--;
	}
}

void	if_zero_here(t_pattern *pattern, char *output, int nul, int sp)
{
	if (pattern->zero == 1)
	{
		nul = pattern->precision - ft_strlen(output);
		sp = pattern->width - pattern->precision;
		print_nuls(sp);
		print_spaces(nul);
		printing_chars(output, pattern);
	}
	else
	{
		nul = pattern->precision - ft_strlen(output);
		sp = pattern->width - pattern->precision;
		print_nuls(sp);
		print_spaces(nul);
		printing_chars(output, pattern);
	}
}

void	if_min_is_nul(t_pattern *pattern, char *output, int nul, int sp)
{
	if (pattern->point == 1)
	{
		nul = 0;
		sp = pattern->width - ft_strlen(output);
		print_nuls(sp);
		print_spaces(nul);
		printing_chars(output, pattern);
	}
	else if (pattern->point == 0)
	{
		nul = pattern->width - ft_strlen(output);
		sp = 0;
		print_spaces(nul);
		print_nuls(sp);
		printing_chars(output, pattern);
	}
	else
	{
		nul = pattern->width - ft_strlen(output);
		sp = 0;
		print_nuls(sp);
		print_spaces(nul);
		printing_chars(output, pattern);
	}
}
