/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 07:29:15 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/04 09:03:14 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sudo.h"

/*
**Check if the line or column contain nb
*/

int 	check_n_column(t_sudo *sudo, int nb, int grid, int col)
{
	int n;

	if (nb < 10)
		nb = nb + '0';
	n = -1;
	while (++n < 9)
		if (sudo->sol[grid][n][col] == nb)
			return (0);
	return (1);
}

int 	check_n_line(t_sudo *sudo, int nb, int grid, int lin)
{
	int n;

	if (nb < 10)
		nb = nb + '0';
	n = -1;
	while (++n < 9)
		if (sudo->sol[grid][lin][n] == nb)
			return (0);
	return (1);
}

int 	check_n_square(t_sudo *sudo, int nb, int grid, int lin, int col)
{
	int		l;
	int		c;

	if (nb < 10)
		nb = nb + '0';
	lin = ((lin / 3) * 3);
	col = ((col / 3) * 3);
	l = -1;
	while (++l < 3)
	{
		c = -1;
		while (++c < 3)
			if (sudo->sol[grid][lin + l][col + c] == nb)
				return (0);
	}
	return (1);
}

int 	check_n(t_sudo *sudo, int nb, int grid, int lin, int col)
{
	if (check_n_column(sudo, nb, grid, col)
		&& check_n_line(sudo, nb, grid, lin)
		&& check_n_square(sudo, nb, grid, lin, col))
		return (1);
	return (0);
}
