/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 14:44:56 by arsciand          #+#    #+#             */
/*   Updated: 2019/03/10 13:33:20 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		split_lst(t_list *vars, t_list **split_a, t_list **split_b)
{
	t_list *current;
	t_list *next_current;

	current = vars;
	next_current = vars->next;
	if (!(vars) || !(vars->next))
	{
		*split_a = vars;
		*split_b = NULL;
		return ;
	}
	while (next_current)
	{
		next_current = next_current->next;
		if (next_current)
		{
			current = current->next;
			next_current = next_current->next;
		}
	}
	*split_a = vars;
	*split_b = current->next;
	current->next = NULL;
}

static t_list	*merge_lst(t_list *split_a, t_list *split_b
					, int (*to_cmp)(t_list *, t_list *, int), int i)
{
	t_list *vars;

	vars = NULL;
	if (!(split_a))
		return (split_b);
	else if (!(split_b))
		return (split_a);
	if ((*to_cmp)(split_a, split_b, i) <= 0)
	{
		vars = split_a;
		vars->next = merge_lst(split_a->next, split_b, to_cmp, i);

	}
	else
	{
		vars = split_b;
		vars->next = merge_lst(split_a, split_b->next, to_cmp, i);
	}
	return (vars);
}

static void		merge_sort(t_list **vars, int (*to_cmp)(t_list *, t_list *, int)
					, int i)
{
	t_list *split_a;
	t_list *split_b;
	t_list *refvars;

	refvars = *vars;
	if (!(refvars) || !(refvars->next))
		return ;
	split_lst(refvars, &split_a, &split_b);
	merge_sort(&split_a, to_cmp, i);
	merge_sort(&split_b, to_cmp, i);
	*vars = merge_lst(split_a, split_b, to_cmp, i);
}

static	int		to_cmp(t_list *split_a, t_list *split_b, int i)
{
	if (i == 1)
		return (HALF_B->time_digit - HALF_A->time_digit);
	return (ft_strcmp(HALF_A->var, HALF_B->var));
}

void			sort_files(t_list **vars, t_opt *opt)
{
	merge_sort(vars, to_cmp, 0);
	if (opt->t == 1)
		merge_sort(vars, to_cmp, 1);
	if (opt->r == 1)
		ft_lstrev(vars);
}
