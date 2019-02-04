/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 01:24:40 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/04 02:04:00 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDO_H
# define SUDO_H

# include <stdio.h>

int ft_check_columns(char array[9][9][10], int i, int grid);
int ft_check_line(char array[9][9][10], int j, int grid);
void ft_remplissage_base(char array[9][9][10], int sqr[3][3], int y, int x, int grid);
void ft_check_square(char array[9][9][10], int grid);
void ft_check_star(char array[9][9][10], int grid);
void ft_check_star_all_grids(char array[9][9][10], int j, int i);
void ft_check_all_grids(char array[9][9][10]);
void ft_simplification_star3h(char array[9][9][10], int aire, int droite, int grid);
void ft_simplification_star3v(char array[9][9][10], int aire, int droite, int grid);
void ft_simplification_star2(char array[9][9][10], int sqr[3][3], int y, int x, int grid);
void ft_simplification_star(char array[9][9][10], int grid);
int compteur(char array[9][9][10]);

//GHOST
void ft_write_ghost_array(char array[9][9][10]);
void ft_remplissage_ghost(char array[9][9][10], int sqr[3][3], int y, int x, int grid);

//SETUP
void first_writing_base(char array[9][9][10], char **argv);

//SOLVE
void ft_brain(char array[9][9][10], int grid);

//PRINT
void ft_print_grid(char array[9][9][10], int grid);
void ft_print_all_grid(char array[9][9][10], int grid);

#endif
