/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 10:47:42 by arsciand          #+#    #+#             */
/*   Updated: 2019/02/26 09:53:20 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	get_ls_option(t_ls *ls, char arg)
{
	if (arg == 'R')
		ls->opt.big_r = 1;
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

static void			get_ls_args(int ac, char **av, int i, t_list **args)
{
	char	*tmp;

	if (!(av[i]))
		tmp = ft_strdup(".");
	else
	{
		while (i < ac)
		{
			tmp = ft_strdup(av[i]);
			ft_strcpy(tmp, av[i]);
			ft_lstpushback(args, ft_lstnew(tmp, ft_strlen(tmp)));
			free(tmp);
			i++;
		}
		return ;
	}
	ft_lstpushback(args, ft_lstnew(tmp, ft_strlen(tmp)));
	free(tmp);
}

t_list		*ls_parser(int ac, char **av, t_ls *ls, t_list *args)
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
				get_ls_option(ls, av[i][j++]);
		else
			break ;
	}
	get_ls_args(ac, av, i, &args);
	return (args);
}
