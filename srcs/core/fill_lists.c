/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 10:13:09 by arsciand          #+#    #+#             */
/*   Updated: 2019/04/03 10:39:31 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list	*fill_vars_dirs(t_list *vars, t_opt *opt)
{
	t_list	*dirs;

	dirs = NULL;
	while (vars != NULL)
	{
		if (opt->l)
		{
			if (((VARS_DB->type == 'l' && !opt->l)
				|| VARS_DB->type == 'd') && VARS_DB->type != '?')
				ft_lstpushback(&dirs, ft_lstnew(VARS_DB, sizeof(t_ls)));
		}
		else
		{
			if ((VARS_DB->type == 'd' && VARS_DB->type != '?' && VARS_DB->type != 'l')
				|| (VARS_DB->type == 'l' && VARS_DB->no_link == 0))
				ft_lstpushback(&dirs, ft_lstnew(VARS_DB, sizeof(t_ls)));
		}
		vars = vars->next;
	}
	return (dirs);
}

t_list	*fill_vars_files(t_list *vars, t_opt *opt)
{
	t_list	*files;

	files = NULL;
	while (vars != NULL)
	{
		if (opt->l)
		{
			if ((VARS_DB->type != 'l' && VARS_DB->type != 'd'
				&& VARS_DB->type != '?') || (VARS_DB->type == 'l' && opt->l))
				ft_lstpushback(&files, ft_lstnew(VARS_DB, sizeof(t_ls)));
		}
		else
		{
			if ((VARS_DB->type != 'd' && VARS_DB->type != '?' && VARS_DB->type != 'l')
				|| (VARS_DB->type == 'l' &&VARS_DB->no_link))
				ft_lstpushback(&files, ft_lstnew(VARS_DB, sizeof(t_ls)));
		}
		vars = vars->next;
	}
	return (files);
}

