/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgueren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 11:15:14 by wgueren           #+#    #+#             */
/*   Updated: 2018/12/07 18:02:30 by wgueren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *str1, const char *str2)
{
	while ((unsigned char)*str1 && (unsigned char)*str1 == (unsigned char)*str2)
	{
		++str1;
		++str2;
	}
	return ((unsigned char)*str1 - (unsigned char)*str2);
}
