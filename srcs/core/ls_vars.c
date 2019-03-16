/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_vars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 10:11:18 by arsciand          #+#    #+#             */
/*   Updated: 2019/03/16 10:31:54 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	process_dirs(t_list *dirs, t_opt *opt, size_t n_dirs)
{
	while (dirs != NULL)
	{
		if (opt->big_r)
			dirs_recursive(DIRS_DB->var, opt, n_dirs);
		else
		{
			dirs_normal(DIRS_DB->var, opt, n_dirs);
			if (dirs->next)
				printf("\n");
		}
		dirs = dirs->next;
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
	if (files && dirs)
		printf("\n");
	process_dirs(dirs, opt, n_dirs);
	free_lst(files);
	free_lst(dirs);
}
