/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_id.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:22:00 by arsciand          #+#    #+#             */
/*   Updated: 2019/03/02 17:23:44 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_gid(struct stat db_stat)
{
	struct group	*grg;
	char			*gid;

	grg = getgrgid(db_stat.st_gid);
	if (grg)
		gid = ft_strdup(grg->gr_name);
	else
		gid = ft_itoa(db_stat.st_gid);
	return (gid);
}

char	*get_uid(struct stat db_stat)
{
	struct passwd *pwd;
	char *uid;

	pwd = getpwuid(db_stat.st_uid);
	if (pwd)
		uid = ft_strdup(pwd->pw_name);
	else
		uid = ft_itoa(db_stat.st_uid);
	return (uid);
}
