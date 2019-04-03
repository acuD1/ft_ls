/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 14:43:26 by arsciand          #+#    #+#             */
/*   Updated: 2019/04/03 10:22:14 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_link(char *var, t_ls *db)
{
	char string[MAX + 1];
	char *tmp;
	int i;
	struct stat db_stat;

	ft_bzero(string, MAX + 1);
	if (db->type == 'l')
	{
		i = readlink(var, string, MAX + 1);
	//	printf("i = %d\n", i);
		tmp = ft_strdup(" -> ");
		tmp = ft_strjoin_free(tmp, string, 1);
		ft_bzero(string, MAX + 1);
		db->no_link = 0;
		if (stat(var, &db_stat) != 0)
		{
			db->no_link = 1;
		}
		return (tmp);
	}
	else
		return (ft_strdup(""));

}
