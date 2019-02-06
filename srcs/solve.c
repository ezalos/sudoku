/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 01:28:21 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/06 18:42:07 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sudo.h"

int		new_nb(t_sudo *sudo, int nb, int lin, int col)
{
	char pause;

	if (check_n(sudo, nb, 0, lin, col))
	{
		//printf("grid %d | lin = %d | col = %d\n", nb, lin, col);
		sudo->sol[0][lin][col] = nb + '0';
		sudo->sol[nb][lin][col] = nb + '0';
		sudo->sld++;
		delete_stars(sudo, nb, lin, col);
		if (ONPTION)
		{
			if (sudo->sld != 1)
				write(1, "\033[u", 3);
			else
				write(1, "\033[0;0H", 6); //top left corner pointer
			ft_putstr("\t\t\t\t\t\t\t\t\t\t\t");
			write(1, _GREEN, 5);
			ft_putstr("New\t");
			write(1, _RESET, 5);
			ft_putchar_color((char)(nb + '0'));
			printf("\tline: %d\t column: %d\n", lin, col);
			write(1, "\033[s", 3);
			//scanf("%c", &pause);
			print_grids(sudo);
		}
	}
	return (0);
}

/*
**	Note:	With less than 17 squares filled in or less than 8 different digits
**			it is known that there will be duplicate solutions.
*/

int		brain(t_sudo *sudo)
{
	int 	a;
	int		b;
	int		grid;

	write_ghosts(sudo);  //met les numeros dans les ghosts
	add_stars(sudo);  // met les etoiles dansns les ghosts
	if (ONPTION)
		print_grids(sudo);
	b = -1;
	a = 2;
	while (a || sudo->sld > b)
	{
		b = sudo->sld;
		grid = 0;
		slv_sqr_strs(sudo); //lonely star in her square is solved
		slv_pos_strs(sudo); //only star in her position by comparing with all other layers
		if (sudo->sld > b)
			a = 2;
		else
		{
			clr_strs(sudo); //get rid of stars that are aligned
			a--;
		}
		if (sudo->sld + sudo->bas == 81)
			return (1);
	}
	return (0);
}
