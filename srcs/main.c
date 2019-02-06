/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 14:32:09 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/06 19:54:14 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sudo.h"

int  main(int ac, char **av)
{
	t_sudo	*sudo;
	int		r_val;
	int		i;

	if (ac != 2)
		return (0);
	if (ONPTION)
		write(1, "\033[2J", 4);//clear screen
	if (!(sudo = read_sudo(av[1])))
		return (-1);
	r_val = brain(sudo);
	if (ONPTION)
	{
		print_grids(sudo);
		write(1, "\033[75;0H", 7);
		if (r_val == 1)
			printf(_GREEN "VICTORY\n" _RESET);
		else
			printf(_RED "FAILURE\n" _RESET);
		printf("File was %s\n", ONPTION, av[1]);
	}
	else
	{
		i = -1;
		while (++i < 9)
			printf("%s\n", sudo->sol[0][i]);
	}
	return (0);
}
