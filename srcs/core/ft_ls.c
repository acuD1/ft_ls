/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 11:02:03 by arsciand          #+#    #+#             */
/*   Updated: 2019/03/15 09:21:54 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int ac, char **av)
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
		return (0);
//	print_vars_db(vars);									// DEBUG
//	print_opt(opt);											// DEBUG
	get_pad(vars, &pad);
//	printf("\nDefault INPUT w/o process_data\n\n");			// DEBUG
//	print_files(vars, &opt, &pad, n_dirs);				// DEBUG
	sort_vars(&vars, &opt);
//	printf("\n[%s] OUTPUT w/o process_data\n\n", av[1]);	// DEBUG
//	print_files(vars, &opt, &pad, n_dirs);				// DEBUG
	ls_vars(&vars, &opt, &pad);
	free_vars(vars);
	free(db);
	return (0);
}
