/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_filler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 10:13:09 by arsciand          #+#    #+#             */
/*   Updated: 2019/03/15 10:14:13 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list	*fill_vars_dirs(t_list *vars)
{
	t_list	*dirs;

	dirs = NULL;
	while (vars != NULL)
	{
		if (VARS_DB->type == 'd')
			ft_lstpushback(&dirs, ft_lstnew(VARS_DB, sizeof(t_ls)));
		vars = vars->next;
	}
	return (dirs);
}

t_list	*fill_vars_files(t_list *vars)
{
	t_list	*files;

	files = NULL;
	while (vars != NULL)
	{
		if (((t_ls*)vars->content)->type == '-')
			ft_lstpushback(&files, ft_lstnew(VARS_DB, sizeof(t_ls)));
		vars = vars->next;
	}
	return (files);
}
