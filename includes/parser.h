/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 08:27:38 by dlabadie          #+#    #+#             */
/*   Updated: 2019/04/20 14:07:20 by wgueren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "ft_printf.h"

int			pf_switch(va_list ap, t_pattern *pattern, char type);
int			is_flag(char c);
int			is_type(char c);
void		calculate_flags(t_pattern *tmp, char *flg);
void		what_the_size(t_pattern *tmp, char *s);
int			is_sizers(char c);
int			about_size(char *fmt, int start, t_pattern *pattern);
int			while_for_dig(char *fmt, int start);
int			pars_precision(t_pattern *pattern, char *fmt, int start);
void		ft_initpattern(char *fmt, t_pattern *pattern);
t_pattern	new_value(void);

#endif
