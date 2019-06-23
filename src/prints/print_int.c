/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgueren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 10:29:42 by wgueren           #+#    #+#             */
/*   Updated: 2019/04/15 07:27:00 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		set_sign(long long d, t_pattern *pattern)
{
	char		sign;

	if (d < 0)
		sign = '-';
	else if (pattern->plus > 0)
	{
		sign = '+';
	}
	else
	{
		if (pattern->space)
			sign = ' ';
		else
			sign = '\0';
	}
	return (sign);
}

static int		count_zeroes(t_pattern *pattern, char sign, int outpulen)
{
	int			zeroes;

	if (pattern->point == TRUE)
		zeroes = pattern->precision - outpulen;
	else
	{
		if (pattern->zero == TRUE && pattern->minus == FALSE)
			zeroes = pattern->width - outpulen - (sign != '\0');
		else
			zeroes = 0;
	}
	zeroes = (zeroes < 0) ? 0 : zeroes;
	return (zeroes);
}

static int		count_spaces(t_pattern *pattern, char sign, \
int zeroes, int outputlen)
{
	int			spaces;

	if (pattern->zero == TRUE && pattern->minus == FALSE)
	{
		if (pattern->point == FALSE)
			spaces = 0;
		else
			spaces = pattern->width - (sign != '\0') - zeroes - outputlen;
	}
	else
		spaces = pattern->width - (sign != '\0') - zeroes - outputlen;
	spaces = (spaces < 0) ? 0 : spaces;
	return (spaces);
}

static int		output_len(t_pattern *pattern, char *output)
{
	int			outputlen;

	if (*output == '0')
	{
		if (pattern->point == FALSE)
			outputlen = 1;
		else
			outputlen = 0;
	}
	else
		outputlen = (int)ft_strlen(output);
	return (outputlen);
}

int				print_int(long long d, char *output, t_pattern *pattern)
{
	int			zeroes;
	int			spaces;
	char		sign;
	int			outputlen;

	sign = set_sign(d, pattern);
	outputlen = output_len(pattern, output);
	zeroes = count_zeroes(pattern, sign, outputlen);
	spaces = count_spaces(pattern, sign, zeroes, outputlen);
	if (pattern->minus == FALSE)
		ft_putchars(spaces, ' ');
	if (sign != '\0')
		ft_putchar(sign);
	ft_putchars(zeroes, '0');
	if (outputlen > 0)
		write(1, output, outputlen);
	if (pattern->minus == TRUE)
		ft_putchars(spaces, ' ');
	free(output);
	return (spaces + zeroes + (sign != '\0') + outputlen);
}
