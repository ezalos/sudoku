/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 01:27:41 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/04 05:14:30 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sudo.h"

void first_writing_base(char ***array, char **argv)
{
	int i;
	int j;
	int grid;

	i = 0;
	j = 0;
	grid = 0;
	while (j <= 8)
	{
		i = 0;
		while (i <= 8)
		{
			if (*(argv[j + 1]+i) == 46)
				*(argv[j + 1]+i) = 48;
			array[j][i][grid] = *((argv[j + 1])+i);
			i++;
		}
		j++;
	}
}
