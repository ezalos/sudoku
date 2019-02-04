/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 01:28:21 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/04 08:32:36 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sudo.h"

/*
int		new_nb(t_sudo *sudo, int nb, int lin, int col)
{

}
*/

int		add_star_grid(t_sudo *sudo, int grid)
{
	int col;
	int lin;

	col = -1;
	while (++col < 9)
	{
		lin = -1;
		while (++lin < 9)
			if (check_n(sudo, grid, grid, lin, col))
				sudo->sol[grid][lin][col] = '*';
	}
	return (0);
}

int		add_star(t_sudo *sudo)
{
	int grid;

	grid = 0;
	while (++grid < 10)
		add_star_grid(sudo, grid);
	return (0);
}

int		brain(t_sudo *sudo)
{
	int b;
	int grid;

	write_ghosts(sudo);  //met les numeros dans les ghosts
	b = -1;
	while (sudo->sld > b)
	{
		b = sudo->sld;
		grid = 0;
		add_star(sudo);  // met les etoiles dansns les ghosts
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
	return (0);
}
