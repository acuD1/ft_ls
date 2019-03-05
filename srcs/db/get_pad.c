/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pad.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 15:40:56 by arsciand          #+#    #+#             */
/*   Updated: 2019/03/05 16:16:39 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		get_guid_pad(char *guid)
{
	int	guid_p;

	guid_p = 0;
	while (guid[guid_p])
		guid_p++;
	return (guid_p);
}

size_t	get_size_pad(size_t size)
{
	int	tmp_s;

	tmp_s = 0;
	if (size == 0)
		return (1);
	while (size != 0)
	{
		size /= 10;
		tmp_s++;
	}
	return (tmp_s);
}

void	get_pad(t_list *vars, t_pad *pad)
{
	int tmp_s_p;
	int	tmp_uid_p;
	int	tmp_gid_p;

	while (vars)
	{
		tmp_s_p = get_size_pad(VARS_DB->size);
		tmp_uid_p = get_guid_pad(VARS_DB->uid);
		tmp_gid_p = get_guid_pad(VARS_DB->gid);
		if (tmp_s_p > pad->m_s_p)
			pad->m_s_p = tmp_s_p;
		if (tmp_uid_p > pad->m_uid_p)
			pad->m_uid_p = tmp_uid_p;
		if (tmp_gid_p > pad->m_gid_p)
			pad->m_gid_p = tmp_gid_p;
		vars = vars->next;
	}
}
