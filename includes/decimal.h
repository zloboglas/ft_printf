/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgueren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 13:57:30 by wgueren           #+#    #+#             */
/*   Updated: 2019/05/03 14:19:31 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DECIMAL_H
# define DECIMAL_H

# include "ft_printf.h"

void			printing_chars(char *output, t_pattern *pattern);
void			print_nuls(int sp);
void			print_spaces(int nul);
void			if_zero_here(t_pattern *pattern, char *output, int nul, int sp);
void			if_min_is_nul(t_pattern *pattern, char *output, \
int nul, int sp);

typedef struct	s_vars
{
	char		*output;
	int			nul;
	int			sp;
}				t_vars;

#endif
