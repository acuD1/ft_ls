/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_db.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 14:19:04 by arsciand          #+#    #+#             */
/*   Updated: 2019/04/02 10:31:47 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	fetch_db_pad(t_ls *db)
{
	db->link_p = get_int_pad(db->links);
	db->uid_p = get_string_pad(db->uid);
	db->gid_p = get_string_pad(db->gid);
	db->size_mm_p = get_string_pad(db->size_mm);
	db->normal_p = get_string_pad(db->var);
	db->block_p = get_int_pad(db->block);
}

t_ls		*fetch_db(t_ls *db, char *av, char *name, t_opt *opt)
{
	lstat(av, &db->db_stat);
	db->av = ft_strdup(av);
	db->var = ft_strdup(name);
	db->type = get_type(db->db_stat);
	db->acl = acl_get_link_np(av, ACL_TYPE_EXTENDED);
	db->chmod = get_chmod(db, db->db_stat, av);
	db->links = db->db_stat.st_nlink;
	db->uid = get_uid(db->db_stat);
	db->gid = get_gid(db->db_stat);
	db->size = db->db_stat.st_size;
	db->size_mm = get_size_mm(db, db->db_stat, db->size);
	db->mtime = get_time(db->db_stat);
	db->time_digit = db->db_stat.st_mtime;
	db->block = db->db_stat.st_blocks;
	db->link_path = get_link(av, db);
	db->color = get_colors(db->type, db->chmod, opt);
	get_acl(db);
	get_xattr(db, av);
	fetch_db_pad(db);
	return (db);
}
