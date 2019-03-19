/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_perms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 14:23:32 by arsciand          #+#    #+#             */
/*   Updated: 2019/03/19 11:37:08 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_perms(struct stat db_stat)
{
	char	*perms;

	perms = ft_strnew(10);
	perms[0] = get_type(db_stat);
	perms[1] = (db_stat.st_mode & S_IRUSR) ? 'r' : '-';
	perms[2] = (db_stat.st_mode & S_IWUSR) ? 'w' : '-';
	perms[3] = (db_stat.st_mode & S_IXUSR) ? 'x' : '-';
	perms[4] = (db_stat.st_mode & S_IRGRP) ? 'r' : '-';
	perms[5] = (db_stat.st_mode & S_IWGRP) ? 'w' : '-';
	perms[6] = (db_stat.st_mode & S_IXGRP) ? 'x' : '-';
	perms[7] = (db_stat.st_mode & S_IROTH) ? 'r' : '-';
	perms[8] = (db_stat.st_mode & S_IWOTH) ? 'w' : '-';
	if ((db_stat.st_mode & S_ISVTX))
		perms[9] = 'T';
	else if ((db_stat.st_mode & S_IXOTH))
		perms[9] = 'x';
	else
		perms[9] = '-';
	perms[10] = '\0';
	return (perms);
}
