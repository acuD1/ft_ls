/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 08:37:29 by arsciand          #+#    #+#             */
/*   Updated: 2019/04/03 12:49:56 by arsciand         ###   ########.fr       */
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
# include <sys/ioctl.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <sys/acl.h>

# define VARS_DB ((t_ls*)(vars->content))
# define HALF_A ((t_ls*)(half_a->content))
# define HALF_B ((t_ls*)(half_b->content))
# define TMP_DB ((t_ls*)(tmp->content))
# define DIRS_DB ((t_ls*)(dirs->content))
# define DIR_C_DB ((t_ls*)(dir_content->content))
# define XATTR ((t_xattr*)((t_ls*)vars->content)->xattr)
# define XATTR_DB ((t_xattr*)(db->xattr))
# define MAX 16384
# define CLR "\x1B[0m"
# define RED "\x1B[31m"
# define MAG "\x1B[35m"
# define CYA "\x1B[1m\x1B[36m"
# define YEL "\x1B[33m"
# define FRED "\x1B[41m\x1B[30m"
# define FYEL "\x1B[43m\x1B[34m"
# define FBLU "\x1B[46m\x1B[34m"
# define FBLUB "\x1B[46m\x1B[30m"
# define FGRE "\x1B[42m\x1B[30m"
# define NFRED "\x1B[3m\x1B[31m"
# define NFYEL "\x1B[3m\x1B[33m"
# define NFBLU "\x1B[3m\x1B[34m"
# define NFBLUB "\x1B[3m\x1B[96m"
# define NFGRE "\x1B[3m\x1B[32m"

typedef struct		s_mprintf
{
	int				pad;
	int				indent;
	int				width;
	int				neg;
	int				diff;
	int				space;
}					t_mprintf;

typedef	struct		s_opt
{
	int				xattr;
	int				e;
	int				big_r;
	int				a;
	int				l;
	int				r;
	int				t;
	int				one;
	int				size;
	int				s;
	int				check_files;
	int				no_d;
	int				no_n;
	int				not_found;
	int				empty;
	int				failed;
	int				no_args;
	int				arg;
	int				width;
	int				reset;
}					t_opt;

typedef struct		s_pad
{
	int				m_size_mm_p;
	int				m_uid_p;
	int				m_gid_p;
	int				m_link_p;
	int				m_normal_p;
	int				m_xattr_p;
	int				m_val_p;
	int				m_block_p;
	int				tmp_size_mm_p;
	int				tmp_uid_p;
	int				tmp_gid_p;
	int				tmp_link_p;
	int				tmp_normal_p;
	int				tmp_xattr_p;
	int				tmp_val_p;
	int				tmp_block_p;
}					t_pad;

typedef struct		s_xattr
{
	char			*xattr;
	int				size;
	int				val;
	char			tmp[MAX];
}					t_xattr;

typedef	struct		s_ls
{
	struct s_xattr	*xattr;
	struct stat		db_stat;
	acl_t			acl;
	char			**acl_tab;
	char			*av;
	char			*var;
	char			*chmod;
	char			*uid;
	char			*gid;
	char			*mtime;
	char			*size_mm;
	char			*link_path;
	char			*color;
	int				links;
	int				block;
	int				size;
	int				time_digit;
	int				n_dirs;
	int				stop;
	int				no_print;
	int				no_link;
	int				uid_p;
	int				gid_p;
	int				size_mm_p;
	int				normal_p;
	int				link_p;
	int				xattr_p;
	int				val_p;
	int				block_p;
	char			type;
}					t_ls;

/*
**	Core
*/

t_list				*get_vars(int ac, char **av, t_opt *opt, t_ls *db);
void				sort_vars(t_list **vars, t_opt *opt);
void				process_dirs(t_list *dirs, t_opt *opt, size_t n_dirs);
t_list				*fill_vars_dirs(t_list *vars, t_opt *opt);
t_list				*fill_vars_files(t_list *vars, t_opt *opt);
char				*get_dir_path(char *dir_path, char *dir, char *name);
int					get_blocks(t_list *vars);
int					free_vars(t_list *vars);
int					free_lst(t_list *lst);
void				get_output(t_list **vars, t_opt *opt, t_pad *pad);
void				dirs_free(t_list *to_free, t_list *dir_content, t_opt *opt);

/*
**	db
*/

t_ls				*fetch_db(t_ls *db, char *av, char *name, t_opt *opt);
char				*get_chmod(t_ls *db, struct stat db_stat, char *av);
char				get_type(struct stat d_stat);
char				*get_gid(struct stat db_stat);
char				*get_uid(struct stat db_stat);
char				*get_time(struct stat db_stat);
void				get_pad(t_list *vars, t_pad *pad);
int					get_string_pad(char *guid);
char				*get_minor_pad(char *min);
char				*get_size_mm(t_ls *db, struct stat db_stat, size_t size);
int					get_int_pad(int	i);
char				*get_link(char *var, t_ls *db);
char				*get_colors(char type, char *perms, t_opt *opt);
void				get_xattr(t_ls *db, char *av);
void				get_acl(t_ls *db);

/*
**	Display
*/

void				ft_mprintf(int fd, const char *str, ...);
int					buff_fill_int(int arg, char *buff, t_mprintf *s_mpf);
int					buff_fill_char(int arg, char *buff, t_mprintf *s_mpf);
int					buff_fill_str(char *arg, char *buff, t_mprintf *s_mpf);
void				print_files(t_list *vars, t_opt *opt,
						t_pad *pad, size_t n_dirs);
void				get_output_width(t_opt *opt);

/*
**	error_handlers
*/

void				print_failed(t_list **vars, t_opt *opt);
t_list				*failed_opendir(char *var, t_opt *opt);
t_list				*usage(char *av, int flag, int i);

#endif
