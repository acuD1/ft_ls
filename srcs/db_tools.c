/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 14:19:04 by arsciand          #+#    #+#             */
/*   Updated: 2019/03/02 12:10:29 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


char	*get_perms(struct stat db_stat)
{
	char	*perms;

	perms = ft_strnew(9);
	perms[0] = get_type(db_stat);
	perms[1] = (db_stat.st_mode & S_IRUSR) ? 'r' : '-';
	perms[2] = (db_stat.st_mode & S_IWUSR) ? 'w' : '-';
	perms[3] = (db_stat.st_mode & S_IXUSR) ? 'x' : '-';
	perms[4] = (db_stat.st_mode & S_IRGRP) ? 'r' : '-';
	perms[5] = (db_stat.st_mode & S_IWGRP) ? 'w' : '-';
	perms[6] = (db_stat.st_mode & S_IXGRP) ? 'x' : '-';
	perms[7] = (db_stat.st_mode & S_IROTH) ? 'r' : '-';
	perms[8] = (db_stat.st_mode & S_IWOTH) ? 'w' : '-';
	perms[9] = (db_stat.st_mode & S_IXOTH) ? 'x' : '-';
	perms[10] = '\0';
	return (perms);
}

t_ls	*fetch_db(t_ls *db, char *av)
{
	struct	stat	db_stat;

	lstat(av, &db_stat);
	db->var = ft_strdup(av);
	db->type = get_type(db_stat);
	db->perms = get_perms(db_stat);
	return (db);
}
