/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghost.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 01:35:59 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/04 01:38:59 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sudo.h"

void ft_write_ghost_array(char array[9][9][10])
{
	int i;
	int j;
	int grid;

	i = 0;
	j = 0;
	grid = 1;
	while ( grid <= 9)
	{
		j = 0;
		while (j <= 8)
		{
			i = 0;
			while (i <= 8)
			{
				if (array[j][i][0] == grid + 48)
					array[j][i][grid] = grid + 48;
				else
					array[j][i][grid] = ' ';
				i++;
			}
			j++;
		}
		//		ft_check_square(array, grid);
		grid++;
	}
}

void ft_remplissage_ghost(char array[9][9][10], int sqr[3][3], int y, int x, int grid)
{
	int i;
	int j;

	if (sqr[y][x] == 0)   // PARTIE DE REMPLISSAGE **********
	{
		j = y * 3;
		while (j <= (y * 3) + 2 && j >= y * 3)  // deplacement dans case line
		{
			i = x * 3;
			while (i <= (x * 3) + 2 && i >= x * 3)  // deplacement dans case colonnes
			{
				if (ft_check_line(array, j, grid) == 1 && ft_check_columns(array, i, grid) == 1 && array[j][i][0] == 48)
					array[j][i][grid] = '*';
				i++;
			}
			j++;
		}
	}
}
