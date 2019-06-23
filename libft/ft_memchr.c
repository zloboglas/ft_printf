/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgueren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 20:28:53 by wgueren           #+#    #+#             */
/*   Updated: 2018/11/30 12:17:53 by wgueren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buf, int ch, size_t count)
{
	size_t	i;
	char	c1;
	char	*c2;

	i = 0;
	c2 = (char*)buf;
	c1 = (char)ch;
	while (i < count)
	{
		if (c2[i] == c1)
			return (&c2[i]);
		i++;
	}
	return (NULL);
}
