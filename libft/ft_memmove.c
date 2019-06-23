/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgueren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 20:05:35 by wgueren           #+#    #+#             */
/*   Updated: 2018/12/06 20:13:57 by wgueren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*str1;
	char	*str2;
	size_t	i;

	if (src == dest || n == 0)
		return (dest);
	str1 = (char *)src;
	str2 = (char *)dest;
	if (str1 < str2 || str2 >= (str1 + n))
	{
		i = n;
		while (i-- > 0)
			str2[i] = str1[i];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			str2[i] = str1[i];
			i++;
		}
	}
	return (dest);
}
