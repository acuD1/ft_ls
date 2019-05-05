/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 14:43:26 by arsciand          #+#    #+#             */
/*   Updated: 2019/05/05 16:02:37 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_link(char *var, t_ls *db)
{
	struct stat	db_stat;
	char		string[MAX + 1];
	char		*tmp;

	ft_bzero(string, MAX + 1);
	if (db->type == 'l')
	{
		readlink(var, string, MAX + 1);
		tmp = ft_strdup(" -> ");
		tmp = ft_strjoinf(tmp, string, 1);
		ft_bzero(string, MAX + 1);
		db->no_link = 0;
		if (stat(var, &db_stat))
			db->no_link = 1;
		return (tmp);
	}
	else
		return (ft_strdup(""));
}
