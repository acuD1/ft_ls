/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 10:52:17 by arsciand          #+#    #+#             */
/*   Updated: 2019/03/09 11:51:38 by arsciand         ###   ########.fr       */
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
		printf("PRINT | size	= |%d|\n", VARS_DB->size);
		printf("PRINT | time	= |%s|\n", VARS_DB->mtime);
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

void	print_content(t_list *vars, t_opt *opt, t_pad *pad)
{
	while (vars != NULL)
	{
		if (opt->l)
			printf("%s  %d %-*.*s  %-*.*s  %*.*s %s %s\n",
					VARS_DB->perms, VARS_DB->links,
					pad->m_uid_p, VARS_DB->uid_p, VARS_DB->uid,
					pad->m_gid_p, VARS_DB->gid_p, VARS_DB->gid,
					pad->m_size_mm_p, VARS_DB->size_mm_p, VARS_DB->size_mm,
					VARS_DB->mtime, VARS_DB->var);
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
