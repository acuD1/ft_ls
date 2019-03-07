/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_db.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 14:19:04 by arsciand          #+#    #+#             */
/*   Updated: 2019/03/07 17:18:20 by arsciand         ###   ########.fr       */
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
	db->uid_p = get_smmguid_pad(db->uid);
	db->gid = get_gid(db_stat);
	db->gid_p = get_smmguid_pad(db->gid);
	db->size = db_stat.st_size;
	db->size_mm = get_size_mm(db, db_stat, db->size);
	db->size_mm_p = get_smmguid_pad(db->size_mm);
	db->mtime = get_time(db_stat);
	db->time_digit = db_stat.st_mtime;
	return (db);
}
