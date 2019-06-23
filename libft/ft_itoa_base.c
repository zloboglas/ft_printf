/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 10:07:17 by dlabadie          #+#    #+#             */
/*   Updated: 2019/04/12 15:18:18 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	numlen(int num, int base)
{
	if (num < 0 && num - 1 > 0)
		return (1 + numlen(num / base, base));
	else if (num < 0)
		return (1 + numlen((-1) * num, base));
	else if (num > 0)
		return (1 + numlen(num / base, base));
	else
		return (0);
}

static void		fillret(char *ret, unsigned int num, int base)
{
	if (num != 0)
	{
		*ret = (num % base >= 10) ? 'a' + (num % base) - 10 : '0' + num % base;
		fillret(ret - 1, num / base, base);
	}
}

char			*ft_itoa_base(int num, int base)
{
	char	*ret;
	size_t	numln;

	numln = numlen(num, base);
	ret = (char*)ft_memalloc(numln + 1);
	if (num < 0)
		ret[0] = '-';
	fillret(ret + numln - 1, (unsigned int)(num < 0) ? \
	((-1) * (long long int)num) : num, base);
	return (ret);
}
