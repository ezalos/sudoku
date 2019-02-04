/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stars_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 11:51:52 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/04 11:53:38 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sudo.h"

int		add_star(t_sudo *sudo, int grid)
{
	int		col;
	int		lin;

	col = -1;
	while (++col < 9)
	{
		lin = -1;
		while (++lin < 9)
			if (sudo->sol[grid][lin][col] == grid + '0');
			else if (check_n(sudo, grid, grid, lin, col))
				sudo->sol[grid][lin][col] = '*';
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
