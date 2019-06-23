/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 07:11:01 by dlabadie          #+#    #+#             */
/*   Updated: 2019/04/12 13:26:24 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLE_H
# define DOUBLE_H

# define MSIZE 4200

# include "ft_printf.h"

typedef struct	s_tab
{
	long int	exp;
	int			intlen;
	int			spaces;
	char		sign;
}				t_tab;

void			*pf_memalloc(size_t size);
int				pf_putchars(int len, char symbol);
int				pf_putsign(t_pattern *pattern, char sign);
int				pf_putdouble(t_pair *doub, int intlen, int fragpoint, \
t_pattern *pattern);

t_pair			*pair_alloc();

int				the_double_printing(t_pair *doub, t_pattern *pattern, \
t_tab *tab);

t_pair			*double2pair(long int exp, unsigned char *d);

int				min(int a, int b);
int				pf_intlen(unsigned char *str);
int				pf_minwidth(int intlen, char sign, t_pattern *pattern);
int				pf_spaces(int minwidth, t_pattern *pattern);

void			addpair(unsigned char *sum, unsigned char *num);
void			multiple(unsigned char *res, int mul);

int				plus_one(char *fractional, int index);
int				the_double_rounding(char *fractional, int fracpoint, \
t_pattern *pattern);
long int		take_exp(unsigned char *db);

#endif
