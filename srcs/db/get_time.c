/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 12:48:37 by arsciand          #+#    #+#             */
/*   Updated: 2019/03/03 12:48:48 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char 	*get_time(struct stat db_stat)
{
	long	mtime;

	mtime = db_stat.st_mtime;
	if (mtime > time(NULL) || time(NULL) - mtime >= 15780000)
		return (ft_strjoin(ft_strjoin(ft_strsub(ctime(&(mtime)), 4, 6),"  "),
				ft_strsub(ctime(&(mtime)), 20, 4)));
	else
		return (ft_strsub(ctime(&(mtime)), 4, 12));
}
