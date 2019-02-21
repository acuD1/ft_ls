/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 13:19:24 by arsciand          #+#    #+#             */
/*   Updated: 2019/02/21 13:19:56 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	dup_and_clean(char *buff, char *tmp)
{
	char *var;

	var = ft_strdup(tmp);
	ft_strcat(buff, var);
	ft_strdel(&tmp);
	ft_strdel(&var);
}
