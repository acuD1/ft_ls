/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 14:19:04 by arsciand          #+#    #+#             */
/*   Updated: 2019/02/28 14:19:20 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	fetch_db(t_ls *db, t_list *node)
{
	struct stat	d_stat;

	lstat(node->content, &d_stat);
	db->type = get_type(d_stat);
	printf("DEBUG | db->type = |%c|\n", db->type);
}

t_ls	*init_db(t_list *args)
{
	t_list	*node;
	t_ls	*db;

	node = args;
	if (!(db = (t_ls*)malloc(sizeof(t_ls))))
		return (NULL);
	while (node != NULL)
	{
		printf("DEBUG | node->content= |%s|\n", node->content);
		fetch_db(db, node);
		node = node->next;
	}
	return (db);
}
