/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 14:19:04 by arsciand          #+#    #+#             */
/*   Updated: 2019/02/28 17:34:55 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls	*fetch_db(t_ls *db, char *av)
{
	struct stat	d_stat;

	lstat(av, &d_stat);
	db->var = ft_strdup(av);
	db->type = get_type(d_stat);
	printf("DEBUG | db->var = |%s|\n", db->var);
	printf("DEBUG | db->type = |%c|\n", db->type);
	return (db);
}
