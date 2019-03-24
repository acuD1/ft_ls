/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_perms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 14:23:32 by arsciand          #+#    #+#             */
/*   Updated: 2019/03/24 11:03:25 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	get_special_perms(char *perms, struct stat db_stat)
{
	perms[3] = db_stat.st_mode & S_IXUSR ? 'x' : '-';
	perms[3] = db_stat.st_mode & S_ISUID ? 'S' : perms[3];
	perms[3] = db_stat.st_mode & S_IXUSR &&
					db_stat.st_mode & S_ISUID ? 's' : perms[3];
	perms[6] = db_stat.st_mode & S_IXGRP ? 'x' : '-';
	perms[6] = db_stat.st_mode & S_ISGID ? 'S' : perms[6];
	perms[6] = db_stat.st_mode & S_IXGRP &&
					db_stat.st_mode & S_ISGID ? 's' : perms[6];
	perms[9] = db_stat.st_mode & S_IXOTH ? 'x' : '-';
	perms[9] = db_stat.st_mode & S_ISVTX ? 'T' : perms[9];
	perms[9] = db_stat.st_mode & S_IXOTH &&
					db_stat.st_mode & S_ISVTX ? 't' : perms[9];
}

char		*get_perms(struct stat db_stat)
{
	char	*perms;

	perms = ft_strnew(10);
	perms[0] = get_type(db_stat);
	perms[1] = (db_stat.st_mode & S_IRUSR) ? 'r' : '-';
	perms[2] = (db_stat.st_mode & S_IWUSR) ? 'w' : '-';
	perms[4] = (db_stat.st_mode & S_IRGRP) ? 'r' : '-';
	perms[5] = (db_stat.st_mode & S_IWGRP) ? 'w' : '-';
	perms[6] = (db_stat.st_mode & S_IXGRP) ? 'x' : '-';
	perms[7] = (db_stat.st_mode & S_IROTH) ? 'r' : '-';
	perms[8] = (db_stat.st_mode & S_IWOTH) ? 'w' : '-';
	get_special_perms(perms, db_stat);
	perms[10] = '\0';
	return (perms);
}
