/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_acl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 15:32:52 by arsciand          #+#    #+#             */
/*   Updated: 2019/03/31 15:33:05 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_acl(t_ls *db)
{
	char *tmp;

	tmp = NULL;
	db->acl_tab = NULL;
	if (db->acl)
	{
		tmp = acl_to_text(db->acl, 0);
		db->acl_tab = ft_strsplit(tmp, ':');
		free(tmp);
	}
}
