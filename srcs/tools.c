/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 13:04:49 by arsciand          #+#    #+#             */
/*   Updated: 2019/02/24 14:31:10 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_struct(t_ls *option)
{
	printf("option->R = |%d|\n\
option->a = |%d|\n\
option->l = |%d|\n\
option->r = |%d|\n\
option->t = |%d|\n",\
	option->R, option->a, option->l, option->r, option->t);
}
