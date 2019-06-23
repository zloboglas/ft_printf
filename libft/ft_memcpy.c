/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgueren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:21:29 by wgueren           #+#    #+#             */
/*   Updated: 2018/12/08 17:06:43 by wgueren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*s1;
	char	*s2;
	size_t	i;

	i = 0;
	if (n == 0 || dest == src)
		return (dest);
	s1 = ((char*)dest);
	s2 = ((char*)src);
	while (n--)
		*s1++ = *s2++;
	return (dest);
}
