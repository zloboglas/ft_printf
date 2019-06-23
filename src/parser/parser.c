/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgueren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 09:43:42 by wgueren           #+#    #+#             */
/*   Updated: 2019/05/07 13:55:34 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	fmt_in_pattern(char type, t_pattern *pattern)
{
	if (type == 'g')
	{
		pattern->liter = 4;
		if (pattern->point == 0)
			pattern->precision = 6;
	}
	else if ((type == 'f' || type == 'F') && pattern->point == 0)
		pattern->precision = 6;
	else if (type == 'x')
		pattern->liter = TRUE;
	else if (type == 'O' || type == 'U' || \
	type == 'D' || type == 'I')
		pattern->liter = 2;
	else
		pattern->liter = FALSE;
}

int		searching_time(t_pattern *pattern, char type, va_list ap)
{
	int		count_output;

	count_output = 0;
	if (is_type(type))
	{
		fmt_in_pattern(type, pattern);
		count_output += pf_switch(ap, pattern, type);
		*pattern = new_value();
	}
	return (count_output);
}

int		validaterinest_function(char *fmt, int i, int *end)
{
	int		flag;

	flag = 0;
	*end = 1;
	while (!is_type(fmt[i + *end]))
	{
		if (!is_sizers(fmt[i + *end]) && !ft_isdigit(fmt[i + *end])
			&& !is_flag(fmt[i + *end]) && !is_type(fmt[i + *end])
			&& fmt[i + *end] != '.')
		{
			flag = 1;
			break ;
		}
		(*end)++;
	}
	return (flag);
}

void	putting_char(char char2put, int a)
{
	ft_putchar(char2put);
	a++;
}

int		pf_parser(char *fmt, va_list ap)
{
	t_pattern	pattern;
	int			count_output;
	int			i;
	int			end;

	i = 0;
	count_output = 0;
	pattern = new_value();
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			if (!validaterinest_function(fmt, i, &end))
			{
				ft_initpattern(ft_strsub(fmt, i + 1, end - 1), &pattern);
				i += end + 1;
				count_output += searching_time(&pattern, fmt[i - 1], ap);
			}
			else
				i += end;
		}
		else
			putting_char(fmt[i++], count_output++);
	}
	return (count_output);
}
