/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_for_double.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 19:07:57 by dlabadie          #+#    #+#             */
/*   Updated: 2019/04/04 07:46:21 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double.h"

int		pf_intlen(unsigned char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[j] == '0')
		j++;
	while (str[j])
	{
		j++;
		i++;
	}
	return (i);
}

int		pf_minwidth(int intlen, char sign, t_pattern *pattern)
{
	int		res;

	res = intlen + pattern->precision;
	if (intlen == 0)
		res += 1;
	if (pattern->precision != 0 || pattern->hash)
		res += 1;
	if (pattern->space || pattern->plus || sign == '-')
		res += 1;
	return (res);
}

int		pf_spaces(int minwidth, t_pattern *pattern)
{
	int		res;

	if (pattern->width > minwidth)
	{
		res = pattern->width - minwidth;
		return (res);
	}
	else
		return (0);
}
