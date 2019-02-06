/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 10:49:55 by gtaja             #+#    #+#             */
/*   Updated: 2019/02/06 14:05:50 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <unistd.h>
#include <stdlib.h>

int		ft_addsoluce(int **tab, int *count, char *soluce)
{
	*count = *count + 1;
	if (*count == 1)
		ft_show_tab(tab, soluce);
	else if (*count > 1)
		return (1);
	return (0);
}

int		ft_backtracking(int **tab, int pos, int *count, char *soluce)
{
	int x;
	int y;
	int i;

	if (pos >= 81)
		return (ft_addsoluce(tab, count, soluce));
	x = pos % 9;
	y = pos / 9;
	i = 1;
	if (tab[y][x] > 0)
		return (ft_backtracking(tab, pos + 1, count, soluce));
	while (i <= 9)
	{
		if (ft_can_place(tab, x, y, i))
		{
			tab[y][x] = i;
			if (ft_backtracking(tab, pos + 1, count, soluce))
				return (1);
		}
		i++;
	}
	tab[y][x] = 0;
	return (0);
}

int		ft_free(int **tab)
{
	int i;

	i = 0;
	while (i < 9)
		free(tab[i++]);
	free(tab);
	return (0);
}

int		main(int argc, char **argv)//si grille complete mais fausse : return grille
{
	int		**tab;
	int		count;
	char	*soluce;

	tab = malloc(9 * sizeof(int*));
	count = 0;
	if (argc < 10 || tab == 0 || !ft_fill_tab(tab, argv))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	soluce = malloc(163 * sizeof(char));
	ft_backtracking(tab, 0, &count, soluce);
	if (count != 1 || soluce == 0)
		write(1, "Error\n", 6);
	else
	{
		write(1, soluce, ft_strlen(soluce));
		free(soluce);
	}
	return (ft_free(tab));
}
