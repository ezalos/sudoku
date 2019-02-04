/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 01:28:21 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/04 02:08:42 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sudo.h"

void ft_brain(char array[9][9][10], int grid)
{
	int b;
	while (compteur(array) != b)
	{
	b = compteur(array);
		grid = 1;
		printf("\n\n1");

		ft_write_ghost_array(array);  //met les numeros dans les ghosts
		while (grid <= 9)
		{
			printf("2");
//			ft_check_square(array, grid);  // met les etoiles dansns les ghosts
			printf("3");
		grid++;
		}
		grid = 1;
		while (grid <= 9)
		{
//			ft_simplification_star(array, grid);  //simplifie les etoiles alignees
			printf("444");
			grid++;
		}
		printf("5");

		grid = 1;
		while (grid <= 9)
		{
			printf("6");

//			ft_check_star(array, grid);   //resoud les etoiles seule dans carres
			printf("7");

//			ft_check_all_grids(array);  //resoud les etoiles seules sur position
			grid++;
		}
		printf("8\n\n");
		printf("NOMBRE DE NOMBRE TROUVES : %d\n", b);
//		ft_print_all_grid(array, grid);
	}
}
