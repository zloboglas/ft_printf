/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_per.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgueren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:18:56 by wgueren           #+#    #+#             */
/*   Updated: 2019/04/13 15:22:28 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "write.h"

void	print_sp(t_pattern *pattern)
{
	while (pattern->width > 1)
	{
		ft_putchar(' ');
		pattern->width--;
	}
	ft_putchar('%');
}

void	print_n(t_pattern *pattern)
{
	while (pattern->width > 1)
	{
		ft_putchar('0');
		pattern->width--;
	}
	ft_putchar('%');
}

int		print_per(t_pattern *pattern)
{
	int		ret;

	ret = pattern->width;
	if (pattern->minus == 1)
	{
		ft_putchar('%');
		while (pattern->width > 1)
		{
			ft_putchar(' ');
			pattern->width--;
		}
	}
	else if (pattern->zero && ret > 0)
		print_n(pattern);
	else if (pattern->zero == 1)
		print_sp(pattern);
	else
		print_sp(pattern);
	return ((ret) ? ret : 1);
}
