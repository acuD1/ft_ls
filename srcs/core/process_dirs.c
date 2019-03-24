/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_dirs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 14:24:00 by arsciand          #+#    #+#             */
/*   Updated: 2019/03/24 12:57:49 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_list	*fetch_dir_content(char *var, DIR *content, t_opt *opt)
{
	t_list			*dir_content;
	t_ls			*db;
	struct dirent	*dir;
	char			*dir_path;

	if (!(db = (t_ls*)malloc(sizeof(t_ls))))
		return (0);
	dir_path = ft_strnew(MAX);
	while ((dir = readdir(content)))
	{
		dir_path = get_dir_path(dir_path, var, dir->d_name);
		if (!(opt->a) && dir->d_name[0] == '.')
			continue;
		ft_lstpushback(&dir_content,
			ft_lstnew(fetch_db(db, dir_path, dir->d_name, opt), sizeof(t_ls)));
		continue;
	}
	free(dir_path);
	free(db);
	return (dir_content);
}

static t_list	*get_dir_content(char *var, t_opt *opt)
{
	DIR		*content;
	t_list	*dir_content;

	opt->empty = 0;
	if (!(content = opendir(var)))
	{
		opt->no_d = 1;
		if (!opt->no_n)
			write(1, "\n", 1);
		return (failed_opendir(var));
	}
	dir_content = fetch_dir_content(var, content, opt);
	if (!(ft_lstlen(dir_content)))
		opt->empty = 1;
	closedir(content);
	return (dir_content);
}

static void		format_output(t_opt *opt, size_t n_dirs, char *var)
{
	if (!opt->no_n && opt->no_d == 0)
		write(1, "\n", 1);
	opt->no_n = 0;
	if (opt->lstat_first_arg && !opt->no_args)
		ft_mprintf(1, "%s:\n", var);
	else if (!(opt->check_files) || n_dirs > 1)
		if (!opt->no_d)
			ft_mprintf(1, "%s%s:\n", CLR, var);
	opt->check_files = 0;
}

static void		print_dirs(char *var, t_opt *opt, size_t n, int len)
{
	t_list	*dir_content;
	t_list	*to_free;
	char	path[MAX];
	t_pad	pad;

	opt->no_d = 0;
	ft_bzero(&pad, sizeof(t_pad));
	dir_content = get_dir_content(var, opt);
	format_output(opt, n, var);
	sort_vars(&dir_content, opt);
	get_pad(dir_content, &pad);
	print_files(dir_content, opt, &pad, n);
	to_free = dir_content;
	while (dir_content && opt->big_r)
	{
		if (ft_strequ(DIR_C_DB->var, ".") || ft_strequ(DIR_C_DB->var, ".."))
		{
			dir_content = dir_content->next;
			continue;
		}
		if (DIR_C_DB->type == 'd')
			print_dirs(get_dir_path(path, var, DIR_C_DB->var), opt, n, len);
		dir_content = dir_content->next;
	}
	dirs_free(to_free, dir_content, opt);
}

void			process_dirs(t_list *dirs, t_opt *opt, size_t n)
{
	int		len;
	int		max;

	len = ft_lstlen(dirs);
	max = len;
	while (dirs != NULL)
	{
		if (len == max)
			opt->no_n = 1;
		print_dirs(DIRS_DB->var, opt, n, len);
		dirs = dirs->next;
		len--;
	}
}
