/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pad.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 15:40:56 by arsciand          #+#    #+#             */
/*   Updated: 2019/04/01 09:11:12 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		get_string_pad(char *guid)
{
	int	guid_p;

	guid_p = 0;
	while (guid[guid_p])
		guid_p++;
	return (guid_p);
}

char	*get_minor_pad(char *min)
{
	size_t		length;
	size_t		i;
	static char	tmp[4];

	length = ft_strlen(min);
	i = 0;
	ft_memset(tmp, ' ', 4);
	while (length)
	{
		tmp[i] = min[length - 1];
		i++;
		length--;
	}
	free(min);
	return (ft_strrev(tmp));
}

int		get_int_pad(int i)
{
	int pad;

	pad = 0;
	if (!i)
		return (1);
	while (i > 0)
	{
		i /= 10;
		pad++;
	}
	return (pad);
}

static void	tmp_pad(t_list *vars, t_pad *pad)
{
	pad->tmp_xattr_p = VARS_DB->xattr_p;
	pad->tmp_val_p = 4;
	pad->tmp_size_mm_p = get_string_pad(VARS_DB->size_mm);
	pad->tmp_block_p = get_int_pad(VARS_DB->block);
	pad->tmp_uid_p = get_string_pad(VARS_DB->uid);
	pad->tmp_gid_p = get_string_pad(VARS_DB->gid);
	pad->tmp_link_p = get_int_pad(VARS_DB->links);
	pad->tmp_normal_p = get_string_pad(VARS_DB->var);
}

void	get_pad(t_list *vars, t_pad *pad)
{
	while (vars)
	{
		tmp_pad(vars, pad);
		if (pad->tmp_xattr_p > pad->m_xattr_p)
			pad->m_xattr_p = pad->tmp_xattr_p;
		if (pad->tmp_val_p > pad->m_val_p)
			pad->m_val_p = pad->tmp_val_p;
		if ((VARS_DB->type == 'c' && pad->tmp_size_mm_p < 8) ||
			(VARS_DB->type == 'b' && pad->tmp_size_mm_p < 8))
			pad->tmp_size_mm_p = 8;
		if (pad->tmp_block_p > pad->m_block_p)
			pad->m_block_p = pad->tmp_block_p;
		if (pad->tmp_normal_p > pad->m_normal_p)
			pad->m_normal_p = pad->tmp_normal_p;
		if (pad->tmp_size_mm_p > pad->m_size_mm_p)
			pad->m_size_mm_p = pad->tmp_size_mm_p;
		if (pad->tmp_uid_p > pad->m_uid_p)
			pad->m_uid_p = pad->tmp_uid_p;
		if (pad->tmp_gid_p > pad->m_gid_p)
			pad->m_gid_p = pad->tmp_gid_p;
		if (pad->tmp_link_p > pad->m_link_p)
			pad->m_link_p = pad->tmp_link_p;
		vars = vars->next;
	}
}
