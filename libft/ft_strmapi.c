/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgueren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 10:25:38 by wgueren           #+#    #+#             */
/*   Updated: 2018/11/29 16:49:35 by wgueren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*frs;

	i = 0;
	if (!s || !f)
		return (NULL);
	frs = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (frs == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		frs[i] = (*f)(i, (char)s[i]);
		i++;
	}
	frs[i] = '\0';
	return (frs);
}
