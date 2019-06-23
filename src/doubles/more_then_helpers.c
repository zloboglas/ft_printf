/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_then_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 19:12:40 by dlabadie          #+#    #+#             */
/*   Updated: 2019/05/07 14:23:01 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double.h"

void	*pf_memalloc(size_t size)
{
	char		*area;
	size_t		i;

	i = size;
	area = (char*)malloc(size + 1);
	if (area == NULL)
		return (NULL);
	while (i + 1)
	{
		area[i] = '0';
		i--;
	}
	area[size] = (char)0;
	return ((void*)area);
}

int		pf_putsign(t_pattern *pattern, char sign)
{
	if (pattern->plus)
	{
		if (sign == '-')
			write(1, "-", 1);
		else
			write(1, "+", 1);
	}
	else if (pattern->space)
	{
		if (sign == '-')
			write(1, "-", 1);
		else
			write(1, " ", 1);
	}
	else if (sign == '-')
		write(1, "-", 1);
	else
		return (0);
	return (1);
}

void	print_fragugagu(char *str, int qwer, t_pattern *pattern)
{
	int		i;

	if (pattern->liter == 4)
	{
		i = 0;
		while (i < qwer && str[i] != '0')
		{
			ft_putchar(str[i]);
			i++;
		}
	}
	else
	{
		if (qwer < pattern->precision)
		{
			write(1, str, qwer);
			ft_putchars(pattern->precision - qwer, '0');
		}
		else
			write(1, str, pattern->precision);
	}
}

int		pf_putdouble(t_pair *doub, int intlen, int fragpoint, \
t_pattern *pattern)
{
	int		qwer;
	int		ret;

	ret = 0;
	if (intlen == 0)
		ret += ft_putchars(1, '0');
	else
	{
		write(1, (char *)doub->left + (MSIZE - intlen + 1), intlen);
		ret += intlen;
	}
	if (pattern->precision != 0 || pattern->hash != 0)
		ret += ft_putchars(1, '.');
	qwer = (MSIZE - fragpoint >= 0) ? MSIZE - fragpoint : 0;
	print_fragugagu((char*)doub->right + fragpoint, qwer, pattern);
	return (ret + pattern->precision);
}
