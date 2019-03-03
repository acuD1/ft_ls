/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_db.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 14:19:04 by arsciand          #+#    #+#             */
/*   Updated: 2019/03/03 13:36:21 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls	*fetch_db(t_ls *db, char *av)
{
	struct stat db_stat;

	lstat(av, &db_stat);
	db->var = ft_strdup(av);
	db->type = get_type(db_stat);
	db->perms = get_perms(db_stat);
	db->links = db_stat.st_nlink;
	db->uid = get_uid(db_stat);
	db->gid = get_gid(db_stat);
	db->size = db_stat.st_size;
	db->mtime = get_time(db_stat);
	return (db);
}
