/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 01:24:25 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/04 01:25:07 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sudo.h"

void ft_print_grid(char array[9][9][10], int grid)
{
	int i;
	int j;

	i = 0;
	j = 0;

	while (j <= 8)
	{
		i = 0;
		while (i <= 8)
		{
			printf("%c ", array[j][i][grid]);
			if (i == 2 || i == 5)
				printf("| ");
			i++;
		}
		printf("\n");
		if (j == 2 || j == 5)
			printf("- - -   - - -   - - - \n" );
		j++;
	}
}

void ft_print_all_grid(char array[9][9][10], int grid)
{

	grid = 0;

	while (grid <= 9)
	{
		ft_print_grid(array, grid);
		printf("\n//////////////////////\n");
		grid++;
	}
}
