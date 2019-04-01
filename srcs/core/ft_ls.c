/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 11:02:03 by arsciand          #+#    #+#             */
/*   Updated: 2019/04/01 13:53:55 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		lol(t_list *vars)
{
	while (vars)
	{
		printf("%s\n", VARS_DB->var);
		vars = vars->next;
	}
}

static int		to_cmp_2(t_list *half_a, t_list *half_b, int i)
{
	if (i == 1)
	{
		if (HALF_B->time_digit == HALF_A->time_digit)
			return (ft_strcmp(HALF_B->var, HALF_A->var));
		else
			return (HALF_B->time_digit - HALF_A->time_digit);
	}
	if (i == 2)
		return (HALF_B->size - HALF_A->size);
	return (ft_strcmp(HALF_B->var, HALF_A->var));
}

void			sort_vars_2(t_list **vars, t_opt *opt)
{
	merge_sort(vars, to_cmp_2, 0);
	if (opt->t == 1)
		merge_sort(vars, to_cmp_2, 1);
	if (opt->size == 1)
		merge_sort(vars, to_cmp_2, 2);
	if (opt->r == 1)
		ft_lstrev(vars);
}

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
	sort_vars_2(&vars, &opt);
	print_failed(&vars);
	lol(vars);
	printf("\n");
	get_output(&vars, &opt, &pad);
	free_vars(vars);
	free(db);
	return (0);
}
