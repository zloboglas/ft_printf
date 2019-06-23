/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgueren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 21:01:59 by wgueren           #+#    #+#             */
/*   Updated: 2018/12/06 18:37:09 by wgueren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*tmp;
	long	len;
	long	i;

	len = 0;
	while (src[len] != '\0')
		len++;
	tmp = (char*)malloc(len + 1);
	if (!tmp)
		return (NULL);
	i = len;
	len = 0;
	while (len < i)
	{
		tmp[len] = src[len];
		len++;
	}
	tmp[len] = '\0';
	return (tmp);
}
