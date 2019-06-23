/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubtopair.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 19:57:47 by dlabadie          #+#    #+#             */
/*   Updated: 2019/04/01 08:28:17 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double.h"

void		double2pair_integer(t_pair *tmp, t_pair *pair, \
long int exp, unsigned char *d)
{
	int		j;

	((unsigned char*)tmp->left)[MSIZE] = '1';
	j = 52 - exp;
	while (j <= 52)
	{
		if (d[j / 8] & (1 << j % 8) || j == 52)
		{
			addpair(pair->left, tmp->left);
		}
		multiple(tmp->left, 2);
		j++;
	}
}

void		double2pair_fractional(t_pair *tmp, t_pair *pair, \
long int exp, unsigned char *d)
{
	int		k;

	((unsigned char*)tmp->right)[MSIZE] = '1';
	multiple(tmp->right, 5);
	k = 52 - exp - 1;
	while (k >= 0)
	{
		if (k > 52)
			multiple(tmp->right, 5);
		else if (k == 52)
		{
			addpair(pair->right, tmp->right);
			multiple(pair->right, 10);
			multiple(tmp->right, 5);
		}
		else
		{
			if (d[k / 8] & (1 << k % 8))
				addpair(pair->right, tmp->right);
			multiple(pair->right, 10);
			multiple(tmp->right, 5);
		}
		k--;
	}
}

void		free_pair(t_pair *pair)
{
	free(pair->left);
	free(pair->right);
	free(pair);
}

t_pair		*pair_alloc(void)
{
	t_pair		*pair;

	pair = malloc(sizeof(t_pair));
	pair->left = pf_memalloc(MSIZE + 1);
	pair->right = pf_memalloc(MSIZE + 1);
	return (pair);
}

t_pair		*double2pair(long int exp, unsigned char *d)
{
	t_pair		*pair;
	t_pair		*tmp;

	pair = pair_alloc();
	tmp = pair_alloc();
	double2pair_integer(tmp, pair, exp, d);
	double2pair_fractional(tmp, pair, exp, d);
	free_pair(tmp);
	return (pair);
}
