/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pad.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 15:40:56 by arsciand          #+#    #+#             */
/*   Updated: 2019/03/10 13:23:11 by arsciand         ###   ########.fr       */
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

void	get_pad(t_list *vars, t_pad *pad)
{
	int tmp_size_mm_p;
	int	tmp_uid_p;
	int	tmp_gid_p;

	while (vars)
	{
		tmp_size_mm_p = get_smmguid_pad(VARS_DB->size_mm);
		if ((VARS_DB->type == 'c' && tmp_size_mm_p < 8) ||
			(VARS_DB->type == 'b' && tmp_size_mm_p < 8))
			tmp_size_mm_p = 8;
		tmp_uid_p = get_smmguid_pad(VARS_DB->uid);
		tmp_gid_p = get_smmguid_pad(VARS_DB->gid);
		if (tmp_size_mm_p > pad->m_size_mm_p)
			pad->m_size_mm_p = tmp_size_mm_p;
		if (tmp_uid_p > pad->m_uid_p)
			pad->m_uid_p = tmp_uid_p;
		if (tmp_gid_p > pad->m_gid_p)
			pad->m_gid_p = tmp_gid_p;
		vars = vars->next;
	}
}
