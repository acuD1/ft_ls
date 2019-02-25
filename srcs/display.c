/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 10:52:17 by arsciand          #+#    #+#             */
/*   Updated: 2019/02/25 13:49:31 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_struct(t_ls ls)
{
	printf("opt.R = |%d|\n\
opt.a = |%d|\n\
opt.l = |%d|\n\
opt.r = |%d|\n\
opt.t = |%d|\n",\
	ls.opt.R, ls.opt.a, ls.opt.l, ls.opt.r, ls.opt.t);
}

void	print_lst(t_list *args)
{
	int		i;
	t_list	*node;

	i = 1;
	node = args;
	if (!args)
	{
		ft_mprintf(1, "No args set, list empty!\n");
		return ;
	}
	while (node != NULL)
	{
		ft_mprintf(1, "arg[%d] = |%s|\n", i, node->content);
		node = node->next;
		i++;
	}
}

void	usage(void)
{
	ft_putendl("ls: illegal option -- -");
	ft_putendl("Usage : ./ft_ls [-Ralrt] [file ...]");
}
