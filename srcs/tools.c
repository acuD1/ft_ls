/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 13:04:49 by arsciand          #+#    #+#             */
/*   Updated: 2019/02/25 10:40:27 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_struct(t_ls ls)
{
	printf("opt.R = |%d|\n\
opt.a = |%d|\n\
opt.l = |%d|\n\
opt.r = |%d|\n\
opt.t = |%d|\n",\
	ls.opt.R, ls.opt.a, ls.opt.l, ls.opt.r, ls.opt.t);
}
