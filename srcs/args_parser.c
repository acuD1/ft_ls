/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 11:52:57 by arsciand          #+#    #+#             */
/*   Updated: 2019/02/25 10:34:02 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	usage(void)
{
	ft_putendl("ls: illegal option -- -");
	ft_putendl("Usage : ./ft_ls [-Ralrt] [file ...]");
}

static void	set_option(t_ls *ls, char arg)
{
	if (arg == 'R')
		ls->opt.R = 1;
	else if (arg == 'a')
		ls->opt.a = 1;
	else if (arg == 'l')
		ls->opt.l = 1;
	else if (arg == 'r')
		ls->opt.r = 1;
	else if (arg == 't')
		ls->opt.t = 1;
	else
		usage();
}

int		get_option(int ac, char **av, t_ls *ls)
{
	int		i;
	int		j;
	i = 0;
	while (++i < ac)
	{
		if (av[i][0] == '-' && av[i][1] == '-' && av[i][2])
		{
			usage();
			return (0);
		}
		else if (av[i][0] == '-' && av[i][1] == '-')
		{
			i++;
			break ;
		}
		else if (av[i][0] == '-')
		{
			j = 1;
			while (av[i][j])
				set_option(ls, av[i][j++]);
		}
	}
	return (1);
}
