/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgueren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 14:07:35 by wgueren           #+#    #+#             */
/*   Updated: 2019/04/19 14:07:36 by wgueren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEX_H
# define HEX_H

# include "ft_printf.h"

void	ishash(char *output, t_pattern *pattern);
void	inhexademical(char *output, t_pattern *pattern);
void	print_nulss(int sp);
void	print_spacess(int nul);
void	hex_without_hash(t_pattern *pattern, char *output);
void	hex_with_hash(t_pattern *pattern, char *output, int sp);
void	hex_with_point_n_zero(t_pattern *pattern, char *output);
void	hex_without_point_n_zero(t_pattern *pattern, char *output);
void	hex_with_hash_minus(t_pattern *pattern, char *output, int nul, int sp);
void	hex_without_prec(t_pattern *pattern, char *output, int nul, int sp);
void	hex_with_prec(t_pattern *pattern, char *output, int sp);
void	more_prec(t_pattern *pattern, char *output, int sp, int nul);
void	hex_without_minus(t_pattern *pattern, char *output);

#endif
