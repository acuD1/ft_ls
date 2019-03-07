/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 11:20:28 by arsciand          #+#    #+#             */
/*   Updated: 2019/03/07 13:03:21 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list	*type_sort(t_list *vars)
{
	t_list *head;
	t_list *vars_sorted;

	head = vars;
	while (vars != NULL && VARS_DB->type == '-')
	{
		ft_lstpushback(&vars_sorted, ft_lstnew(VARS_DB, sizeof(t_ls)));
		vars = vars->next;
	}
	vars = head;
	while (vars != NULL && VARS_DB->type == 'd')
	{
		ft_lstpushback(&vars_sorted, ft_lstnew(VARS_DB, sizeof(t_ls)));
		vars = vars->next;
	}
	return (vars_sorted);
}

t_list	*sort_vars(t_list *vars, t_opt *opt)
{
	if (!(opt->r) || !(opt->t))
	{
		printf("Return type sort?\n");
		return (type_sort(vars));
	}
	return (NULL);
}
