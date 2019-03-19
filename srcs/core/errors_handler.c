/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 12:51:14 by arsciand          #+#    #+#             */
/*   Updated: 2019/03/19 11:07:11 by arsciand         ###   ########.fr       */
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

void	lstat_failure(char *av, int *fail)
{
	ft_putstr_fd("ft_ls: ", 2);
	ft_putstr_fd(av, 2);
	ft_putstr_fd(": ", 2);
	perror(0);
	strerror(errno);
	*fail = 1;
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
