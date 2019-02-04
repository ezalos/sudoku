/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:52:11 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/04 16:08:20 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sudo.h"

int		delete_stars_on_point(t_sudo *sudo, int lin, int col)
{
	int tmp;

	tmp = 0;
	while (++tmp < 10)
	{
		if (sudo->sol[tmp][lin][col] == '*')
			sudo->sol[tmp][lin][col] = ' ';
	}
	return (0);
}

int		delete_stars_on_lin(t_sudo *sudo, int grid, int lin, int col)
{
	int	c;

	c = -1;
	while (++c < 9)
	{
		if (c != col && sudo->sol[grid][lin][c] == '*')
			sudo->sol[grid][lin][c] = ' ';
	}
	return (0);
}

int		delete_stars_on_col(t_sudo *sudo, int grid, int lin, int col)
{
	int	l;

	l = -1;
	while (++l < 9)
	{
		if (l != lin && sudo->sol[grid][l][col] == '*')
			sudo->sol[grid][l][col] = ' ';
	}
	return (0);
}

int		delete_stars(t_sudo *sudo, int grid, int lin, int col)
{
	delete_stars_on_point(sudo, lin, col);
	delete_stars_on_lin(sudo, grid, lin, col);
	delete_stars_on_col(sudo, grid, lin, col);
	return (0);
}
