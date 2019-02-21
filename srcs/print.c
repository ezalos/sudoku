/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 01:24:25 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/18 18:23:20 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sudo.h"

void	ft_putchar_color(char c)
{
	int l;

	l = (int)c % 10;
	if (c == '*')
		write(1, _BLUE, 5);
	else if (l == 1)
		write(1, _GREEN, 5);
	else if (l == 2)
		write(1, _YELLOW, 5);
	else if (l == 3 )
		write(1, _CYAN, 5);
	else if (l == 4)
		write(1, _MAGENTA, 5);
	else if (l == 5)
		write(1, _RED, 5);
	else if (l == 6)
		write(1, _BROWN, 20);
	else if (l == 7)
		write(1, _PINK, 20);
	else if (l == 8)
		write(1, _PURPLE, 20);
	else if (l == 9)
		write(1, _ORANGE, 18);
	else if (l == 0)
		write(1, _TURQUOISE, 19);
	else
		write(1, _BLUE, 5);
	write(1, &c, 1);
	write(1, " ", 1);
	write(1, _RESET, 5);
}

void print_ghost_grid(t_sudo *sudo, int tri)
{
	int i;
	int j;
	int grid;

	j = -1;
	if (tri == 0)
		ft_putstr("\t");
	while (++j < 9)
	{
		grid = 0;
		while (++grid < 4)
		{
		i = -1;
		while (++i < 9)
		{
				ft_putchar_color(sudo->sol[tri + grid][j][i]);
				if (i == 2 || i == 5)
					ft_putstr("| ");
		}
			if ( grid < 3)
			ft_putstr("  $  ");
		}
		ft_putstr("\n\t");
		if (j == 2 || j == 5)
		{
			ft_putstr("- - -   - - -   - - -   $  - - -   - - -   - - -   $  - - -   - - -   - - - \n\t");
		}
	}
	if (tri < 6)
	{
	ft_putstr("                        $                          $                        \n\t");
	ft_putstr("~~~~~~~~~~~~~~~~~~~~~~~~+~~~~~~~~~~~~~~~~~~~~~~~~~~+~~~~~~~~~~~~~~~~~~~~~~~~\n\t");
	ft_putstr("                        $                          $                        \n\t");
	}
	else
		ft_putstr("\n\n\n\t");
}

void print_grid(t_sudo *sudo, int grid)
{
	int i;
	int j;

	j = -1;
	while (++j < 9)
	{
		i = -1;
		ft_putstr("                           ");
		while (++i < 9)
		{
			ft_putchar_color(sudo->sol[grid][j][i]);
			if (i == 2 || i == 5)
				ft_putstr("| ");
		}
		ft_putstr("\n\t");
		if (j == 2 || j == 5)
		{
			ft_putstr("                           ");
			ft_putstr("- - -   - - -   - - - \n\t");
		}
	}
}

void wait_pls(void)
{
	long long wait;

	wait = 100000000;
	wait /= 3;
	while(--wait);
	//printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

void print_grids(t_sudo *sudo)
{
	int grid;
	int tri;

	write(1, "\033[0;0H", 6); //top left corner pointer
	//wait_pls();
	//printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\t");
	tri = 0;
	grid = 0;
	while (tri < 9)
	{
		print_ghost_grid(sudo, tri);
		tri += 3;
	}
	print_grid(sudo, 0);
	printf("\n\t\t\t      NOMBRE DE NOMBRE TROUVES : " _GREEN "%d"_RESET" / " _RED "%d\n" _RESET, sudo->sld, 81 - sudo->bas);
}
