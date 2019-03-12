/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 11:20:28 by arsciand          #+#    #+#             */
/*   Updated: 2019/03/12 17:14:58 by arsciand         ###   ########.fr       */
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

/*
t_list *get_dirs_content(t_list *dirs, t_opt *opt)
{
	DIR		*content;
	t_list	*files;

	files = NULL;
	content = opendir(((t_ls*)dirs->content)->var);



}*/

void	print_dirs(t_list *dirs, t_opt *opt, t_pad *pad, size_t n_dirs)
{
	t_list *dirs_content;

	(void)dirs_content;
	(void)opt;
	(void)pad;
	if (n_dirs)
		ft_mprintf(1, "%s:\n", ((t_ls*)dirs->content)->var);
//	dirs_content = get_dirs_content(dirs, opt);
//	printf_files(dirs_content, opt, pad, n_dirs);
}

void	process_dirs(t_list *dirs, t_opt *opt, t_pad *pad, size_t n_dirs)
{
	while (dirs != NULL)
	{
		print_dirs(dirs, opt, pad, n_dirs);
		dirs = dirs->next;
	}
}

void	process_vars(t_list **vars, t_opt *opt, t_pad *pad)
{
	t_list	*dirs;
	t_list	*files;
	size_t	n_dirs;

	dirs = fill_vars_dirs(*vars);
	files = fill_vars_files(*vars);
	n_dirs = ft_lstlen(dirs);
/*
**	DEBUG
*/
	print_test(dirs);
	print_test(files);
	printf("\nn_dirs = |%zu|\n", n_dirs);
/*
**	-
*/
	printf("\nFINAL OUTPUT\n-\n");
	print_files(files, opt, pad, n_dirs);
	process_dirs(dirs, opt, pad, n_dirs);
	free_lst(dirs);
	free_lst(files);
}
