/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 08:37:29 by arsciand          #+#    #+#             */
/*   Updated: 2019/03/22 14:38:01 by arsciand         ###   ########.fr       */
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
# include <errno.h>

# define VARS_DB ((t_ls*)(vars->content))
# define HALF_A ((t_ls*)(half_a->content))
# define HALF_B ((t_ls*)(half_b->content))
# define TMP_DB ((t_ls*)(tmp->content))
# define DIRS_DB ((t_ls*)(dirs->content))
# define DIR_C_DB ((t_ls*)(dir_content->content))
# define MAX 16384

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
	int			m_link_p;
}				t_pad;

typedef	struct	s_opt
{
	int			big_r;
	int			a;
	int			l;
	int			r;
	int			t;
	int			check_files;
	int			no_d;
	int			no_n;
	int			lstat_first_arg;
	int			empty;
	int			failed;
}				t_opt;

typedef	struct	s_ls
{
	char		*var;
	char		*perms;
	char		*uid;
	char		*gid;
	char		*mtime;
	char		*size_mm;
	char		*link_path;
	int			links;
	int			block;
	int			size;
	int			uid_p;
	int			gid_p;
	int			size_mm_p;
	int			link_p;
	int			time_digit;
	int			n_dirs;
	int			stop;
	char		type;
}				t_ls;

/*
**	Core
*/

t_list			*get_vars(int ac, char **av, t_opt *opt, t_ls *db);
void			sort_vars(t_list **vars, t_opt *opt);
void			process_dirs(t_list *dirs, t_opt *opt, size_t n_dirs);
t_list			*fill_vars_dirs(t_list *vars);
t_list			*fill_vars_files(t_list *vars);
char			*get_dir_path(char *dir_path, char *dir, char *name);
int				get_blocks(t_list *vars);
int				free_vars(t_list *vars);
int				free_lst(t_list *lst);
void			dirs_free(t_list *to_free, t_list *dir_content, t_opt *opt);

/*
**	db
*/

t_ls			*fetch_db(t_ls *db, char *av, char *name);
char			*get_perms(struct stat db_stat);
char			get_type(struct stat d_stat);
char			*get_gid(struct stat db_stat);
char			*get_uid(struct stat db_stat);
char			*get_time(struct stat db_stat);
void			get_pad(t_list *vars, t_pad *pad);
int				get_smmguid_pad(char *guid);
char			*get_minor_pad(char *min);
char			*get_size_mm(t_ls *db, struct stat db_stat, size_t size);
int				get_int_pad(int	i);

/*
**	Display
*/

void			ft_mprintf(int fd, const char *str, ...);
int				buff_fill_int(int arg, char *buff, t_mprintf *s_mpf);
int				buff_fill_char(int arg, char *buff, t_mprintf *s_mpf);
int				buff_fill_str(char *arg, char *buff, t_mprintf *s_mpf);
void			print_files(t_list *vars, t_opt *opt,
					t_pad *pad, size_t n_dirs);

/*
**	error_hanlders
*/

void			print_failed(t_list **vars);
t_list			*failed_opendir(char *var);
t_list			*usage(char *av, int flag);

/*
** dev
*/

void			print_test(t_list *tmp);
void			print_opt(t_opt opt);
void			print_vars_db(t_list *vars);

#endif
