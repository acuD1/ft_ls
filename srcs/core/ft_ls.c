/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 11:02:03 by arsciand          #+#    #+#             */
/*   Updated: 2019/03/02 16:57:40 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int ac, char **av)
{
	t_opt	opt;
	t_ls	*db;
	t_list	*vars;

	ft_bzero(&opt, sizeof(t_opt));
	if (!(db = (t_ls*)malloc(sizeof(t_ls))))
		return (0);
	if (!(vars = get_vars(ac, av, &opt, db)))
		return (0);
	print_vars_db(vars);
	print_opt(opt);
	free_vars(vars);
	free(db);
	printf("***\nDEBUG | Finished\n");
	return (0);
}
