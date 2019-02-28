/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 14:19:04 by arsciand          #+#    #+#             */
/*   Updated: 2019/02/28 18:10:11 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_permission(struct stat db_stat)
{
	(void)db_stat;
	char *tmp;

	tmp = ft_strnew(10);
	printf("TEST = |%s|\n", tmp);
}

t_ls	*fetch_db(t_ls *db, char *av)
{
	struct stat	db_stat;

	lstat(av, &db_stat);
	db->var = ft_strdup(av);
	db->type = get_type(db_stat);
	printf("Mode : %lo (octal)\n", (unsigned long) db_stat.st_mode);
	get_permission(db_stat);
	return (db);
}
