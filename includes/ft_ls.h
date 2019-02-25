/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 08:37:29 by arsciand          #+#    #+#             */
/*   Updated: 2019/02/25 13:49:53 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "../libft/includes/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <dirent.h>

# include <stdio.h>

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
	int			R;
	int			a;
	int			l;
	int			r;
	int			t;
}				t_opt;

typedef	struct	s_ls
{
//	t_list		*filenames;
	t_opt		opt;
}				t_ls;

/*
**	Init
*/

void			ft_ls(const char *str);

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

t_list			*ls_parser(int ac, char **av, t_ls *ls);
//void			get_files(int ac, char **av,t_ls *ls);

/*
**	Errors
*/

/*
**	Display
*/

void			usage(void);
void			print_struct(t_ls option);
void			print_lst(t_list *args);

/*
**	Tools
*/

void	ft_free_list(t_list *list);

#endif
