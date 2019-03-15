/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 11:46:03 by arsciand          #+#    #+#             */
/*   Updated: 2019/03/15 10:15:42 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_test(t_list *tmp)
{
	printf("\nDEBUG PROCESS_VARS\n\n");
	while (tmp)
	{
		if (((t_ls*)tmp->content)->type == 'd')
			printf("dirs = %s\n", ((t_ls*)tmp->content)->var);
		if (((t_ls*)tmp->content)->type == '-')
			printf("files = %s\n", ((t_ls*)tmp->content)->var);
		tmp = tmp->next;
	}
}
