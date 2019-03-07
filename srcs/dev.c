/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 11:20:28 by arsciand          #+#    #+#             */
/*   Updated: 2019/03/07 17:20:30 by arsciand         ###   ########.fr       */
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

t_list	*lst_merge_sort(t_list *a, t_list *b)
{
	t_list *result;

	result = NULL;
	if (!(a))
		return b;
	else if (!(b))
		return a;
	if (((t_ls*)((t_list*)a->content))->time_digit <= ((t_ls*)((t_list*)b->content))->time_digit)
	{
		result = a;
		result->next = lst_merge_sort(a->next, b);
	}
	else
	{
		result = b;
		result->next = lst_merge_sort(a, b->next);
	}
	return (result);
}

void 	lst_sort(t_list **alist)
{
	t_list *a;
	t_list *b;

	if (!(*alist) || !((*alist)->next))
		return ;
	lst_split(*alist, &a, &b);
	lst_sort(&a);
	lst_sort(&b);
	lst_merge_sort(a, b);
}

void	lst_rev(t_list **alist)
{
	t_list *current;
	t_list *next;
	t_list *prev;

	current = *alist;
	next = NULL;
	prev = NULL;
	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*alist = prev;
}

t_list  *test(t_list *vars, t_opt *opt)
{
	if (opt->t)
	{
		lst_sort(&vars);
		lst_rev(&vars);
	}
	return (vars);
}
