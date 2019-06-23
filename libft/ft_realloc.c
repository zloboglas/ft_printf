/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgueren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 16:47:05 by wgueren           #+#    #+#             */
/*   Updated: 2018/12/08 17:07:07 by wgueren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *str, size_t s)
{
	char	*fstr;

	if (str == NULL)
		return (malloc(s));
	if (s <= sizeof(str))
		return (str);
	fstr = malloc(s);
	ft_memcpy(str, fstr, sizeof(s));
	free(str);
	return (fstr);
}
