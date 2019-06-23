/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 07:16:03 by dlabadie          #+#    #+#             */
/*   Updated: 2019/04/02 07:33:05 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWITCH_H
# define SWITCH_H

# include "ft_printf.h"

int		write_double(va_list ap, t_pattern *pattern);
int		write_string(va_list ap, t_pattern *pattern);
int		write_int(va_list ap, t_pattern *pattern);
int		write_pointer(va_list ap, t_pattern *pattern);
int		write_char(va_list ap, t_pattern *pattern);
int		write_decimal(va_list ap, t_pattern *pattern);
int		write_octal(va_list ap, t_pattern *pattern);
int		write_hex(va_list ap, t_pattern *pattern);
int		write_per(va_list ap, t_pattern *pattern);

#endif
