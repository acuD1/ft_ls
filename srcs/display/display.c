/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 10:52:17 by arsciand          #+#    #+#             */
/*   Updated: 2019/03/02 17:33:59 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_opt(t_opt opt)
{
	printf("***\nPRINT | opt.R = |%d|\n\
PRINT | opt.a = |%d|\n\
PRINT | opt.l = |%d|\n\
PRINT | opt.r = |%d|\n\
PRINT | opt.t = |%d|\n",\
	opt.big_r, opt.a, opt.l, opt.r, opt.t);
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
		printf("PRINT | perms	= |%s|\n", VARS_DB->perms);
		printf("PRINT | links	= |%d|\n", VARS_DB->links);
		printf("PRINT | uid	= |%s|\n", VARS_DB->uid);
		printf("PRINT | gid	= |%s|\n", VARS_DB->gid);
		printf("PRINT | size	= |%zu|\n", VARS_DB->size);
		vars = vars->next;
		i++;
	}
}

t_list	*usage(void)
{
	ft_putendl("ls: illegal option -- -");
	ft_putendl("Usage : ./ft_ls [-Ralrt] [file ...]");
	return (NULL);
}
