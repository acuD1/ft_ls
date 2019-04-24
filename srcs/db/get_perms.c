/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_perms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 14:23:32 by arsciand          #+#    #+#             */
/*   Updated: 2019/04/24 11:37:40 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	get_special_chmod(char *chmod, struct stat db_stat)
{
	chmod[3] = (db_stat.st_mode & S_IXUSR) ? 'x' : '-';
	chmod[3] = (db_stat.st_mode & S_ISUID) ? 'S' : chmod[3];
	chmod[3] = (db_stat.st_mode & S_IXUSR) &&
					(db_stat.st_mode & S_ISUID) ? 's' : chmod[3];
	chmod[6] = (db_stat.st_mode & S_IXGRP) ? 'x' : '-';
	chmod[6] = (db_stat.st_mode & S_ISGID) ? 'S' : chmod[6];
	chmod[6] = (db_stat.st_mode & S_IXGRP) &&
					(db_stat.st_mode & S_ISGID) ? 's' : chmod[6];
	chmod[9] = (db_stat.st_mode & S_IXOTH) ? 'x' : '-';
	chmod[9] = (db_stat.st_mode & S_ISVTX) ? 'T' : chmod[9];
	chmod[9] = (db_stat.st_mode & S_IXOTH) &&
					(db_stat.st_mode & S_ISVTX) ? 't' : chmod[9];
}

char		*get_chmod(t_ls *db, struct stat db_stat, char *av)
{
	char	*chmod;
	char	xattr[MAX];

	chmod = ft_strnew(11);
	chmod[0] = get_type(db_stat);
	chmod[1] = (db_stat.st_mode & S_IRUSR) ? 'r' : '-';
	chmod[2] = (db_stat.st_mode & S_IWUSR) ? 'w' : '-';
	chmod[4] = (db_stat.st_mode & S_IRGRP) ? 'r' : '-';
	chmod[5] = (db_stat.st_mode & S_IWGRP) ? 'w' : '-';
	chmod[6] = (db_stat.st_mode & S_IXGRP) ? 'x' : '-';
	chmod[7] = (db_stat.st_mode & S_IROTH) ? 'r' : '-';
	chmod[8] = (db_stat.st_mode & S_IWOTH) ? 'w' : '-';
	get_special_chmod(chmod, db_stat);
	chmod[10] = db->acl ? '+' : ' ';
	chmod[10] = listxattr(av, xattr, MAX, XATTR_NOFOLLOW) > 0 ? '@' : chmod[10];
	chmod[11] = '\0';
	return (chmod);
}
