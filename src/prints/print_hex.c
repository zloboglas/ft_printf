/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgueren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 10:28:52 by wgueren           #+#    #+#             */
/*   Updated: 2019/04/20 17:24:39 by wgueren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hex.h"

void	prec_less_then_len(t_pattern *pattern, char *output, int nul)
{
	if (pattern->hash == 1)
	{
		print_nulss(pattern->width - ft_strlen(output) - 2);
		print_spacess(nul);
		ishash(output, pattern);
		inhexademical(output, pattern);
	}
	else
	{
		print_nulss(pattern->width - ft_strlen(output));
		print_spacess(nul);
		inhexademical(output, pattern);
	}
}

void	len_less_then_prec(t_pattern *pattern, char *output, int sp)
{
	if (pattern->hash == 1)
	{
		ishash(output, pattern);
		print_nulss(sp);
		print_spacess(pattern->precision - ft_strlen(output));
		inhexademical(output, pattern);
	}
	else
	{
		print_nulss(sp);
		print_spacess(pattern->precision - ft_strlen(output));
		inhexademical(output, pattern);
	}
}

void	most_important(t_pattern *pattern, char *output, int sp, int nul)
{
	if (pattern->precision > (int)ft_strlen(output))
	{
		if (pattern->hash == 1)
			hex_with_hash(pattern, output, sp);
		else
			hex_without_hash(pattern, output);
	}
	else if (pattern->width > (int)ft_strlen(output) && pattern->precision == 0)
		hex_without_prec(pattern, output, nul, sp);
	else if (pattern->width <= (int)ft_strlen(output))
	{
		ishash(output, pattern);
		inhexademical(output, pattern);
	}
	else if (pattern->precision > 0)
	{
		more_prec(pattern, output, sp, nul);
	}
}

int		count_ret(t_pattern *pattern, char *output, int nbr)
{
	int		ret;

	ret = ft_max(ft_max(pattern->width, pattern->precision + 2 * pattern->hash
	* (nbr != 0)), ft_strlen(output) * (!(nbr == 0 && pattern->point)) + 2
	* pattern->hash * (nbr != 0));
	return (ret);
}

int		print_hex(unsigned long long nbr, t_pattern *pattern)
{
	char	*output;
	int		nul;
	int		sp;

	nul = 0;
	sp = 0;
	output = ft_itoa_base_unsigned(nbr, 16);
	if (pattern->width > 0)
		most_important(pattern, output, sp, nul);
	else if (pattern->precision > 0 && pattern->width == 0)
	{
		if (pattern->precision < (int)ft_strlen(output))
			prec_less_then_len(pattern, output, nul);
		else
			len_less_then_prec(pattern, output, sp);
	}
	else
	{
		if (pattern->hash == 1)
			ishash(output, pattern);
		inhexademical(output, pattern);
	}
	nul = count_ret(pattern, output, nbr);
	free(output);
	return (nul);
}
