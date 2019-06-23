/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgueren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 13:28:09 by wgueren           #+#    #+#             */
/*   Updated: 2019/04/15 14:04:12 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define L 'l'
# define LL 'L'
# define H 'h'
# define HH 'H'
# define LLL 'A'

# define TRUE 1
# define FALSE 0

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

typedef	struct	s_pair
{
	void		*left;
	void		*right;
}				t_pair;

typedef struct	s_pattern
{
	char		zero;
	int			space;
	char		plus;
	char		minus;
	char		hash;
	int			precision;
	int			width;
	char		specifier;
	int			percent;
	int			point;
	int			liter;
}				t_pattern;

int				ft_printf(const char *format, ...);

int				pf_parser(char *fmt, va_list ap);

#endif
