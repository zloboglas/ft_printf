/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgueren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:12:05 by wgueren           #+#    #+#             */
/*   Updated: 2018/12/06 20:19:33 by wgueren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int s)
{
	while (*str != (unsigned char)s)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return ((char *)str);
}
