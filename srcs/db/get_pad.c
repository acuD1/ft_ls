/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pad.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 15:40:56 by arsciand          #+#    #+#             */
/*   Updated: 2019/03/15 10:38:34 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		get_smmguid_pad(char *guid)
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
	while (i > 0)
	{
		i /= 10;
		pad++;
	}
	return (pad);
}

void	get_pad(t_list *vars, t_pad *pad)
{
	int tmp_size_mm_p;
	int	tmp_uid_p;
	int	tmp_gid_p;
	int	tmp_link_p;

	while (vars)
	{
		tmp_size_mm_p = get_smmguid_pad(VARS_DB->size_mm);
		if ((VARS_DB->type == 'c' && tmp_size_mm_p < 8) ||
			(VARS_DB->type == 'b' && tmp_size_mm_p < 8))
			tmp_size_mm_p = 8;
		tmp_uid_p = get_smmguid_pad(VARS_DB->uid);
		tmp_gid_p = get_smmguid_pad(VARS_DB->gid);
		tmp_link_p = get_int_pad(VARS_DB->links);
		if (tmp_size_mm_p > pad->m_size_mm_p)
			pad->m_size_mm_p = tmp_size_mm_p;
		if (tmp_uid_p > pad->m_uid_p)
			pad->m_uid_p = tmp_uid_p;
		if (tmp_gid_p > pad->m_gid_p)
			pad->m_gid_p = tmp_gid_p;
		if (tmp_link_p > pad->m_link_p)
			pad->m_link_p = tmp_link_p;
		vars = vars->next;
	}
}
