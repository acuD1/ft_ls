/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 08:37:29 by arsciand          #+#    #+#             */
/*   Updated: 2019/03/02 13:06:00 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "../libft/includes/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdio.h>

# define VARS_DB ((t_ls*)((t_list*)vars->content))

typedef struct	s_mprintf
{
	int			pad;
	int			indent;
	int			width;
	int			neg;
	int			diff;
	int			space;
}				t_mprintf;

typedef	struct	s_opt
{
	int			big_r;
	int			a;
	int			l;
	int			r;
	int			t;
}				t_opt;

typedef	struct	s_ls
{
	char		*var;
	char		type;
	char		*perms;
}				t_ls;

/*
**	mprintf
*/

void			ft_mprintf(int fd, const char *str, ...);
int				buff_fill_int(int arg, char *buff, t_mprintf *s_mpf);
int				buff_fill_char(int arg, char *buff, t_mprintf *s_mpf);
int				buff_fill_str(char *arg, char *buff, t_mprintf *s_mpf);

/*
**	parser
*/

t_list			*vars_parser(int ac, char **av, t_opt *opt, t_ls *db);

/*
**	db
*/

t_ls			*fetch_db(t_ls *db, char *av);
t_ls			*init_db(t_list *vars, t_ls *db);
char			get_type(struct stat d_stat);

/*
**	Display
*/

t_list			*usage(void);
void			print_opt(t_opt opt);
void			print_vars_db(t_list *vars);

#endif
