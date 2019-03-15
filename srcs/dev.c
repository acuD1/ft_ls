/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 11:20:28 by arsciand          #+#    #+#             */
/*   Updated: 2019/03/15 10:16:49 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list	*fetch_dir_content(t_list *dirs, DIR *content, t_opt *opt)
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
		dir_path = get_dir_path(dir_path, DIRS_DB->var, dir->d_name);
		ft_lstpushback(&dir_content,
			ft_lstnew(fetch_db(db, dir_path, dir->d_name), sizeof(t_ls)));
		continue;
	}
	free(dir_path);
	free(db);
	return (dir_content);

}

t_list *get_dir_content(t_list *dirs, t_opt *opt)
{
	DIR		*content;
	t_list	*dir_content;
	(void)opt;

	content = opendir(DIRS_DB->var);
	dir_content = fetch_dir_content(dirs, content, opt);
	closedir(content);
	return (dir_content);
}

void	dirs_normal(t_list *dirs, t_opt *opt, size_t n_dirs)
{
	t_list *dir_content;
	t_pad pad;

	ft_bzero(&pad, sizeof(t_pad));
	if (n_dirs)
		ft_mprintf(1, "%s:\n", DIRS_DB->var);
	dir_content = get_dir_content(dirs, opt);
	sort_vars(&dir_content, opt);
	get_pad(dir_content, &pad);
	print_files(dir_content, opt, &pad, n_dirs);
	free_vars(dir_content);
}
