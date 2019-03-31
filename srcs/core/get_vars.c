/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 10:47:42 by arsciand          #+#    #+#             */
/*   Updated: 2019/03/31 13:51:55 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		fill_opt(t_opt *opt, char av)
{
	if (!(ft_strchr("-Ralrt1@e", av)))
		return (0);
	if (av == 'R')
		opt->big_r = 1;
	else if (av == 'a')
		opt->a = 1;
	else if (av == 'l')
	{
		opt->l = 1;
		opt->one = 0;
	}
	else if (av == 'r')
		opt->r = 1;
	else if (av == 't')
		opt->t = 1;
	else if (av == '1')
	{
		opt->one = 1;
		opt->l = 0;
	}
	if (av == '@')
		opt->xattr = 1;
	if (av == 'e')
		opt->e = 1;
	return (1);
}

static t_list	*fill_vars(char **av, int i, t_ls *db, t_opt *opt)
{
	t_list		*vars;

	vars = NULL;
	if (!(av[i]))
	{
		ft_lstpushback(&vars,
			ft_lstnew(fetch_db(db, ".", ".", opt), sizeof(t_ls)));
		return (vars);
	}
	while (av[i])
	{
		ft_lstpushback(&vars,
			ft_lstnew(fetch_db(db, av[i], av[i], opt), sizeof(t_ls)));
		av++;
	}
	return (vars);
}

void			check_first_arg(char **av, int i, t_opt *opt)
{
	struct stat db_stat;

	if (!(av[i]))
		opt->no_args = 1;
	if (lstat(av[i], &db_stat))
		opt->lstat_first_arg = 1;
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
			return (usage(av[i], 1, i));
		else if (av[i][0] == '-' && av[i][1] == '-')
		{
			i++;
			break ;
		}
		else if (av[i][0] == '-' && av[i][1])
		{
			while (av[i][j])
				if (!(fill_opt(opt, av[i][j++])))
					return (usage(av[i], 0, i));
		}
		else
			break ;
	}
	check_first_arg(av, i, opt);
	return (fill_vars(av, i, db, opt));
}
