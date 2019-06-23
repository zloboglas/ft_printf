/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rounding.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 19:23:57 by dlabadie          #+#    #+#             */
/*   Updated: 2019/04/10 10:50:15 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double.h"

int		plus_one(char *fractional, int index)
{
	if (index <= 0)
		return (1);
	else if (*fractional == '9')
	{
		*fractional = '0';
		return (plus_one(fractional - 1, index - 1));
	}
	else
	{
		*fractional += 1;
		return (0);
	}
}

int		the_double_rounding(char *fractional, int fracpoint, t_pattern *pattern)
{
	int		frgpnt;

	frgpnt = ft_min(MSIZE, fracpoint + pattern->precision);
	if (fractional[frgpnt] >= '5')
		return (plus_one(fractional + frgpnt - 1, pattern->precision));
	else
		return (0);
}
