/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 13:15:00 by arsciand          #+#    #+#             */
/*   Updated: 2019/03/24 13:16:29 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_colors(char type, char *perms, t_opt *opt)
{
	if (type == '-' && (perms[9] == 't' || perms[9] == 'T'))
		return (opt->l ? FRED : NFRED);
	else if (type == '-' && (perms[3] == 's'
			|| perms[6] == 's') && perms[9] == 'x')
		return (opt->l ? FRED : NFRED);
	else if ((perms[3] == 's' || perms[6] == 's') && perms[9] != 'x')
		return (opt->l ? FBLUB : NFBLUB);
	else if (type == '-' && (perms[3] == 'x'
			|| perms[6] == 'x' || perms[9] == 'x'))
		return (RED);
	else if (type == 'd' && perms[9] == 't')
		return (opt->l ? FGRE : NFGRE);
	else if (type == 'd')
		return (CYA);
	else if (type == 'l')
		return (MAG);
	else if (type == 'c')
		return (opt->l ? FYEL : NFYEL);
	else if (type == 'b')
		return (opt->l ? FBLU : NFBLU);
	else if (type == 'p')
		return (YEL);
	else
		return (CLR);
}
