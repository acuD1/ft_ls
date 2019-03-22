/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 14:43:26 by arsciand          #+#    #+#             */
/*   Updated: 2019/03/22 14:43:36 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_link(char *var, t_ls *db)
{
	char string[MAX + 1];
	char *tmp;

	ft_bzero(string, MAX + 1);
	if (db->type == 'l')
	{
		readlink(var, string, MAX + 1);
		tmp = ft_strdup(" -> ");
		tmp = ft_strjoin_free(tmp, string, 1);
		ft_bzero(string, MAX + 1);
		return (tmp);
	}
	else
		return (ft_strdup(""));
}
