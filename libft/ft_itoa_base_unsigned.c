/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:16:43 by dlabadie          #+#    #+#             */
/*   Updated: 2019/04/16 14:03:24 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	numlen(unsigned long long num, int base)
{
	if (num == 0)
		return (0);
	else
		return (1 + numlen(num / base, base));
}

static void		fillret(char *ret, unsigned long long num, int base)
{
	if (num != 0)
	{
		*ret = (num % base >= 10) ? 'a' + (num % base) - 10 : '0' + num % base;
		fillret(ret - 1, num / base, base);
	}
}

char			*ft_itoa_base_unsigned(unsigned long long num, int base)
{
	char	*ret;
	size_t	numln;

	if (num == 0)
	{
		ret = (char*)ft_memalloc(1 + 1);
		ret[0] = '0';
		return (ret);
	}
	else
	{
		numln = numlen(num, base);
		ret = (char *)ft_memalloc(numln + 1);
		fillret(ret + numln - 1, num, base);
		return (ret);
	}
}
