/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 14:32:09 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/04 05:15:48 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sudo.h"

int  main(int argc, char **argv)
{
	char ***array;
	int i;
	int j;
	int grid;

	//ON CHECK L'INPUT

	first_writing_base(array, argv);

	ft_brain(array, grid);

	ft_print_all_grid(array, grid);
}
