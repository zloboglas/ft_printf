/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgueren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 18:34:05 by wgueren           #+#    #+#             */
/*   Updated: 2018/12/07 19:44:42 by wgueren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	if (!s[0])
		return (ft_strnew(0));
	i = 0;
	j = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while ((s[j] == ' ' || s[j] == '\n' ||
	s[j] == '\t' || s[j] == '\0') && j > i)
		j--;
	j++;
	if (!(str = (char*)ft_strnew(j - i)))
		return (NULL);
	ft_strncpy(str, s + i, j - i);
	return (str);
}
