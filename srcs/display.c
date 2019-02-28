/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 10:52:17 by arsciand          #+#    #+#             */
/*   Updated: 2019/02/28 17:35:53 by arsciand         ###   ########.fr       */
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
		printf("PRINT | var[%d] = |%s|\n", i, VARS_DB->var));
		printf("PRINT | type[%d] = |%c|\n", i, VARS_DB->type));
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
