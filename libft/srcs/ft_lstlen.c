/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:12:33 by arsciand          #+#    #+#             */
/*   Updated: 2018/11/20 16:21:58 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstlen(t_list *lst)
{
	t_list	*link;
	int		len;

	len = 0;
	link = lst;
	if (!lst)
		return (0);
	while (link->next)
	{
		link = link->next;
		len++;
	}
	return (len + 1);
}
