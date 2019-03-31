/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_xattr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 12:08:51 by arsciand          #+#    #+#             */
/*   Updated: 2019/03/31 12:15:17 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_xattr(t_ls *db, char *av, t_opt *opt)
{
	int		i;
	int		tmp_xattr_p;
	int		tmp_val_p;

	i = 0;
	tmp_val_p = 0;
	tmp_xattr_p = 0;
	if (!(db->xattr = (t_xattr*)malloc(sizeof(t_xattr)))
		|| (!opt->l && db->chmod[10] != '@'))
		return ;
	XATTR_DB->size = listxattr(av, XATTR_DB->tmp, MAX, XATTR_NOFOLLOW);
	XATTR_DB->xattr = ft_strnew(MAX + 1);
	XATTR_DB->size = listxattr(av, XATTR_DB->xattr, MAX, XATTR_NOFOLLOW);
	while (i < XATTR_DB->size)
	{
		XATTR_DB->val = getxattr(av, &XATTR_DB->xattr[i], XATTR_DB->tmp,
			NAME_MAX, 0, XATTR_NOFOLLOW | XATTR_SHOWCOMPRESSION);
		if (get_int_pad(XATTR_DB->val) > tmp_val_p)
			tmp_val_p = get_int_pad(XATTR_DB->val);
		if (get_string_pad(XATTR_DB->xattr) > tmp_xattr_p)
			tmp_xattr_p = get_string_pad(XATTR_DB->xattr);
		i += (ft_strlen(&XATTR_DB->xattr[i]) + 1);
	}
	db->xattr_p = tmp_xattr_p;
	db->val_p = tmp_val_p;
}
