/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 11:52:57 by arsciand          #+#    #+#             */
/*   Updated: 2019/02/24 14:50:44 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	usage(void)
{
	ft_putendl("ls: illegal option -- -");
	ft_putendl("Usage : ./ft_ls [-Ralrt] [file ...]");
}

int		set_option(t_ls *option, char arg)
{
	if (arg == 'R')
		option->R = 1;
	else if (arg == 'a')
		option->a = 1;
	else if (arg == 'l')
		option->l = 1;
	else if (arg == 'r')
		option->r = 1;
	else if (arg == 't')
		option->t = 1;
	else
	{
		usage();
		return (0);
	}
	return (1);
}

void	get_option(int ac, char **av, t_ls *option)
{
	int		i;
	int		j;

	i = 0;
	while (++i < ac)
	{
		if (av[i][0] == '-' && av[i][1] == '-' && av[i][2])
		{
			usage();
			return ;
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
				set_option(option, av[i][j++]);
		}
	}
}
