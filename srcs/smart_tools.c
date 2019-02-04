/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 11:48:44 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/04 12:08:05 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sudo.h"

int		slv_sqr_str(t_sudo *sudo, int grid)
{
	int		lin;
	int		col;
	int		res;

	lin = -1;
	while (++lin < 3)
	{
		col = -1;
		while (++col < 3)
		{
			if (1 == (res = check_n_square(sudo, (int)'*', grid, lin * 3, col * 3)))
			{
				res = find_n_in_sqr(sudo, (int)'*', grid, lin * 3, col * 3);
				//printf("\n%d\n\n", res);
				new_nb(sudo, grid, res / 10, res - ((res / 10) * 10));
			}
			//if (grid == 4 && lin == 1 && col == 2)
				//printf("RES : %d\n", res);
		}
	}
	return (0);
}


int		slv_sqr_strs(t_sudo *sudo)
{
	int 	grid;

	grid = 0;
	while (++grid < 10)
		slv_sqr_str(sudo, grid);
	return (0);
}

int		slv_pos_strs(t_sudo *sudo)
{
	int 	grid;
	int		str;
	int		lin;
	int		col;

	lin = -1;
	while (++lin < 9)
	{
		col = -1;
		while (++col < 9)
		{
			if (sudo->sol[0][lin][col] == ' ')
			{
				grid = 0;
				str = 0;
				while (++grid < 10)
				{
					if (sudo->sol[grid][lin][col] >= '1' && sudo->sol[grid][lin][col] <= '9' && str)
						return (0);
					if (sudo->sol[grid][lin][col] >= '1' && sudo->sol[grid][lin][col] <= '9')
						str = grid;
				}
				if (str)
					new_nb(sudo, str, lin, col);
			}
		}
	}
	return (0);
}
