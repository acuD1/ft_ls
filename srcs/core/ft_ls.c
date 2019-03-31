/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 11:02:03 by arsciand          #+#    #+#             */
/*   Updated: 2019/03/31 10:45:53 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			main(int ac, char **av)
{
	t_opt	opt;
	t_ls	*db;
	t_list	*vars;
	t_pad	pad;

	ft_bzero(&opt, sizeof(t_opt));
	ft_bzero(&pad, sizeof(t_pad));
	if (!(db = (t_ls*)malloc(sizeof(t_ls))))
		return (0);
	if (!(vars = get_vars(ac, av, &opt, db)))
	{
		free(db);
		return (0);
	}
	get_output_width(&opt);
	get_pad(vars, &pad);
	sort_vars(&vars, &opt);
	print_failed(&vars);
	get_output(&vars, &opt, &pad);
	free_vars(vars);
	free(db);
	return (0);
}
