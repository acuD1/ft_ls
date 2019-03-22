/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_db.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 14:19:04 by arsciand          #+#    #+#             */
/*   Updated: 2019/03/22 10:27:37 by arsciand         ###   ########.fr       */
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

t_ls	*fetch_db(t_ls *db, char *av, char *name)
{
	struct stat db_stat;

	lstat(av, &db_stat);
	db->var = ft_strdup(name);
	db->type = get_type(db_stat);
	db->perms = get_perms(db_stat);
	db->links = db_stat.st_nlink;
	db->link_p = get_int_pad(db->links);
	db->uid = get_uid(db_stat);
	db->uid_p = get_smmguid_pad(db->uid);
	db->gid = get_gid(db_stat);
	db->gid_p = get_smmguid_pad(db->gid);
	db->size = db_stat.st_size;
	db->size_mm = get_size_mm(db, db_stat, db->size);
	db->size_mm_p = get_smmguid_pad(db->size_mm);
	db->mtime = get_time(db_stat);
	db->time_digit = db_stat.st_mtime;
	db->block = db_stat.st_blocks;
	db->link_path = get_link(av, db);
	return (db);
}
