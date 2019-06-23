/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 08:24:51 by dlabadie          #+#    #+#             */
/*   Updated: 2019/05/07 12:33:37 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRITE_H
# define WRITE_H

# include "ft_printf.h"

unsigned long long		write_unsigned(va_list ap, char	specifier, int liter);

unsigned char			get_unsigned_char(va_list ap);
unsigned short			get_unsigned_short(va_list ap);
unsigned int			get_unsigned_int(va_list ap);
unsigned long			get_unsigned_long(va_list ap);
unsigned long long		get_unsigned_long_long(va_list ap);

char					get_char(va_list ap);
short					get_short(va_list ap);
int						get_int(va_list ap);
long					get_long(va_list ap);
long long				get_long_long(va_list ap);

int						print_double(double digital, t_pattern *pattern);
int						print_char(int c, t_pattern *pattern);
int						print_hex(unsigned long long nbr, t_pattern *pattern);
int						print_string(char	*str, t_pattern *pattern);
int						print_decimal(unsigned long long nbr, \
t_pattern *pattern);
int						print_int(long long nbr, char *output, \
t_pattern *pattern);
int						print_pointer(void	*str, t_pattern *pattern);
int						print_octal(unsigned long long nbr, t_pattern *pattern);
int						print_per(t_pattern *pattern);

#endif
