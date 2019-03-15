/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 11:46:03 by arsciand          #+#    #+#             */
/*   Updated: 2019/03/13 11:46:55 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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

t_list	*fill_vars_dirs(t_list *vars)
{
	t_list	*dirs;

	dirs = NULL;
	while (vars != NULL)
	{
		if (((t_ls*)vars->content)->type == 'd')
			ft_lstpushback(&dirs, ft_lstnew((t_ls*)vars->content, sizeof(t_ls)));
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
			ft_lstpushback(&files, ft_lstnew((t_ls*)vars->content, sizeof(t_ls)));
		vars = vars->next;
	}
	return (files);
}

void	print_test(t_list *tmp)
{
	printf("\nDEBUG PROCESS_VARS\n\n");
	while (tmp)
	{
		if (((t_ls*)tmp->content)->type == 'd')
			printf("dirs = %s\n", ((t_ls*)tmp->content)->var);
		if (((t_ls*)tmp->content)->type == '-')
			printf("files = %s\n", ((t_ls*)tmp->content)->var);
		tmp = tmp->next;
	}
}
