/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 01:28:21 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/04 07:57:37 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sudo.h"

void	brain(t_sudo *sudo)
{
	int b;
	int grid;

	b = -1;
	while (sudo->sld > b)
	{
		b = sudo->sld;
		write_ghosts(sudo);  //met les numeros dans les ghosts
		grid = 0;
//		while (++grid <= 9)
//			ft_check_square(array, grid);  // met les etoiles dansns les ghosts
		print_grids(sudo);
		grid = 0;
//		while (++grid <= 9)
//			ft_simplification_star(array, grid);  //simplifie les etoiles alignees

		grid = 0;
//		while (++grid <= 9)
		{
//			ft_check_star(array, grid);   //resoud les etoiles seule dans carres
//			ft_check_all_grids(array);  //resoud les etoiles seules sur position
		}
		printf("NOMBRE DE NOMBRE TROUVES : %d\n", b);
//		print_grids(sudo);
	}
}
