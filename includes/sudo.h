/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 01:24:40 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/04 05:14:16 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDO_H
# define SUDO_H

# include <stdio.h>

int ft_check_columns(char ***array, int i, int grid);
int ft_check_line(char ***array, int j, int grid);
void ft_remplissage_base(char ***array, int sqr[3][3], int y, int x, int grid);
void ft_check_square(char ***array, int grid);
void ft_check_star(char ***array, int grid);
void ft_check_star_all_grids(char ***array, int j, int i);
void ft_check_all_grids(char ***array);
void ft_simplification_star3h(char ***array, int aire, int droite, int grid);
void ft_simplification_star3v(char ***array, int aire, int droite, int grid);
void ft_simplification_star2(char ***array, int sqr[3][3], int y, int x, int grid);
void ft_simplification_star(char ***array, int grid);
int compteur(char ***array);

//GHOST
void ft_write_ghost_array(char ***array);
void ft_remplissage_ghost(char ***array, int sqr[3][3], int y, int x, int grid);

//SETUP
void first_writing_base(char ***array, char **argv);

//SOLVE
void ft_brain(char ***array, int grid);

//PRINT
void ft_print_grid(char ***array, int grid);
void ft_print_all_grid(char ***array, int grid);

#endif
