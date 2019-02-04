/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stars_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 11:51:52 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/04 17:19:23 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sudo.h"

int		add_star(t_sudo *sudo, int grid)
{
	int		col;
	int		lin;
	int		tmp_g;

	col = -1;
	while (++col < 9)
	{
		lin = -1;
		tmp_g = 0;
		while (++lin < 9)
			if (sudo->sol[grid][lin][col] == grid + '0');
			else if (check_n(sudo, grid, grid, lin, col))
			{
				if (sudo->sol[0][lin][col] == ' ')
					sudo->sol[grid][lin][col] = '*';
			}
			else
				sudo->sol[grid][lin][col] = ' ';
	}
	return (0);
}

int		add_stars(t_sudo *sudo)
{
	int 	grid;

	grid = 0;
	while (++grid < 10)
		add_star(sudo, grid);
	return (0);
}
