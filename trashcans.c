void	print_dirs(char *var, t_opt *opt, size_t n_dirs)
{
	t_list	*dir_content;
	t_list	*to_free;
	char 	path[MAX];
	t_pad	pad;

	ft_bzero(&pad, sizeof(t_pad));
	opt->check = 0;
	if (!(dir_content = get_dir_content(var, opt)))
		opt->check = -1;
	if (dir_content && dir_content->next && opt->big_r)
		printf("\n");
	if ((!(opt->check_files) || n_dirs > 1) && opt->check != -1)
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
