/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgueren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 15:12:49 by wgueren           #+#    #+#             */
/*   Updated: 2018/12/07 15:38:59 by wgueren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*n;

	n = (char *)s + ft_strlen(s);
	if ((char)c == '\0')
		return (n);
	while (n >= s)
	{
		if (*n == (char)c)
			return (n);
		n--;
	}
	return (NULL);
}
