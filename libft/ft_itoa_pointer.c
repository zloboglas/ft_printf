/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 10:06:18 by dlabadie          #+#    #+#             */
/*   Updated: 2019/04/10 10:06:47 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_pointer(void *p)
{
	t_herobora	herobora;

	herobora.shift = 15;
	herobora.flag = 0;
	if (!(herobora.str = ft_strnew(1)))
		return (NULL);
	while (herobora.shift >= 0)
	{
		herobora.tmp = ((long)p >> (herobora.shift * 4)) & 15;
		if (!herobora.flag && herobora.shift != 1 && herobora.tmp
			== 0 && (herobora.shift)--)
			continue ;
		else
			herobora.flag = 1;
		if (!(herobora.buff2 = ft_itoa_base(herobora.tmp, 16)))
			return (NULL);
		herobora.to_free = herobora.str;
		if (!(herobora.str = ft_strjoin(herobora.str, herobora.buff2)))
			return (NULL);
		free(herobora.to_free);
		free(herobora.buff2);
		--(herobora.shift);
	}
	return (herobora.str);
}
