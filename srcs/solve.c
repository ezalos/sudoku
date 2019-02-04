/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 01:28:21 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/04 16:04:39 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sudo.h"

int		new_nb(t_sudo *sudo, int nb, int lin, int col)
{

	printf("grid %d | lin = %d | col = %d\n", nb, lin, col);
	sudo->sol[0][lin][col] = nb + '0';
	sudo->sol[nb][lin][col] = nb + '0';
	sudo->sld++;
	delete_stars(sudo, nb, lin, col);
	return (0);
}

int		brain(t_sudo *sudo)
{
	int		b;
	int		grid;

	write_ghosts(sudo);  //met les numeros dans les ghosts
	add_stars(sudo);  // met les etoiles dansns les ghosts
	b = -1;
	while (sudo->sld > b)
	{
		b = sudo->sld;
		grid = 0;
		slv_sqr_strs(sudo);
		slv_pos_strs(sudo);
		clr_strs(sudo);
		print_grids(sudo);
		printf("\t\tNOMBRE DE NOMBRE TROUVES : %d\n", sudo->sld);
	}
	return (0);
}
