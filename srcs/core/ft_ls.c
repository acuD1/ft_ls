/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 11:02:03 by arsciand          #+#    #+#             */
/*   Updated: 2019/03/03 14:24:13 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_content(t_list *vars, t_opt *opt)
{
	while (vars != NULL)
	{
		if (opt->l)
			ft_mprintf(1, "%s  %d %s  %s %d %s %s\n",
					VARS_DB->perms, VARS_DB->links, VARS_DB->uid,
					VARS_DB->gid, VARS_DB->size, VARS_DB->mtime, VARS_DB->var);
		else
		{
			if (VARS_DB->type == '-')
				ft_mprintf(1, "%s", VARS_DB->var);
			if (vars->next != NULL)
				ft_mprintf(1, " ");
			if (vars->next == NULL)
				ft_mprintf(1, "\n");
		}
		vars = vars->next;
	}
}

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
//	print_vars_db(vars);
//	print_opt(opt);
/*
*/
//	printf("\nTESTING MPRINTF\n\n");
	print_content(vars, &opt);
// /	printf("\nTESTING MPRINTF\n");
/*
*/
	free_vars(vars);
	free(db);
// /	printf("***\nDEBUG | Finished\n");
	return (0);
}
