/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 11:02:03 by arsciand          #+#    #+#             */
/*   Updated: 2019/03/02 13:06:44 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		free_vars(t_list *vars)
{
	t_list *node;

	while (vars != NULL)
	{
		free(VARS_DB->var);
		free(VARS_DB->perms);
		free(vars->content);
		node = vars;
		vars = vars->next;
		free(node);
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_opt	opt;
	t_ls	*db;
	t_list	*vars;

	ft_bzero(&opt, sizeof(t_ls));
	if (!(db = (t_ls*)malloc(sizeof(t_ls))))
		return (0);
	if (!(vars = vars_parser(ac, av, &opt, db)))
		return (0);
	print_vars_db(vars);
	print_opt(opt);
	free_vars(vars);
	free(db);
	printf("***\nDEBUG | Finished\n");
	return (0);
}
