/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgueren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 20:07:41 by wgueren           #+#    #+#             */
/*   Updated: 2018/12/07 16:45:13 by wgueren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(unsigned long long nb)
{
	unsigned long long	value;
	char				digit;

	value = nb;
	if (value >= 10)
		ft_putnbr(value / 10);
	digit = (value % 10) + '0';
	ft_putchar(digit);
}
