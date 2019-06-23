/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_for_pars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgueren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 09:46:30 by wgueren           #+#    #+#             */
/*   Updated: 2019/04/02 09:47:07 by wgueren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	calculate_flags(t_pattern *tmp, char *flg)
{
	int		lox23;

	lox23 = 0;
	while (*flg)
	{
		if (*flg == '#')
			tmp->hash = 1;
		else if (*flg == '+')
			tmp->plus = 1;
		else if (*flg == '-')
			tmp->minus = 1;
		else if (*flg == ' ')
			tmp->space = 1;
		else if (lox23 == 0)
		{
			if (*flg == '0' && *(flg + 1) != '.')
				tmp->zero = 1;
		}
		else if (lox23 != 0)
			if (*flg == '0' && *(flg - 1) != '.'
			&& *(flg + 1) != '.' && !ft_isdigit(*(flg - 1)))
				tmp->zero = 1;
		flg++;
		lox23++;
	}
}

int		is_flag(char c)
{
	if (c == '#' || c == '-' || c == '+'
		|| (c == '0' && (c + 1) != '.') || c == ' ')
		return (1);
	else
		return (0);
}

int		is_sizers(char c)
{
	if (c == 'h' || c == 'l' || c == 'L')
		return (1);
	else
		return (0);
}

void	what_the_size(t_pattern *tmp, char *s)
{
	while (*s && tmp->specifier == 'n')
	{
		if (*s == 'h' && (*(s + 1)) == 'h')
			tmp->specifier = HH;
		else if (*s == 'h' && (*(s + 1)) != 'h')
			tmp->specifier = H;
		if (*s == 'l' && (*(s + 1)) != 'l')
			tmp->specifier = L;
		if (*s == 'l' && (*(s + 1)) == 'l')
			tmp->specifier = LL;
		if (*s == 'L')
			tmp->specifier = LLL;
		s++;
	}
}

int		is_type(char c)
{
	if (c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'o' || c == 'u'
		|| c == 'x' || c == 'X' || c == 'f' ||
		c == 'c' || c == 'C' || c == '%' || \
		c == 'S' || c == 'U' || c == 'D' || \
		c == 'I' || c == 'O' || c == 'g' || c == 'F')
		return (1);
	else
		return (0);
}
