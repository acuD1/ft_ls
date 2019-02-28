/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 12:01:09 by arsciand          #+#    #+#             */
/*   Updated: 2019/02/28 17:40:32 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	free_vars(t_list *vars)
{
	t_list	*node;

	while (vars != NULL)
	{
		free(VARS_DB->var));
		free(vars->content);
		node = vars;
		vars = vars->next;
		free(node);
	}
}
