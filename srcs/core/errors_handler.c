/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 12:51:14 by arsciand          #+#    #+#             */
/*   Updated: 2019/03/16 13:00:24 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	lstat_failure(char *av, int *fail)
{
	ft_putstr_fd("ft_ls: ", 2);
	ft_putstr_fd(av, 2);
	ft_putstr_fd(": ", 2);
	perror(0);
	strerror(errno);
	*fail = 1;
}