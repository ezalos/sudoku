/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 01:24:40 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/04 07:55:16 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDO_H
# define SUDO_H

# include <stdio.h>
# include "../../libft/libft.h"

# define COLOR

# ifndef COLOR
#  define _RED     ""
#  define _GREEN   ""
#  define _YELLOW  ""
#  define _BLUE    ""
#  define _MAGENTA ""
#  define _CYAN    ""
#  define _RESET   ""
# endif

# ifdef COLOR
#  define _RED     "\x1b[31m"
#  define _GREEN   "\x1b[32m"
#  define _YELLOW  "\x1b[33m"
#  define _BLUE    "\x1b[34m"
#  define _MAGENTA "\x1b[35m"
#  define _CYAN    "\x1b[36m"
#  define _RESET   "\x1b[0m"
# endif

typedef struct			s_sudo
{
	char				***sol;
	int					lin;
	int					col;
	int					grd;
	int					sld;
}						t_sudo;


//SETUP
t_sudo		*read_sudo(char *av);
int			write_ghosts(t_sudo *s);
int			write_ghost(t_sudo *s, int grd);

//SOLVE
void	brain(t_sudo *sudo);

//PRINT
void	ft_putchar_color(char c);
void 	print_grid(t_sudo *sudo, int grid);
void 	print_grids(t_sudo *sudo);





//SHIT
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

#endif
