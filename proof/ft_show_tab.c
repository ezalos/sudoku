/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 11:54:49 by gtaja             #+#    #+#             */
/*   Updated: 2018/09/08 11:54:50 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

void	ft_show_tab(int **tab, char *result)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (j > 0)
				result[k++] = ' ';
			result[k++] = tab[i][j] + '0';
			j++;
		}
		result[k++] = '\n';
		i++;
	}
	result[k++] = '\0';
}
