/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgueren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 10:25:21 by wgueren           #+#    #+#             */
/*   Updated: 2019/04/17 11:17:58 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "write.h"

int		write_char(va_list ap, t_pattern *pattern)
{
	int		c;

	c = va_arg(ap, int);
	return (print_char(c, pattern));
}
