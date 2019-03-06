/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 08:37:29 by arsciand          #+#    #+#             */
/*   Updated: 2019/03/06 18:08:54 by arsciand         ###   ########.fr       */
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
# include <pwd.h>
# include <grp.h>
# include <time.h>
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

typedef struct	s_pad
{
	int			m_size_mm_p;
	int			m_uid_p;
	int			m_gid_p;
}				t_pad;

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
	char		*perms;
	char		*uid;
	char		*gid;
	char		*mtime;
	char		*size_mm;
	int			links;
	int			size;
	int			uid_p;
	int			gid_p;
	int			size_mm_p;
	char		type;
}				t_ls;

/*
**	Core
*/

t_list			*get_vars(int ac, char **av, t_opt *opt, t_ls *db);
int				free_vars(t_list *vars);

/*
**	Display
*/

void			ft_mprintf(int fd, const char *str, ...);
int				buff_fill_int(int arg, char *buff, t_mprintf *s_mpf);
int				buff_fill_char(int arg, char *buff, t_mprintf *s_mpf);
int				buff_fill_str(char *arg, char *buff, t_mprintf *s_mpf);
void			print_opt(t_opt opt);
void			print_vars_db(t_list *vars);
t_list			*usage(void);

/*
**	db
*/

t_ls			*fetch_db(t_ls *db, char *av);
char			*get_perms(struct stat db_stat);
char			get_type(struct stat d_stat);
char			*get_gid(struct stat db_stat);
char			*get_uid(struct stat db_stat);
char			*get_time(struct stat db_stat);
void			get_pad(t_list *vars, t_pad *pad);
int				get_smmguid_pad(char *guid);
char			*get_minor_pad(char *min);
char			*get_size_mm(t_ls *db, struct stat db_stat, size_t size);

/*
** dev
*/

void			print_content(t_list *vars, t_opt *opt, t_pad *pad);

#endif
