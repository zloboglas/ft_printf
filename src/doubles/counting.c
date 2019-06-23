/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 19:26:40 by dlabadie          #+#    #+#             */
/*   Updated: 2019/04/01 08:03:00 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double.h"

void		addpair(unsigned char *sum, unsigned char *num)
{
	int		memory;
	int		i;
	int		tmp;

	memory = 0;
	i = MSIZE;
	while (i >= 0)
	{
		tmp = (sum[i] - '0') + (num[i] - '0') + memory;
		sum[i] = '0' + (tmp % 10);
		memory = tmp / 10;
		i--;
	}
}

void		multiple(unsigned char *res, int mul)
{
	int		memory;
	int		i;
	int		tmp;

	memory = 0;
	i = MSIZE;
	while (i >= 0)
	{
		tmp = (res[i] - '0') * mul + memory;
		res[i] = '0' + tmp % 10;
		memory = tmp / 10;
		i--;
	}
}

long int	take_exp(unsigned char *db)
{
	long int	exp;
	int			i;

	exp = 0;
	i = 6;
	while (i >= 0)
	{
		exp *= 2;
		if (db[7] & (1 << i))
			exp += 1;
		i--;
	}
	i = 7;
	while (i >= 4)
	{
		exp *= 2;
		if (db[6] & (1 << i))
			exp += 1;
		i--;
	}
	return (exp);
}
