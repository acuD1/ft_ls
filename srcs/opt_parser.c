/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 10:47:42 by arsciand          #+#    #+#             */
/*   Updated: 2019/02/25 13:58:05 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	get_ls_option(t_ls *ls, char arg)
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

int		get_ls_args(int ac, char **av, int i, t_list **args)
{
	int		check;
	char	*tmp;

	check = i;
	while (i < ac)
	{
		if (!(av[i]))
			tmp = ft_strdup(".");
		else
		{
			tmp = ft_strnew(ft_strlen(av[i]));
			ft_strcpy(tmp,av[i]);
		}
		ft_lstpushback(args, ft_lstnew(tmp, ft_strlen(tmp)));
		free(tmp);
		i++;
	}
	return (1);
}

t_list		*ls_parser(int ac, char **av, t_ls *ls)
{
	int		i;
	int		j;
	t_list	*args;

	i = 0;
	args = NULL;
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
				get_ls_option(ls, av[i][j++]);
		}
		else
			break;
	}
	get_ls_args(ac, av, i, &args);
	return (args);
}
