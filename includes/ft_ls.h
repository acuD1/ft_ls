/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 08:37:29 by arsciand          #+#    #+#             */
/*   Updated: 2019/02/22 10:45:28 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "../libft/includes/libft.h"
# include <stdarg.h>
# include <stdlib.h>

typedef struct	s_mprintf
{
	int			pad;
	int			pad1;
	int			pad2;
	int			neg;
}				t_mprintf;

void	ft_ls_test(void);
void	mprintf(int fd, const char *str, ...);
int		s_mpf_padding(t_mprintf *s_mpf, int pad1, int pad2);
void	cat_and_clean(char *buff, char *tmp, char *var);

#include <stdio.h>
#endif
