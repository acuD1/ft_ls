/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_vars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 10:11:18 by arsciand          #+#    #+#             */
/*   Updated: 2019/03/15 15:53:22 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	process_dirs(t_list *dirs, t_opt *opt, size_t n_dirs)
{
	(void)opt;
	while (dirs != NULL)
	{
		if (dirs->next == NULL)
			opt->check = 0;
		else
			opt->check = 1;
		if (opt->big_r)
		{
			dirs_recursive(DIRS_DB->var, opt, n_dirs);
		}
		else
			dirs_normal(DIRS_DB->var, opt, n_dirs);
		dirs = dirs->next;
	}
}

void	ls_vars(t_list **vars, t_opt *opt, t_pad *pad)
{
	t_list	*dirs;
	t_list	*files;
	size_t	n_dirs;

	dirs = fill_vars_dirs(*vars);
	files = fill_vars_files(*vars);
	if ((n_dirs = ft_lstlen(dirs)) > 0)
		opt->check = 1;
	if (files)
		print_files(files, opt, pad, 0);
	process_dirs(dirs, opt, n_dirs);
	free_lst(files);
	free_lst(dirs);
}
