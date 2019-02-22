/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_printf_convert.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 09:02:41 by arsciand          #+#    #+#             */
/*   Updated: 2019/02/22 10:43:00 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	s_mpf_padding(t_mprintf *s_mpf, int pad1, int pad2)
{
	s_mpf->pad = 1;
	s_mpf->pad1 = pad1;
	s_mpf->pad2 = pad2;
	return (3);
}

void	cat_and_clean(char *buff, char *tmp, char *var)
{
	ft_strcat(buff, var);
	ft_strdel(&tmp);
	ft_strdel(&var);
}
