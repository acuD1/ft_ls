/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 11:20:28 by arsciand          #+#    #+#             */
/*   Updated: 2019/03/06 18:08:51 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_content(t_list *vars, t_opt *opt, t_pad *pad)
{
	while (vars != NULL)
	{
		if (opt->l)
			ft_mprintf(1, "%s  %d %-*.*s  %-*.*s  %*.*s %s %s\n",
					VARS_DB->perms, VARS_DB->links,
					pad->m_uid_p, VARS_DB->uid_p, VARS_DB->uid,
					pad->m_gid_p, VARS_DB->gid_p, VARS_DB->gid,
					pad->m_size_mm_p, VARS_DB->size_mm_p, VARS_DB->size_mm,
					VARS_DB->mtime, VARS_DB->var);
		else
		{
			if (VARS_DB->type == '-')
				ft_mprintf(1, "%s", VARS_DB->var);
			if (vars->next != NULL)
				ft_mprintf(1, " ");
			if (vars->next == NULL)
				ft_mprintf(1, "\n");
		}
		vars = vars->next;
	}
}
