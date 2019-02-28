/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 11:02:03 by arsciand          #+#    #+#             */
/*   Updated: 2019/02/28 14:22:35 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int ac, char **av)
{
	t_opt	opt;
	t_ls	*db;
	t_list	*args;

	ft_bzero(&opt, sizeof(t_ls));
	if (!(args = ls_parser(ac, av, &opt)))
		return (0);
	db = init_db(args);
	print_args(args);
	print_opt(opt);
	free_list(args);
	free(db);
	printf("***\nDEBUG | Finished\n");
	return (0);
}
