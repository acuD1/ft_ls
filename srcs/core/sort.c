/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 14:44:56 by arsciand          #+#    #+#             */
/*   Updated: 2019/03/22 14:26:28 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		split_lst(t_list *vars, t_list **half_a, t_list **half_b)
{
	t_list *current;
	t_list *next_current;

	current = vars;
	next_current = vars->next;
	if (!(vars) || !(vars->next))
	{
		*half_a = vars;
		*half_b = NULL;
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
	*half_a = vars;
	*half_b = current->next;
	current->next = NULL;
}

static t_list	*merge_lst(t_list *half_a, t_list *half_b
					, int (*to_cmp)(t_list *, t_list *, int), int i)
{
	t_list *vars;

	vars = NULL;
	if (!(half_a))
		return (half_b);
	else if (!(half_b))
		return (half_a);
	if ((*to_cmp)(half_a, half_b, i) <= 0)
	{
		vars = half_a;
		vars->next = merge_lst(half_a->next, half_b, to_cmp, i);
	}
	else
	{
		vars = half_b;
		vars->next = merge_lst(half_a, half_b->next, to_cmp, i);
	}
	return (vars);
}

static void		merge_sort(t_list **vars, int (*to_cmp)(t_list *, t_list *, int)
					, int i)
{
	t_list *half_a;
	t_list *half_b;
	t_list *refvars;

	refvars = *vars;
	if (!(refvars) || !(refvars->next))
		return ;
	split_lst(refvars, &half_a, &half_b);
	merge_sort(&half_a, to_cmp, i);
	merge_sort(&half_b, to_cmp, i);
	*vars = merge_lst(half_a, half_b, to_cmp, i);
}

static int		to_cmp(t_list *half_a, t_list *half_b, int i)
{
	if (i == 1)
		return (HALF_B->time_digit - HALF_A->time_digit);
	return (ft_strcmp(HALF_A->var, HALF_B->var));
}

void			sort_vars(t_list **vars, t_opt *opt)
{
	merge_sort(vars, to_cmp, 0);
	if (opt->t == 1)
		merge_sort(vars, to_cmp, 1);
	if (opt->r == 1)
		ft_lstrev(vars);
}
