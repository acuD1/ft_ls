/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 08:54:05 by arsciand          #+#    #+#             */
/*   Updated: 2019/02/19 13:15:08 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <unistd.h>

void	print_buff(va_list args, char *buff)
{
	if ()
}

void	get_args(va_list args, char *buff)
{
	if (*buff == 'd')
		buff = va_arg(args, int);
}

void	mini_printf(int fd, const char *str, ...)
{
	va_list	args;
	char	*buff;

	va_start(args, str);
	buff = ft_strnew(BUFF_SIZE + 1);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			get_args(args, buff);
		}
		str++;
	}
	print_buff(args, buff);
	va_end(args);
}
