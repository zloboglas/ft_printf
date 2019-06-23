/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgueren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 20:41:32 by wgueren           #+#    #+#             */
/*   Updated: 2018/11/28 22:21:45 by wgueren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *strb, const char *stra)
{
	int		i;
	int		j;
	int		l;

	i = 0;
	j = 0;
	l = 0;
	while (stra[l] != '\0')
		l++;
	if (*stra == '\0')
		return ((char *)strb);
	while (strb[i] != '\0')
	{
		while (stra[j] == strb[i + j])
		{
			if (j == l - 1)
				return ((char *)strb + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
