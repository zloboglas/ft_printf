/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgueren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 13:52:32 by wgueren           #+#    #+#             */
/*   Updated: 2019/05/03 14:18:53 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OCTAL_H
# define OCTAL_H

# include "ft_printf.h"

void			octal_hash(t_pattern *pattern, int nul, \
int sp, char *output);
void			without_minus(t_pattern *pattern, int nul, \
int sp, char *output);
void			without_width(t_pattern *pattern, int nul, \
int sp, char *output);
void			prec_hash(t_pattern *pattern, \
int sp, char *output);
void			with_precision(t_pattern *pattern, \
int sp, char *output);
void			when_prec_is_nul(t_pattern *pattern, int nul, \
int sp, char *output);
void			print_and_hash(char *output, t_pattern *pattern);
void			print_nul(int sp);
void			print_space(int nul);
void			with_minus_n_zero(t_pattern *pattern, char *output);
void			with_hash_n_minus(t_pattern *pattern, int nul, \
int sp, char *output);

typedef struct	s_vars
{
	char		*output;
	int			nul;
	int			sp;
	int			res;
}				t_vars;

#endif
