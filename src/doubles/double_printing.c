/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_printing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 09:22:19 by dlabadie          #+#    #+#             */
/*   Updated: 2019/04/17 11:04:44 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double.h"

int				the_double_printing(t_pair *doub, \
t_pattern *pattern, t_tab *tab)
{
	if (the_double_rounding((char *)doub->right, MSIZE - tab->exp, pattern))
		plus_one((char *)doub->left + MSIZE, MSIZE);
	if (pattern->minus)
	{
		return (pf_putsign(pattern, tab->sign) + \
				pf_putdouble(doub, tab->intlen, MSIZE - tab->exp, pattern) + \
				ft_putchars(tab->spaces, ' '));
	}
	else
	{
		if (pattern->zero)
		{
			return (pf_putsign(pattern, tab->sign) + \
			ft_putchars(tab->spaces, '0') + \
			pf_putdouble(doub, tab->intlen, MSIZE - tab->exp, pattern));
		}
		else
		{
			return (ft_putchars(tab->spaces, ' ') + \
			pf_putsign(pattern, tab->sign) + \
			pf_putdouble(doub, tab->intlen, MSIZE - tab->exp, pattern));
		}
	}
}
