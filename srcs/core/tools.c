/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 10:16:58 by arsciand          #+#    #+#             */
/*   Updated: 2019/03/19 09:37:03 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_dir_path(char *dir_path, char *dir, char *name)
{
	ft_bzero(dir_path, MAX);
	ft_strcpy(dir_path, dir);
	ft_strcat(dir_path, "/");
	ft_strcat(dir_path, name);
	return (dir_path);
}

int		get_blocks(t_list *vars)
{
	int blocks;

	blocks = 0;
	while (vars)
	{
		blocks += VARS_DB->block;
		vars = vars->next;
	}
	return (blocks);
}

void	dirs_free(t_list *to_free, t_list *dir_content, t_opt *opt)
{
	if (opt->big_r)
		free_vars(to_free);
	free_vars(dir_content);
}
