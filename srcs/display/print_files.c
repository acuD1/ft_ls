/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 10:52:17 by arsciand          #+#    #+#             */
/*   Updated: 2019/03/22 10:27:51 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_files(t_list *vars, t_opt *opt, t_pad *pad, size_t n_dirs)
{
	if (n_dirs > 0 && opt->l && !opt->no_d && !opt->empty)
		ft_mprintf(1, "total %d\n", get_blocks(vars));
	while (vars != NULL)
	{
		if (opt->l)
			ft_mprintf(1, "%s  %*.*d %-*.*s  %-*.*s  %*.*s %s %s%s\n",
					VARS_DB->perms,
					pad->m_link_p, VARS_DB->link_p, VARS_DB->links,
					pad->m_uid_p, VARS_DB->uid_p, VARS_DB->uid,
					pad->m_gid_p, VARS_DB->gid_p, VARS_DB->gid,
					pad->m_size_mm_p, VARS_DB->size_mm_p, VARS_DB->size_mm,
					VARS_DB->mtime, VARS_DB->var, VARS_DB->link_path);
		else
		{
			ft_mprintf(1, "%s", VARS_DB->var);
			if (vars->next != NULL)
				ft_mprintf(1, " ");
			if (vars->next == NULL)
				ft_mprintf(1, "\n");
		}
		vars = vars->next;
	}
}
