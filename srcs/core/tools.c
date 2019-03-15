/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 10:16:58 by arsciand          #+#    #+#             */
/*   Updated: 2019/03/15 10:17:14 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*get_dir_path(char *dir_path, char *dir, char *name)
{
	ft_bzero(dir_path, MAX);
	ft_strcpy(dir_path, dir);
	ft_strcat(dir_path, "/");
	ft_strcat(dir_path, name);
	return (dir_path);
}
