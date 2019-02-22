/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 08:37:29 by arsciand          #+#    #+#             */
/*   Updated: 2019/02/22 08:55:29 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "../libft/includes/libft.h"
# include <stdarg.h>
# include <stdlib.h>

typedef struct	s_mprintf
{
	int		pad;
	int		pad1;
	int		pad2;
	int		neg;
}				t_mprintf;

void	ft_ls_test(void);
void	mprintf(int fd, const char *str, ...);
void	buff_fill_int(int arg, char *buff);
void	buff_fill_char(int c, char *buff);
void	buff_fill_str(char *str, char *buff);
void	dup_and_clean(char *buff, char *tmp);

#include <stdio.h>
#endif
