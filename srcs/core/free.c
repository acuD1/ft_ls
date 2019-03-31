/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 14:09:22 by arsciand          #+#    #+#             */
/*   Updated: 2019/03/31 11:01:55 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		free_vars(t_list *vars)
{
	t_list *node;

	while (vars != NULL)
	{
		free(VARS_DB->av);
		free(VARS_DB->var);
		acl_free(VARS_DB->acl);
		free(VARS_DB->chmod);
		free(VARS_DB->uid);
		free(VARS_DB->gid);
		free(VARS_DB->mtime);
		free(VARS_DB->size_mm);
		free(VARS_DB->link_path);
		if (VARS_DB->xattr->xattr)
			free(VARS_DB->xattr->xattr);
		free(VARS_DB->xattr);
		free(vars->content);
		node = vars;
		vars = vars->next;
		free(node);
	}
	return (0);
}

int		free_lst(t_list *lst)
{
	t_list *node;

	while (lst != NULL)
	{
		free(lst->content);
		node = lst;
		lst = lst->next;
		free(node);
	}
	return (0);
}
