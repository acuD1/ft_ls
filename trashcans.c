void	dirs_normal(char *var, t_opt *opt, int n_dirs)
{
	t_list	*dir_content;
	t_pad	pad;

	ft_bzero(&pad, sizeof(t_pad));
	if (n_dirs > 1 || !(opt->check_files))
		ft_mprintf(1, "%s:\n", var);
	dir_content = get_dir_content(var, opt);
	sort_vars(&dir_content, opt);
	get_pad(dir_content, &pad);
	print_files(dir_content, opt, &pad, n_dirs);
	free_vars(dir_content);
}

void	dirs_recursive(char *var, t_opt *opt, size_t n_dirs)
{
	t_list	*dir_content;
	t_list	*to_free;
	char 	path[MAX];
	t_pad	pad;

	ft_bzero(&pad, sizeof(t_pad));
	dir_content = get_dir_content(var, opt);
	if (dir_content->next)
		printf("\n");
	if (!(opt->check_files) || n_dirs > 1)
		ft_mprintf(1, "%s:\n", var);
	opt->check_files = 0;
	sort_vars(&dir_content, opt);
	get_pad(dir_content, &pad);
	print_files(dir_content, opt, &pad, n_dirs);
	to_free = dir_content;
	while (dir_content)
	{
		if (DIR_C_DB->type == 'd')
			dirs_recursive(get_dir_path(path, var, DIR_C_DB->var), opt, n_dirs);
		dir_content = dir_content->next;
	}
	free_vars(to_free);
}


/*
void	process_dirs(t_list *dirs, t_opt *opt, size_t n_dirs)
{
	while (dirs != NULL)
	{
		if (opt->big_r)
			dirs_recursive(DIRS_DB->var, opt, n_dirs);
		else
		{
			dirs_normal(DIRS_DB->var, opt, n_dirs);
			if (dirs->next)
				printf("\n");
		}
		dirs = dirs->next;
	}
}
*/
