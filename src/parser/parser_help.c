/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_help.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgueren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 13:30:46 by wgueren           #+#    #+#             */
/*   Updated: 2019/04/20 13:37:15 by wgueren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_pattern	new_value(void)
{
	t_pattern	tmp;

	tmp.hash = 0;
	tmp.minus = 0;
	tmp.plus = 0;
	tmp.space = 0;
	tmp.zero = 0;
	tmp.width = 0;
	tmp.precision = 0;
	tmp.specifier = 'n';
	tmp.percent = 0;
	tmp.point = 0;
	return (tmp);
}

int			about_size(char *fmt, int start, t_pattern *pattern)
{
	if (is_sizers(fmt[start]))
	{
		if (pattern->hash == 1 || pattern->minus == 1 ||
			pattern->plus == 1 || pattern->space == 1 || pattern->zero == 1 ||
			pattern->point || pattern->precision > 0 || pattern->width > 0)
			what_the_size(pattern, fmt);
		else
			what_the_size(pattern, fmt);
		return (1);
	}
	return (0);
}

int			while_for_dig(char *fmt, int start)
{
	while (ft_isdigit(fmt[start]))
		start++;
	return (start);
}

int			pars_precision(t_pattern *pattern, char *fmt, int start)
{
	start++;
	pattern->point = 1;
	if (ft_isdigit(fmt[start]))
	{
		pattern->precision = ft_atoi(&fmt[start]);
		start = while_for_dig(fmt, start);
	}
	return (start);
}

void		ft_initpattern(char *fmt, t_pattern *pattern)
{
	int		start;
	int		end;

	start = 0;
	end = ft_strlen(fmt);
	calculate_flags(pattern, fmt);
	while (start < end)
	{
		if (is_flag(fmt[start]))
			start++;
		if (fmt[start] == '.')
			start = pars_precision(pattern, fmt, start);
		else if (ft_isdigit(fmt[start]))
		{
			pattern->width = ft_atoi(&fmt[start]);
			start = while_for_dig(fmt, start);
		}
		start += about_size(fmt, start, pattern);
	}
	free(fmt);
}
