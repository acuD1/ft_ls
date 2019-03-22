/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 11:02:03 by arsciand          #+#    #+#             */
/*   Updated: 2019/03/22 14:31:21 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	get_output(t_list **vars, t_opt *opt, t_pad *pad)
{
	t_list	*dirs;
	t_list	*files;
	size_t	n;

	dirs = fill_vars_dirs(*vars);
	if (!(files = fill_vars_files(*vars)))
		opt->check_files = 1;
	n = ft_lstlen(dirs);
	if (files)
	{
		ft_bzero(pad, sizeof(t_pad));
		get_pad(files, pad);
		print_files(files, opt, pad, 0);
	}
	if (files && dirs)
		printf("\n");
	process_dirs(dirs, opt, n);
	free_lst(files);
	free_lst(dirs);
}

int			main(int ac, char **av)
{
	t_opt	opt;
	t_ls	*db;
	t_list	*vars;
	t_pad	pad;

	ft_bzero(&opt, sizeof(t_opt));
	ft_bzero(&pad, sizeof(t_pad));
	if (!(db = (t_ls*)malloc(sizeof(t_ls))))
		return (0);
	if (!(vars = get_vars(ac, av, &opt, db)))
	{
		free(db);
		return (0);
	}
	get_pad(vars, &pad);
	sort_vars(&vars, &opt);
	print_failed(&vars);
	get_output(&vars, &opt, &pad);
	free_vars(vars);
	free(db);
	return (0);
}
