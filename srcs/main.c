/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 08:39:15 by arsciand          #+#    #+#             */
/*   Updated: 2019/02/22 09:02:39 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(void)
{
	int d = 123;
	int c = '\t';
	int cc = 32;
	char *null = NULL;
	ft_ls_test();
	/*
	**
	*/
	dprintf(1, "TEST INT REAL |%d|  |%d|", d, d);
	ft_putchar('\n');
	mprintf(1, "TEST INT MINI |%d|  |%d|", d, d);
	ft_putchar('\n');
	/*
	**
	*/
	dprintf(1, "TEST CHAR REAL |%c|  |%c|", cc, c);
	ft_putchar('\n');
	mprintf(1, "TEST CHAR MINI |%c|  |%c|", cc, c);
	ft_putchar('\n');
	/*
	**
	*/
	dprintf(1, "TEST STRING REAL |%s|\\  |%s|\t", null, "\\Test kappa\t");
	ft_putchar('\n');
	mprintf(1, "TEST STRING MINI |%s|\\  |%s|\t", null, "\\Test Kappa\t");
	ft_putchar('\n');
	/*
	**
	*/
	dprintf(1, "%*.*s", 5, 1, "123456");
	ft_putchar('\n');
	mprintf(1, "%.*s", 2, "126666");
	ft_putchar('\n');
	return (0);
}
