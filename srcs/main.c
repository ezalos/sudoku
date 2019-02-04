/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 14:32:09 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/04 07:48:15 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sudo.h"

int  main(int ac, char **av)
{
	t_sudo	*sudo;

	if (ac != 2)
		return (0);
	if (!(sudo = read_sudo(av[1])))
		return (-1);
	int i = -1;
	while (++i < 9)
		printf("%s\n", sudo->sol[0][i]);
	brain(sudo);
	print_grids(sudo);
	return (0);
}
