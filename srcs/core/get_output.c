/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_output.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 13:22:02 by arsciand          #+#    #+#             */
/*   Updated: 2019/04/01 10:42:48 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_output_width(t_opt *opt)
{
	struct winsize width;

	ioctl(0, TIOCGWINSZ, &width);
	opt->width = width.ws_col;
}

void	get_output(t_list **vars, t_opt *opt, t_pad *pad)
{
	t_list	*dirs;
	t_list	*files;
	size_t	n;

	dirs = fill_vars_dirs(*vars, opt);
	if (!(files = fill_vars_files(*vars, opt)))
		opt->check_files = 1;
	n = ft_lstlen(dirs);
	if (files)
	{
		ft_bzero(pad, sizeof(t_pad));
		get_pad(files, pad);
		print_files(files, opt, pad, 0);
	}
	if (files && dirs)
		printf("\n");
	process_dirs(dirs, opt, n);
	free_lst(files);
	free_lst(dirs);
}
