/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 10:47:42 by arsciand          #+#    #+#             */
/*   Updated: 2019/02/28 14:18:01 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	get_ls_option(t_opt *opt, char arg)
{
	if (arg == 'R')
		opt->big_r = 1;
	else if (arg == 'a')
		opt->a = 1;
	else if (arg == 'l')
		opt->l = 1;
	else if (arg == 'r')
		opt->r = 1;
	else if (arg == 't')
		opt->t = 1;
	else
		usage();
}

t_list		*get_ls_args(int ac, char **av, int i)
{
	t_list	*args;
	char	*tmp;

	args = NULL;
	if (!(av[i]))
		tmp = ft_strdup(".");
	else
	{
		while (i < ac)
		{
			tmp = ft_strdup(av[i]);
			ft_strcpy(tmp, av[i]);
			ft_lstpushback(&args,
					ft_lstnew(tmp, sizeof(char) * (ft_strlen(tmp) + 1)));
			free(tmp);
			i++;
		}
		return (args);
	}
	ft_lstpushback(&args, ft_lstnew(tmp, sizeof(char) * (ft_strlen(tmp) + 1)));
	return (args);
	free(tmp);
}

t_list		*ls_parser(int ac, char **av, t_opt *opt)
{
	int		i;
	int		j;

	i = 0;
	while (++i < ac)
	{
		j = 1;
		if (av[i][0] == '-' && av[i][1] == '-' && av[i][2])
		{
			usage();
			return (NULL);
		}
		else if (av[i][0] == '-' && av[i][1] == '-')
		{
			i++;
			break ;
		}
		else if (av[i][0] == '-' && av[i][1])
			while (av[i][j])
				get_ls_option(opt, av[i][j++]);
		else
			break ;
	}
	return (get_ls_args(ac, av, i));
}
