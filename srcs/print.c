/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 01:24:25 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/04 07:28:33 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sudo.h"

void	ft_putchar_color(char c)
{
	int l;

	l = (int)c % 10;
	if (c == '*')
		write(1, _RESET, 5);
	else if (l == 1 || l == 6)
		write(1, _GREEN, 5);
	else if (l == 2 || l == 7)
		write(1, _YELLOW, 5);
	else if (l == 3 || l == 8)
		write(1, _CYAN, 5);
	else if (l == 4 || l == 9)
		write(1, _MAGENTA, 5);
	else if (l == 5 || l == 0)
		write(1, _RED, 5);
	else
		write(1, _BLUE, 5);
	write(1, &c, 1);
	write(1, " ", 1);
	write(1, _RESET, 5);
}

void print_grid(t_sudo *sudo, int grid)
{
	int i;
	int j;

	j = -1;
	while (++j < 9)
	{
		i = -1;
		while (++i < 9)
		{
			ft_putchar_color(sudo->sol[grid][j][i]);
			if (i == 2 || i == 5)
				ft_putstr("| ");
		}
		ft_putstr("\n");
		if (j == 2 || j == 5)
			ft_putstr("- - -   - - -   - - - \n");
	}
}

void print_grids(t_sudo *sudo)
{
	int grid;
	grid = 1;

	while (grid <= 9)
	{
		print_grid(sudo, grid);
		ft_putstr("\n//////////////////////\n");
		grid++;
	}
	print_grid(sudo, 0);
}
