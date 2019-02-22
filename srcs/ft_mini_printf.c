/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 08:54:05 by arsciand          #+#    #+#             */
/*   Updated: 2019/02/22 10:46:28 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	buff_fill_int(int arg, char *buff, t_mprintf *s_mpf)
{
	char *tmp;
	char *var;

	tmp = ft_itoa(arg);
	s_mpf->pad = 1;
	var = ft_strdup(tmp);
	cat_and_clean(buff, tmp, var);
}

static void	buff_fill_char(int arg, char *buff)
{
	char *tmp;
	char *var;

	tmp = ft_strnew(1);
	if (ft_isprint(arg))
		tmp[0] = arg;
	else
		*tmp = 0;
	var = ft_strdup(tmp);
	cat_and_clean(buff, tmp, var);
}

static void	buff_fill_str(char *arg, char *buff)
{
	char *tmp;
	char *var;

	if (!(arg))
		tmp = ft_strdup("(null)");
	else
		tmp = ft_strdup(arg);
	var = ft_strdup(tmp);
	cat_and_clean(buff, tmp, var);
}

static void	get_args(va_list args, char *buff, char *str)
{
	int			i;
	t_mprintf	*s_mpf;
	char		*mprintf_opt;

	i = 0;
	if (!(s_mpf = (t_mprintf*)malloc(sizeof(t_mprintf))))
		return ;
	ft_bzero(s_mpf, sizeof(t_mprintf));
	mprintf_opt = "%dcs-.*";
	while (str[i] && ft_strchr(mprintf_opt, str[i]))
	{
		if (str[i] == '-')
			s_mpf->neg = 1;
		if (str[i] == '*' && str[i] == '.' && str[i] == '*')
			i += s_mpf_padding(s_mpf, va_arg(args, int), va_arg(args, int));
		if (str[i] == 'd')
			buff_fill_int(va_arg(args, int), buff, s_mpf);
		if (str[i] == 'c')
			buff_fill_char(va_arg(args, int), buff);
		if (str[i] == 's')
			buff_fill_str(va_arg(args, char *), buff);
		i++;
	}
	ft_strdel(&str);
	free(s_mpf);
}

void		mprintf(int fd, const char *str, ...)
{
	va_list		args;
	char		*buff;

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
