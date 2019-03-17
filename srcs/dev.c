/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 11:20:28 by arsciand          #+#    #+#             */
/*   Updated: 2019/03/17 11:58:24 by arsciand         ###   ########.fr       */
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


t_list	*get_dir_content(char *var, t_opt *opt, int size)
{
	DIR		*content;
	t_list	*dir_content;
	t_list *test;
	int		i = 0;

	//printf("??%s\n", var);
	if (!(content = opendir(var)))
	{
		return (failed_opendir(var, opt));
	}
	opt->multiple = -1;
	dir_content = fetch_dir_content(var, content, opt);
	closedir(content);
	test = dir_content;
	if (size == 1)
	{
		printf("DEBUG?\n");
		while (test)
		{
			if (((t_ls*)test->content)->type == 'd')
				i++;
			test = test->next;
		}
	}
	if (!i)
		opt->no_d = 1;
	//printf("no_d = %d\n", opt->no_d);
	return (dir_content);
}

void	dirs_normal(char *var, t_opt *opt, int n_dirs, int size)
{
	t_list	*dir_content;
	t_pad	pad;

	ft_bzero(&pad, sizeof(t_pad));
	opt->check = 0;
	if (n_dirs > 1 || !(opt->check_files))
		ft_mprintf(1, "%s:\n", var);
	if (!(dir_content = get_dir_content(var, opt, size)))
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
	t_list *test;
	static char new[MAX];

	ft_bzero(&pad, sizeof(t_pad));
	opt->check = 0;
	dir_content = get_dir_content(var, opt, size);
	if (!(opt->check_files) || n_dirs > 1)
		ft_mprintf(1, "%s:\n", var);
	opt->check_files = 0;
	sort_vars(&dir_content, opt);
	get_pad(dir_content, &pad);
//	print_test(dir_content);
	printf("dirs no_do = %d\n", opt->no_d);
	test = dir_content;
	if (opt->no_d == 0 && opt->go == 1)
	{
		while (test->next)
		{
			test = test->next;
		}
		printf("CPY %s\n", ft_strcpy(new, ((t_ls*)test->content)->var));
	//	((t_ls*)test->content)->stop = 1;
		//printf("%s > to_stop = %d\n", ((t_ls*)test->content)->var, ((t_ls*)test->content)->stop);
	}
	printf("new rec = %s\n", new);
	printf("TEST = %s\n", var + ft_strnrchr(var, '/'));
	if (!(ft_strcmp(new, var + ft_strnrchr(var, '/'))))
	{
		opt->no = 1;
		printf("OK\n");
	}
	print_files(dir_content, opt, &pad, n_dirs);
	to_free = dir_content;
	t_list *tmp;
	tmp = dir_content;
	int i = 0;
	while (tmp)
	{
		if (((t_ls*)tmp->content)->type == 'd')
			i++;
		tmp = tmp->next;
	}
	printf("i = |%d|\n", i);
	while (dir_content)
	{
		opt->go = 0;
		if (DIR_C_DB->type == 'd')
		{
			printf("DIRS_C_DB %s \n", DIR_C_DB->var);
			/*if (dir_content->next)
			{
				t_list *tmp;
				tmp = dir_content->next;
				printf("DIRS_C_DB NEXT %s \n", ((t_ls*)tmp->content)->var);
				if (((t_ls*)tmp->content)->type == 'd')
					opt->go = 1;
			}*/
			if (i == 1)
				opt->go = 1;
			dirs_recursive(get_dir_path(path, var, DIR_C_DB->var), opt, n_dirs, size);
		}
		dir_content = dir_content->next;
	}
	free_vars(to_free);
}
