/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 11:02:03 by arsciand          #+#    #+#             */
/*   Updated: 2019/02/25 13:30:33 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	test_dir(int flag, t_ls *ls, t_list *args)
{
	(void)ls;
	if (flag == 0)
		printf("Testing |%s|\n", args->content);
}

t_list	*exec_args(t_ls *ls, t_list *args)
{
	t_list	*node;

	node = args;
	if (!args)
		return (NULL);
	while (node != NULL)
	{
		if (ft_strcmp(node->content, ".") == 0)
			test_dir(0, ls, args);
		else
			printf("Ops! not implemented yet\n");
		node = node->next;
	}
	return (NULL);
}

int		main(int ac, char **av)
{
	t_ls	ls;
	t_list	*args;

	ft_bzero(&ls, sizeof(t_ls));
	args = ls_parser(ac, av, &ls);
	exec_args(&ls, args);
	print_lst(args);
	print_struct(ls);
	ft_free_list(args);
	return (0);
}
