/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 11:53:54 by gtaja             #+#    #+#             */
/*   Updated: 2018/09/08 11:53:55 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

int		ft_free_memory(int **tab, int len)
{
	int i;

	i = 0;
	while (i < len)
		free(tab[i++]);
	free(tab);
	return (0);
}

int		ft_fill_tab(int **tab, char **argv)
{
	int i;
	int j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		if (ft_strlen(argv[1 + i]) != 9)
			return (ft_free_memory(tab, i));
		tab[i] = malloc(9 * sizeof(int));
		if (tab[i] == 0)
			return (ft_free_memory(tab, i));
		while (j < 9)
		{
			if (argv[i + 1][j] >= '1' && argv[i + 1][j] <= '9')
				tab[i][j] = argv[i + 1][j] - '0';
			else if (argv[i + 1][j] == '.')
				tab[i][j] = 0;
			else
				return (ft_free_memory(tab, i + 1));
			j++;
		}
		i++;
	}
	return (1);
}
