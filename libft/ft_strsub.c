/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgueren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:12:39 by wgueren           #+#    #+#             */
/*   Updated: 2018/12/08 16:06:28 by wgueren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*frs;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < (size_t)start)
		return (NULL);
	if (!(frs = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len && s[i])
	{
		frs[i] = s[start];
		i++;
		start++;
	}
	frs[i] = '\0';
	return (frs);
}
