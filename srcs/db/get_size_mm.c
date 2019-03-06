/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size_mm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 17:51:22 by arsciand          #+#    #+#             */
/*   Updated: 2019/03/06 18:08:49 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_size_mm(t_ls *db, struct stat db_stat, size_t size)
{
	char *major;
	char *minor;
	char *tmp;

	if (db->type == 'c' || db->type == 'b')
	{
		major = ft_itoa(major(db_stat.st_rdev));
		minor = get_minor_pad(ft_itoa(minor(db_stat.st_rdev)));
		tmp = ft_strdup(",");
		return (ft_strjoin_free(ft_strjoin_free(major, tmp, 3), minor, 1));
	}
	else
		return (ft_itoa(size));
}
