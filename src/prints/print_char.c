/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgueren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 10:28:29 by wgueren           #+#    #+#             */
/*   Updated: 2019/04/15 07:25:01 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "write.h"

int				print_char(int c, t_pattern *pattern)
{
	char	symbol;
	int		i;

	symbol = (int)c;
	if (pattern->minus)
	{
		write(1, &symbol, 1);
		i = 0;
		while (i < pattern->width - 1)
		{
			write(1, " ", 1);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < pattern->width - 1)
		{
			write(1, " ", 1);
			i++;
		}
		write(1, &symbol, 1);
	}
	return (ft_max(pattern->width, 1));
}
