/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 12:01:09 by arsciand          #+#    #+#             */
/*   Updated: 2019/02/25 12:01:53 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_free_list(t_list *list)
{
	t_list	*next;

	while (list != NULL)
	{
		free(list->content);
		next = list;
		list = list->next;
		free(next);
	}
}
