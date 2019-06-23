/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgueren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 18:48:16 by wgueren           #+#    #+#             */
/*   Updated: 2018/12/06 20:21:34 by wgueren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t		j;
	const char	*str1;
	char		*str2;

	j = 0;
	str1 = src;
	str2 = dest;
	while (j < n)
	{
		str2[j] = str1[j];
		if (str2[j] == (char)c)
			return (str2 + j + 1);
		j++;
	}
	return (NULL);
}
