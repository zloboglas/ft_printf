/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgueren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 10:26:30 by wgueren           #+#    #+#             */
/*   Updated: 2019/04/17 11:23:31 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "write.h"

static void		*pf_memalloc(size_t size)
{
	char		*area;
	size_t		i;

	area = (char*)malloc(size + 1);
	if (area == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		area[i] = '0';
		i++;
	}
	area[size] = (char)0;
	return ((void*)area);
}

static int		pf_nonzerolen(char *str)
{
	int		i;

	i = 0;
	while (*str == '0')
		str++;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

static char		*fill_str(char *str, t_pattern *pattern)
{
	int		zernum;
	char	*zeroes;
	char	*tmp;
	char	*ret;

	zernum = pattern->precision - 2 - pf_nonzerolen(str);
	if (zernum > 0)
	{
		zeroes = (char *)pf_memalloc(zernum);
		tmp = str;
		str = ft_strjoin(zeroes, str);
		free(tmp);
		free(zeroes);
	}
	if (ft_strlen(str) == 2 && *str == '0')
	{
		ret = ft_strjoin("0x", str + 1);
		free(str);
		return (ret);
	}
	ret = ft_strjoin("0x", str);
	free(str);
	return (ret);
}

int				write_pointer(va_list ap, t_pattern *pattern)
{
	void		*ptr;
	char		*str;
	int			spaces;

	ptr = va_arg(ap, void *);
	if (pattern->point && pattern->precision == 0)
		pattern->precision = 1;
	str = fill_str(ft_itoa_pointer(ptr), pattern);
	spaces = pattern->width - ft_strlen(str);
	spaces = (spaces < 0) ? 0 : spaces;
	if (pattern->minus)
	{
		ft_putstr(str);
		ft_putchars(spaces, ' ');
	}
	else
	{
		ft_putchars(spaces, ' ');
		ft_putstr(str);
	}
	spaces += ft_strlen(str);
	free(str);
	return (spaces);
}
