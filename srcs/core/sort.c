/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 14:44:56 by arsciand          #+#    #+#             */
/*   Updated: 2019/03/09 14:45:42 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	lst_split(t_list *vars, t_list **start, t_list **end)
{
	t_list *slow;
	t_list *fast;

	slow = vars;
	fast = vars->next;
	if (!(vars) || !(vars->next))
	{
		*start = vars;
		*end = NULL;
		return;
	}
	while (fast)
	{
		fast = fast->next;
		if (fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*start = vars;
	*end = slow->next;
	slow->next = NULL;
}

t_list	*lst_merge_sort(t_list *a, t_list *b, int (*to_cmp)(t_list *, t_list *, int), int i)
{
	t_list *vars;

	vars = NULL;
	if (!(a))
		return (b);
	else if (!(b))
		return (a);
	if ((*to_cmp)(a, b, i) <= 0)
	{
		vars = a;
		vars->next = lst_merge_sort(a->next, b, to_cmp, i);
	}
	else
	{
		vars = b;
		vars->next = lst_merge_sort(a, b->next, to_cmp, i);
	}
	return (vars);
}

void 	lst_sort(t_list **vars, int (*to_cmp)(t_list *, t_list *, int), int i)
{
	t_list *a;
	t_list *b;
	t_list *hvars;

	hvars = *vars;
	if (!(hvars) || !(hvars->next))
		return ;
	lst_split(hvars, &a, &b);
	lst_sort(&a, to_cmp, i);
	lst_sort(&b, to_cmp, i);
	*vars = lst_merge_sort(a, b, to_cmp, i);
}

int		to_cmp(t_list *a, t_list *b, int i)
{
	if (i == 1)
		return (HALF_B->time_digit - HALF_A->time_digit);
	return (ft_strcmp(HALF_A->var, HALF_B->var));
}

void	sort_files(t_list **vars, t_opt *opt)
{
	lst_sort(vars , to_cmp, 0);
	if (opt->t == 1)
		lst_sort(vars, to_cmp, 1);
	if (opt->r == 1)
		ft_lstrev(vars);
}
