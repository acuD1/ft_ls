/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 11:20:28 by arsciand          #+#    #+#             */
/*   Updated: 2019/03/15 09:13:51 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*build_new_path(char *old_path, char *directory, char *name)
{
	int	i;

	if (directory == NULL || ft_strequ(directory, ""))
	{
		i = ft_strlen(old_path);
		while (old_path[i] != '/')
			old_path[i--] = '\0';
		old_path = ft_strcat(old_path, name);
	}
	else
	{
		ft_bzero(old_path, MAX);
		(void)ft_strcpy(old_path, directory);
		(void)ft_strcat(old_path, "/");
		(void)ft_strcat(old_path, name);
	}
	return (old_path);
}

t_list *fill_dirs_content(t_list *dirs, DIR *content, t_opt *opt)
{
	t_list *dirs_content;
	char	*new_path;
	struct dirent *dir;
	t_ls	*db;

	(void)opt;
	if (!(db = (t_ls*)malloc(sizeof(t_ls))))
		return (0);
	new_path = ft_strnew(MAX);
	while ((dir = readdir(content)))
	{
		//printf("dirent : |%s|\n", dir->d_name);
		new_path = build_new_path(new_path, ((t_ls*)dirs->content)->var, dir->d_name);
		//printf("new path : |%s|\n", new_path);
		ft_lstpushback(&dirs_content, ft_lstnew(fetch_db(db, new_path, dir->d_name), sizeof(t_ls)));
		continue;
	}
	free(new_path);
	free(db);
	return (dirs_content);

}

t_list *get_dirs_content(t_list *dirs, t_opt *opt)
{
	DIR		*content;
	t_list	*dirs_content;

	content = opendir(((t_ls*)dirs->content)->var);
	dirs_content = fill_dirs_content(dirs, content, opt);
	return (dirs_content);
}

void	dirs_normal(t_list *dirs, t_opt *opt, t_pad *pad, size_t n_dirs)
{
	(void)pad;
	t_list *dirs_content;

	(void)opt;
	if (n_dirs)
		ft_mprintf(1, "%s:\n", ((t_ls*)dirs->content)->var);
	dirs_content = get_dirs_content(dirs, opt);
//	sort_vars(&dirs_content, opt);
//	get_pad(dirs_content, pad);
//	print_files(dirs_content, opt, pad, n_dirs);
	free_vars(dirs_content);
}

void	process_dirs(t_list *dirs, t_opt *opt, size_t n_dirs)
{
	(void)opt;
	(void)n_dirs;
	(void)dirs;
	t_pad pad;

	ft_bzero(&pad, sizeof(t_pad));
	while (dirs != NULL)
	{
		dirs_normal(dirs, opt, &pad, n_dirs);
		dirs = dirs->next;
	}
}

void	process_vars(t_list **vars, t_opt *opt, t_pad *pad)
{
	t_list	*dirs;
//	t_list	*files;
	size_t	n_dirs;
	(void)pad;
	(void)opt;

	dirs = fill_vars_dirs(*vars);
//	files = fill_vars_files(*vars);
	n_dirs = ft_lstlen(dirs);
/*
**	DEBUG
*//*
	print_test(dirs);
	print_test(files);
	printf("\nn_dirs = |%zu|\n", n_dirs);*/
/*
**	-
*/
//	printf("\nFINAL OUTPUT\n-\n");
//	print_files(files, opt, pad, n_dirs);
	process_dirs(dirs, opt, n_dirs);
//	free_lst(files);
	free_lst(dirs);
}
