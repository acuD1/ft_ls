/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 11:20:28 by arsciand          #+#    #+#             */
/*   Updated: 2019/04/02 09:29:35 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_opt(t_opt opt)
{
	printf("***\nPRINT | opt.R = |%d|\n\
PRINT | opt.a = |%d|\n\
PRINT | opt.l = |%d|\n\
PRINT | opt.r = |%d|\n\
PRINT | opt.s = |%d|\n\
PRINT | opt.S = |%d|\n\
PRINT | opt.t = |%d|\n",\
	opt.big_r, opt.a, opt.l, opt.r, opt.s, opt.size, opt.t);
}

void	print_vars_db(t_list *vars)
{
	int		i;

	i = 1;
	if (!(vars))
	{
		printf("--> No vars set, list empty! <--\n");
		return ;
	}
	printf("***\n");
	while (vars != NULL)
	{
		printf("* |%d| *\n", i);
		printf("PRINT | var	= |%s|\n", VARS_DB->var);
		printf("PRINT | type	= |%c|\n", VARS_DB->type);
		printf("PRINT | perms	= |%s|\n", VARS_DB->chmod);
		printf("PRINT | links	= |%d|\n", VARS_DB->links);
		printf("PRINT | uid	= |%s|\n", VARS_DB->uid);
		printf("PRINT | gid	= |%s|\n", VARS_DB->gid);
		printf("PRINT | size	= |%d|\n", VARS_DB->size);
		printf("PRINT | time	= |%s|\n", VARS_DB->mtime);
		vars = vars->next;
		i++;
	}
}

void	print_test(t_list *tmp)
{
	printf("\nDEBUG PROCESS_VARS\n\n");
	while (tmp)
	{
		if (((t_ls*)tmp->content)->type == 'd')
			printf("dirs = %s\n", ((t_ls*)tmp->content)->var);
		if (((t_ls*)tmp->content)->type == '-')
			printf("files = %s\n", ((t_ls*)tmp->content)->var);
		if (((t_ls*)tmp->content)->type == 'l')
			printf("links = %s\n", ((t_ls*)tmp->content)->var);
		tmp = tmp->next;
	}
}
