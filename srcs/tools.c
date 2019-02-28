/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 12:01:09 by arsciand          #+#    #+#             */
/*   Updated: 2019/02/28 14:06:27 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	free_list(t_list *args)
{
	t_list	*next;

	while (args != NULL)
	{
		free(args->content);
		next = args;
		args = args->next;
		free(next);
	}
}
