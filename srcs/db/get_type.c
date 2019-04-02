/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 14:22:46 by arsciand          #+#    #+#             */
/*   Updated: 2019/04/02 10:31:28 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	get_type(struct stat db_stat)
{
	if (S_ISREG(db_stat.st_mode))
		return ('-');
	else if (S_ISDIR(db_stat.st_mode))
		return ('d');
	else if (S_ISCHR(db_stat.st_mode))
		return ('c');
	else if (S_ISBLK(db_stat.st_mode))
		return ('b');
	else if (S_ISFIFO(db_stat.st_mode))
		return ('p');
	else if (S_ISLNK(db_stat.st_mode))
		return ('l');
	else if (S_ISSOCK(db_stat.st_mode))
		return ('s');
	else
		return ('?');
}
