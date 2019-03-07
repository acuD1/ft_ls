/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 11:02:03 by arsciand          #+#    #+#             */
/*   Updated: 2019/03/07 13:05:01 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int ac, char **av)
{
	t_opt	opt;
	t_ls	*db;
	t_list	*vars;
	t_list	*vars_sorted;
	t_pad	pad;

	ft_bzero(&opt, sizeof(t_opt));
	ft_bzero(&pad, sizeof(t_pad));
	if (!(db = (t_ls*)malloc(sizeof(t_ls))))
		return (0);
	if (!(vars = get_vars(ac, av, &opt, db)))
		return (0);
	//print_vars_db(vars);
	//print_opt(opt);
	get_pad(vars, &pad);
	vars_sorted = sort_vars(vars, &opt);
	while (vars_sorted != NULL)
	{
		printf("TEST main = |%s|\n", VARS_SORT_DB->var);
		vars_sorted = vars_sorted->next;

	}
	print_content(vars, &opt, &pad);
	free_vars(vars);
	free(db);
	return (0);
}
