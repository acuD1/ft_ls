/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 08:37:29 by arsciand          #+#    #+#             */
/*   Updated: 2019/02/24 10:49:49 by arsciand         ###   ########.fr       */
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
	int			indent;
	int			width;
	int			neg;
	int			diff;
	int			space;
}				t_mprintf;

void			ft_ls_test(void);
void			ft_mprintf(int fd, const char *str, ...);
int				buff_fill_int(int arg, char *buff, t_mprintf *s_mpf);
int				buff_fill_char(int arg, char *buff, t_mprintf *s_mpf);
int				buff_fill_str(char *arg, char *buff, t_mprintf *s_mpf);

#endif
