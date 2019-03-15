/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_vars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 10:11:18 by arsciand          #+#    #+#             */
/*   Updated: 2019/03/15 10:12:16 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	process_dirs(t_list *dirs, t_opt *opt, size_t n_dirs)
{
	while (dirs != NULL)
	{
		dirs_normal(dirs, opt, n_dirs);
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
	n_dirs = ft_lstlen(dirs);
/*
**	DEBUG
*/
	print_test(dirs);
	print_test(files);
	printf("\nn_dirs = |%zu|\n", n_dirs);
	printf("\nFINAL OUTPUT\n-\n");
/*
**	-
*/
	print_files(files, opt, pad, n_dirs);
	process_dirs(dirs, opt, n_dirs);
	free_lst(files);
	free_lst(dirs);
}
