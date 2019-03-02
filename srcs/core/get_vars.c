/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 10:47:42 by arsciand          #+#    #+#             */
/*   Updated: 2019/03/02 15:26:50 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		fill_opt(t_opt *opt, char av)
{
	if (!(ft_strchr("-Ralrt", av)))
		return (0);
	if (av == 'R')
		opt->big_r = 1;
	else if (av == 'a')
		opt->a = 1;
	else if (av == 'l')
		opt->l = 1;
	else if (av == 'r')
		opt->r = 1;
	else if (av == 't')
		opt->t = 1;
	return (1);
}

static t_list	*fill_vars(int ac, char **av, int i, t_ls *db)
{
	t_list	*vars;

	vars = NULL;
	if (!(av[i]))
	{
		ft_lstpushback(&vars,
			ft_lstnew(fetch_db(db, "."), sizeof(t_ls)));
		return (vars);
	}
	else
	{
		while (i < ac)
			ft_lstpushback(&vars,
				ft_lstnew(fetch_db(db, av[i++]), sizeof(t_ls)));
		return (vars);
	}
}

t_list			*get_vars(int ac, char **av, t_opt *opt, t_ls *db)
{
	int		i;
	int		j;

	i = 0;
	while (++i < ac)
	{
		j = 0;
		if (av[i][0] == '-' && av[i][1] == '-' && av[i][2])
			return (usage());
		else if (av[i][0] == '-' && av[i][1] == '-')
		{
			i++;
			break ;
		}
		else if (av[i][0] == '-' && av[i][1])
		{
			while (av[i][j])
				if (!(fill_opt(opt, av[i][j++])))
					return (usage());
		}
		else
			break ;
	}
	return (fill_vars(ac, av, i, db));
}
