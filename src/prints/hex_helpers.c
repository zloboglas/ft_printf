/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgueren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 14:06:37 by wgueren           #+#    #+#             */
/*   Updated: 2019/04/19 14:24:26 by wgueren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ishash(char *output, t_pattern *pattern)
{
	if (pattern->hash == 1 && *output != '0')
	{
		ft_putchar('0');
		if (pattern->liter == 1)
			ft_putchar('x');
		else
			ft_putchar('X');
	}
	else if (pattern->width != 0 && pattern->hash == 1 && \
	*output == '0' && !pattern->zero)
	{
		if (pattern->minus == 0)
		{
			ft_putchar(' ');
			ft_putchar(' ');
		}
	}
}

void	print_for_nul(t_pattern *pattern)
{
	if ((pattern->precision >= 1 && pattern->point == 1) || pattern->point == 0)
		ft_putchar('0');
	else
	{
		if (pattern->width >= 1)
			ft_putchar(' ');
	}
}

void	inhexademical(char *output, t_pattern *pattern)
{
	int		i;

	i = 0;
	if (pattern->liter == 1 && *output != '0')
	{
		while (i < (int)ft_strlen(output))
		{
			ft_putchar(output[i]);
			i++;
		}
	}
	else if (*output != '0')
	{
		i = 0;
		while (i < (int)ft_strlen(output))
		{
			if (output[i] >= 'a' && output[i] <= 'z')
				ft_putchar(output[i] - 32);
			else
				ft_putchar(output[i]);
			i++;
		}
	}
	else
		print_for_nul(pattern);
}

void	print_nulss(int sp)
{
	while (sp > 0)
	{
		ft_putchar(' ');
		sp--;
	}
}

void	print_spacess(int nul)
{
	while (nul > 0)
	{
		ft_putchar('0');
		nul--;
	}
}
