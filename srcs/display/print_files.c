/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 10:52:17 by arsciand          #+#    #+#             */
/*   Updated: 2019/04/02 10:23:47 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_names(t_list *vars, t_opt *opt, t_pad *pad)
{
	static int		size;
	static int		words;
	static int		max;

	size += pad->m_normal_p + 1;
	if (size != opt->width)
		words += 1;
	max = words * (pad->m_normal_p + 1);
	if (opt->reset || (((max + pad->m_normal_p) >= opt->width)))
	{
		size = 0;
		words = 0;
		max = 0;
		if (!opt->reset)
			write(1, "\n", 1);
	}
	ft_mprintf(1, "%s%-*.*s", VARS_DB->color, pad->m_normal_p,
		VARS_DB->normal_p, VARS_DB->var);
	ft_mprintf(1, "%s", CLR);
	if (vars->next != NULL)
		write(1, " ", 1);
	if (vars->next == NULL)
		write(1, "\n", 1);
	opt->reset = 0;
}

static void	print_xattr(t_list *vars, t_opt *opt, t_pad *pad)
{
	int		i;

	i = 0;
	if (opt->xattr && VARS_DB->chmod[10] == '@')
	{
		i = 0;
		while (i < XATTR->size)
		{
			XATTR->val = getxattr(VARS_DB->av, &XATTR->xattr[i], XATTR->tmp,
				NAME_MAX, 0, XATTR_NOFOLLOW | XATTR_SHOWCOMPRESSION);
			ft_mprintf(1, "        %-*.*s %*.*d\n",
				pad->m_xattr_p, get_string_pad(&XATTR->xattr[i]),
				&XATTR->xattr[i],
				pad->m_val_p, get_int_pad(XATTR->val), XATTR->val,
				XATTR->val);
			i += (ft_strlen(&XATTR->xattr[i]) + 1);
		}
	}
}

static void	print_acl(t_list *vars, t_opt *opt)
{
	if (opt->e && VARS_DB->acl)
	{
		ft_mprintf(2, " 0: group:%s %s %s", VARS_DB->acl_tab[2],
			VARS_DB->acl_tab[4], VARS_DB->acl_tab[5]);
	}
}

static void	print_total(t_list *vars, t_opt *opt, size_t n_dirs)
{
	if ((n_dirs > 0 && opt->l && !opt->no_d && !opt->empty && !opt->one)
		|| (n_dirs > 0 && opt->s))
		ft_mprintf(1, "total %d\n", get_blocks(vars));
}

void		print_files(t_list *vars, t_opt *opt, t_pad *pad, size_t n_dirs)
{
	print_total(vars, opt, n_dirs);
	while (vars != NULL)
	{
		if (opt->s)
			ft_mprintf(1, "%*.*d ", pad->m_block_p, VARS_DB->block_p,
				VARS_DB->block);
		if (opt->l)
		{
			ft_mprintf(1, "%s %*.*d %-*.*s  %-*.*s  %*.*s %s %s%s%s%s\n",
					VARS_DB->chmod,
					pad->m_link_p, VARS_DB->link_p, VARS_DB->links,
					pad->m_uid_p, VARS_DB->uid_p, VARS_DB->uid,
					pad->m_gid_p, VARS_DB->gid_p, VARS_DB->gid,
					pad->m_size_mm_p, VARS_DB->size_mm_p, VARS_DB->size_mm,
					VARS_DB->mtime, VARS_DB->color, VARS_DB->var, CLR,
					VARS_DB->link_path);
			print_xattr(vars, opt, pad);
			print_acl(vars, opt);
		}
		else if (opt->one)
			ft_mprintf(1, "%s%s%s\n", VARS_DB->color, VARS_DB->var, CLR);
		else
			print_names(vars, opt, pad);
		vars = vars->next;
	}
}
