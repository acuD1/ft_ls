/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_printf_parser.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 09:02:41 by arsciand          #+#    #+#             */
/*   Updated: 2019/02/21 13:19:14 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	buff_fill_int(int arg, char *buff)
{
	char *tmp;

	tmp = ft_itoa(arg);
	dup_and_clean(buff, tmp);
}

void	buff_fill_char(int arg, char *buff)
{
	char *tmp;

	tmp = ft_strnew(1);
	if (ft_isprint(arg))
		tmp[0] = arg;
	else
		*tmp = 0;
	dup_and_clean(buff, tmp);
}

void	buff_fill_str(char *arg, char *buff)
{
	char *tmp;

	if (!(arg))
		tmp = ft_strdup("(null)");
	else
		tmp = ft_strdup(arg);
	dup_and_clean(buff, tmp);
}
