/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 12:51:14 by arsciand          #+#    #+#             */
/*   Updated: 2019/04/02 15:40:35 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list	*usage(char *av, int flag, int i)
{
	if (flag == 1)
	{
		ft_putendl("ft_ls: illegal option -- -");
		ft_putendl("usage: ./ft_ls [-Ralrt] [file ...]");
	}
	else
	{
		while (av[i])
		{
			if (!(ft_strchr("-Ralrt1@e", av[i])))
			{
				ft_mprintf(1, "ft_ls: illegal option -- %c\n", av[i]);
				ft_putendl("usage : ./ft_ls [-Ralrt] [file ...]");
			}
			i++;
		}
	}
	return (NULL);
}

void	print_failed(t_list **vars, t_opt *opt)
{
	struct stat	db_stat;
	t_list		*tmp;

	tmp = *vars;
	while (tmp)
	{
		if (lstat(TMP_DB->av, &db_stat))
		{
			ft_putstr_fd("ft_ls: ", 2);
			ft_putstr_fd(TMP_DB->av, 2);
			ft_putstr_fd(": ", 2);
			perror(0);
			strerror(errno);
			TMP_DB->type = '?';
			opt->not_found = 1;
		}
		tmp = tmp->next;
	}
	free_lst(tmp);
}

t_list	*failed_opendir(char *var, t_opt *opt)
{
	if (opt->l)
	{
		ft_mprintf(1, "%s:\n", var);
		ft_putstr_fd("ft_ls: ", 2);
		ft_putstr_fd(var + ft_strnrchr(var, '/'), 2);
		ft_putstr_fd(": ", 2);
		perror(0);
	}
	return (NULL);
}
