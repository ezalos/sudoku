/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 01:28:21 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/04 21:26:43 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sudo.h"

int		new_nb(t_sudo *sudo, int nb, int lin, int col)
{
	if (check_n(sudo, nb, 0, lin, col))
	{
		//printf("grid %d | lin = %d | col = %d\n", nb, lin, col);
		sudo->sol[0][lin][col] = nb + '0';
		sudo->sol[nb][lin][col] = nb + '0';
		sudo->sld++;
		delete_stars(sudo, nb, lin, col);
		print_grids(sudo);
	}
	return (0);
}

int		brain(t_sudo *sudo)
{
	int 	a;
	int		b;
	int		grid;

	write_ghosts(sudo);  //met les numeros dans les ghosts
	add_stars(sudo);  // met les etoiles dansns les ghosts
	print_grids(sudo);
	b = -1;
	a = 2;
	while (a || sudo->sld > b)
	{
		b = sudo->sld;
		grid = 0;
		slv_sqr_strs(sudo);
		slv_pos_strs(sudo);
		//if (a <= 3)
		//	add_stars(sudo);
		if (sudo->sld > b)
			a = 2;
		else
		{
			clr_strs(sudo);
			print_grids(sudo);
			a--;
		}
		if (sudo->sld + sudo->bas == 81)
		{
			printf(_GREEN "VICOTRY\n");
			return (1);
		}
	}
	printf(_RED "FAILURE\n");
	//clr_strs(sudo);
	//print_grids(sudo);
	return (0);
}
