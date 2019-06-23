/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgueren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 10:25:34 by wgueren           #+#    #+#             */
/*   Updated: 2019/04/10 09:54:09 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "write.h"

int		write_string(va_list ap, t_pattern *pattern)
{
	char	*str;

	str = (char*)va_arg(ap, char*);
	return (print_string(str, pattern));
}
