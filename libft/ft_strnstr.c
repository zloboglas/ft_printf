/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgueren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:29:43 by wgueren           #+#    #+#             */
/*   Updated: 2018/12/07 22:00:55 by wgueren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	if (*str2 == '\0')
		return ((char *)str1);
	i = ft_strlen(str2);
	while (*str1 && n >= i)
	{
		if (*str1 == *str2 && ft_memcmp(str1, str2, i) == 0)
			return ((char *)str1);
		str1++;
		n--;
	}
	return (NULL);
}
