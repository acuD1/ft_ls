/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 08:54:05 by arsciand          #+#    #+#             */
/*   Updated: 2019/02/21 13:14:22 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	get_args(va_list args, char *buff, char *str)
{
	int		i;
	char	*printf_option;

	i = 0;
	printf_option = "%dcs";
	while (str[i] && ft_strchr(printf_option, str[i]))
	{
		if (str[i] == 'd')
			buff_fill_int(va_arg(args, int), buff);
		if (str[i] == 'c')
			buff_fill_char(va_arg(args, int), buff);
		if (str[i] == 's')
			buff_fill_str(va_arg(args, char *), buff);
		i++;
	}
	ft_strdel(&str);
}

void		mini_printf(int fd, const char *str, ...)
{
	va_list	args;
	char	*buff;

	va_start(args, str);
	buff = ft_strnew(BUFF_SIZE + 1);
	while (*str)
	{
		if (*str == '%')
			get_args(args, buff, ft_strdup(str++));
		else
			ft_strncat(buff, str, 1);
		str++;
	}
	ft_putstr_fd(buff, fd);
	ft_bzero(buff, BUFF_SIZE);
	ft_strdel(&buff);
	va_end(args);
}
