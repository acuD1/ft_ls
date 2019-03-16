/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 11:20:28 by arsciand          #+#    #+#             */
/*   Updated: 2019/03/16 17:00:18 by arsciand         ###   ########.fr       */
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

t_list		*failed_opendir(char *var, t_opt *opt)
{
	(void)opt;
//	if (opt->multiple == -1)
//		ft_mprintf(1, "%s:\n", var);
	ft_putstr_fd("ft_ls: ", 2);
	ft_putstr_fd(var + ft_strnrchr(var, '/'), 2);
	ft_putstr_fd(": ", 2);
	perror(0);
//	printf("\n");
	return (NULL);
}


t_list	*get_dir_content(char *var, t_opt *opt)
{
	DIR		*content;
	t_list	*dir_content;

	//printf("??%s\n", var);
	if (!(content = opendir(var)))
	{
		return (failed_opendir(var, opt));
	}
	opt->multiple = -1;
	dir_content = fetch_dir_content(var, content, opt);
	closedir(content);
	return (dir_content);
}

void	dirs_normal(char *var, t_opt *opt, int n_dirs)
{
	t_list	*dir_content;
	t_pad	pad;

	ft_bzero(&pad, sizeof(t_pad));
	opt->check = 0;
	if (n_dirs > 1 || !(opt->check_files))
		ft_mprintf(1, "%s:\n", var);
	if (!(dir_content = get_dir_content(var, opt)))
		opt->check = -1;
	sort_vars(&dir_content, opt);
	get_pad(dir_content, &pad);
	print_files(dir_content, opt, &pad, n_dirs);
	free_vars(dir_content);
}

int		get_lol(t_list *dir_content)
{
	char *test;
	int i = 0;

	test = ft_strnew(MAX);
	while (dir_content)
	{
		if (DIR_C_DB->type == 'd')
			i++;
			//ft_strcpy(test, DIR_C_DB->var);
		dir_content = dir_content->next;
	}
	return (i);
}


// Found tricky shit, will see tomorrow
// Check at size = 1 the last var at the last linked list node, and print \n until we reach this one

void	dirs_recursive(char *var, t_opt *opt, size_t n_dirs, int size)
{
	t_list	*dir_content;
	t_list	*to_free;
	char 	path[MAX];
	t_pad	pad;

	ft_bzero(&pad, sizeof(t_pad));
	opt->check = 0;
	dir_content = get_dir_content(var, opt);
	if (!(opt->check_files) || n_dirs > 1)
		ft_mprintf(1, "%s:\n", var);
	opt->check_files = 0;
	sort_vars(&dir_content, opt);
	get_pad(dir_content, &pad);
//	print_test(dir_content);
	if (size == 1 && opt->no != 1)
	{
		opt->no = 1;
		printf("lol = |%d|\n", get_lol(dir_content));
	}
	print_files(dir_content, opt, &pad, n_dirs);
	printf("\n");
	to_free = dir_content;
	while (dir_content)
	{
		if (DIR_C_DB->type == 'd')
		{
			dirs_recursive(get_dir_path(path, var, DIR_C_DB->var), opt, n_dirs, size);
		}
		dir_content = dir_content->next;
	}
	free_vars(to_free);
}
