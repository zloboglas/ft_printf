/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgueren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 18:13:10 by wgueren           #+#    #+#             */
/*   Updated: 2018/12/05 18:24:35 by wgueren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **link, void (*del)(void *, size_t))
{
	if (*link)
	{
		(del)((*link)->content, (*link)->content_size);
		free(*link);
		*link = NULL;
	}
}
