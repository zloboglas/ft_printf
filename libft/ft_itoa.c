/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgueren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 19:15:33 by wgueren           #+#    #+#             */
/*   Updated: 2018/12/10 12:20:26 by wgueren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_len(int n)
{
	int		i;

	i = 0;
	if (0 > n)
	{
		i++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static int		maxmm(int n)
{
	long	mx;

	if (n < 0)
		n = -n;
	mx = 10;
	while (mx < n)
	{
		mx *= 10;
	}
	if (mx > n)
		mx /= 10;
	return (mx);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		l;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(str = (char*)(ft_strnew(ft_len(n + 1)))))
		return (NULL);
	if (n < 0)
	{
		n = -n;
		str[i++] = '-';
	}
	l = maxmm(n);
	while (l > 0)
	{
		if (n < 0)
			n = -n;
		str[i++] = n / l + '0';
		n %= l;
		l /= 10;
	}
	str[i] = '\0';
	return (str);
}
