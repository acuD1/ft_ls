/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_vars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 10:11:18 by arsciand          #+#    #+#             */
/*   Updated: 2019/03/16 15:58:45 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
void	process_dirs(t_list *dirs, t_opt *opt, size_t n_dirs)
{
	while (dirs != NULL)
	{
		print_dirs(DIRS_DB->var, opt, n_dirs);
		if (dirs->next && !opt->big_r)
			printf("\n");
		dirs = dirs->next;
	}
}
*/

void	process_dirs(t_list *dirs, t_opt *opt, size_t n_dirs)
{
	int		size;

	size = ft_lstlen(dirs);
	while (dirs != NULL)
	{
		printf("size = |%d|\n", size);
		if (opt->big_r)
		{
			dirs_recursive(DIRS_DB->var, opt, n_dirs, size);
		}
		else
		{
			dirs_normal(DIRS_DB->var, opt, n_dirs);
			if (dirs->next)
				printf("\n");
		}
		dirs = dirs->next;
		size--;
	}
}

void	ls_vars(t_list **vars, t_opt *opt, t_pad *pad)
{
	t_list	*dirs;
	t_list	*files;
	size_t	n_dirs;

	dirs = fill_vars_dirs(*vars);
	if (!(files = fill_vars_files(*vars)))
		opt->check_files = 1;
	n_dirs = ft_lstlen(dirs);
	if (files)
		print_files(files, opt, pad, 0);
	if (ft_lstlen(files) > 1 || ft_lstlen(dirs) > 1)
		opt->multiple = -1;
	if (files && dirs)
		printf("\n");
	process_dirs(dirs, opt, n_dirs);
	free_lst(files);
	free_lst(dirs);
}
