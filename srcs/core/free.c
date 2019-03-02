/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 14:09:22 by arsciand          #+#    #+#             */
/*   Updated: 2019/03/02 14:21:00 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		free_vars(t_list *vars)
{
	t_list *node;

	while (vars != NULL)
	{
		free(VARS_DB->var);
		free(VARS_DB->perms);
		free(vars->content);
		node = vars;
		vars = vars->next;
		free(node);
	}
	return (0);
}
