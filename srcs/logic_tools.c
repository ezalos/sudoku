/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 07:29:15 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/04 07:42:27 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sudo.h"

/*
**Check if the line or column contain nb
*/

int check_n_columns(t_sudo *sudo, int nb, int i)
{
	int n;

	n = -1;
	while (++n < 9)
		if (sudo->sol[0][n][i] == nb + '0')
			return (0);
	return (1);
}

int check_n_line(t_sudo *sudo, int nb, int j)
{
	int n;

	n = -1;
	while (++n < 9)
		if (sudo->sol[0][j][n] == nb + '0')
			return (0);
	return (1);
}
