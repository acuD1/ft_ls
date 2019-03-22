/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 12:51:14 by arsciand          #+#    #+#             */
/*   Updated: 2019/03/22 14:40:30 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list	*usage(char *av, int flag)
{
	char	option;

	if (flag == 1)
	{
		ft_putendl("ft_ls: illegal option -- -");
		ft_putendl("usage : ./ft_ls [-Ralrt] [file ...]");
	}
	else
	{
		option = av[1];
		ft_mprintf(1, "ft_ls: illegal option -- %c\n", option);
		ft_putendl("usage : ./ft_ls [-Ralrt] [file ...]");
	}
	return (NULL);
}

void	print_failed(t_list **vars)
{
	struct stat	db_stat;
	t_list		*tmp;

	tmp = *vars;
	while (tmp)
	{
		if (TMP_DB->type == '?')
		{
			lstat(TMP_DB->var, &db_stat);
			ft_putstr_fd("ft_ls: ", 2);
			ft_putstr_fd(TMP_DB->var, 2);
			ft_putstr_fd(": ", 2);
			perror(0);
			strerror(errno);
		}
		tmp = tmp->next;
	}
	free_lst(tmp);
}

t_list	*failed_opendir(char *var)
{
	ft_mprintf(1, "%s:\n", var);
	ft_putstr_fd("ft_ls: ", 2);
	ft_putstr_fd(var + ft_strnrchr(var, '/'), 2);
	ft_putstr_fd(": ", 2);
	perror(0);
	return (NULL);
}
