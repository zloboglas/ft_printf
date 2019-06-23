/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgueren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 10:28:42 by wgueren           #+#    #+#             */
/*   Updated: 2019/04/13 15:28:05 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "write.h"
#include "string.h"

void	print_string_sp(int i, int n2)
{
	while (i < n2)
	{
		write(1, " ", 1);
		i++;
	}
}

int		print_string(char *str, t_pattern *pattern)
{
	int		n1;
	int		n2;
	int		len;

	len = (str == NULL) ? 6 : ft_strlen(str);
	if (pattern->point)
		n1 = ft_min(len, pattern->precision);
	else
		n1 = len;
	n2 = pattern->width - n1;
	if (pattern->minus)
	{
		write(1, (str == NULL) ? "(null)" : str, n1);
		print_string_sp(0, n2);
	}
	else
	{
		print_string_sp(0, n2);
		write(1, (str == NULL) ? "(null)" : str, n1);
	}
	return (n1 + ((n2 < 0) ? 0 : n2));
}
