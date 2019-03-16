/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 11:20:28 by arsciand          #+#    #+#             */
/*   Updated: 2019/03/16 10:48:28 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list	*fetch_dir_content(char *var, DIR *content, t_opt *opt)
{
	t_list			*dir_content;
	t_ls			*db;
	struct dirent	*dir;
	char			*dir_path;

	(void)opt;
	if (!(db = (t_ls*)malloc(sizeof(t_ls))))
		return (0);
	dir_path = ft_strnew(MAX);
	while ((dir = readdir(content)))
	{
		dir_path = get_dir_path(dir_path, var, dir->d_name);
		if (!(opt->a) && dir->d_name[0] == '.')
			continue;
		ft_lstpushback(&dir_content,
			ft_lstnew(fetch_db(db, dir_path, dir->d_name), sizeof(t_ls)));
		continue;
	}
	free(dir_path);
	free(db);
	return (dir_content);
}

t_list	*get_dir_content(char *var, t_opt *opt)
{
	DIR		*content;
	t_list	*dir_content;

	content = opendir(var);
	dir_content = fetch_dir_content(var, content, opt);
	closedir(content);
	return (dir_content);
}

void	print_dirs(char *var, t_opt *opt, size_t n_dirs)
{
	t_list	*dir_content;
	t_list	*to_free;
	char 	path[MAX];
	t_pad	pad;

	ft_bzero(&pad, sizeof(t_pad));
	dir_content = get_dir_content(var, opt);
	if (dir_content->next && opt->big_r)
		printf("\n");
	if (!(opt->check_files) || n_dirs > 1)
		ft_mprintf(1, "%s:\n", var);
	opt->check_files = 0;
	sort_vars(&dir_content, opt);
	get_pad(dir_content, &pad);
	print_files(dir_content, opt, &pad, n_dirs);
	if (opt->big_r)
	{
		to_free = dir_content;
		while (dir_content)
		{
			if (DIR_C_DB->type == 'd')
				print_dirs(get_dir_path(path, var, DIR_C_DB->var), opt, n_dirs);
			dir_content = dir_content->next;
		}
		free_vars(to_free);
	}
	else
		free_vars(dir_content);
}
