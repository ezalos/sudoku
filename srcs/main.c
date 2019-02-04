/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 14:32:09 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/04 08:58:59 by ldevelle         ###   ########.fr       */
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
	brain(sudo);
//	print_grid(sudo, 0);
	return (0);
}
