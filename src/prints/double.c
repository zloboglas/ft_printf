/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 09:17:22 by dlabadie          #+#    #+#             */
/*   Updated: 2019/04/04 08:56:30 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double.h"

int				print_double(double digital, t_pattern *pattern)
{
	unsigned char	*db;
	t_pair			*doub;
	t_tab			tab;
	int				ln;

	db = (unsigned char *)&digital;
	tab.sign = ((db[7] & (1 << 7)) != 0) ? (char)'-' : (char)'+';
	tab.exp = (take_exp(db) - 1023);
	doub = double2pair(tab.exp, db);
	tab.intlen = pf_intlen((unsigned char *)doub->left);
	tab.spaces = pf_spaces(pf_minwidth(tab.intlen, \
	tab.sign, pattern), pattern);
	tab.exp = 52 - tab.exp;
	ln = the_double_printing(doub, pattern, &tab);
	free(doub->left);
	free(doub->right);
	free(doub);
	return (ln);
}
