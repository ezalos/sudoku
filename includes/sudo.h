/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 01:24:40 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/04 12:07:37 by ldevelle         ###   ########.fr       */
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
t_sudo	*read_sudo(char *av);
int		write_ghosts(t_sudo *s);
int		write_ghost(t_sudo *s, int grd);

//SOLVE
int		brain(t_sudo *sudo);
int		new_nb(t_sudo *sudo, int nb, int lin, int col);

//STARS TOOLS
int		add_star(t_sudo *sudo, int grid);
int		add_stars(t_sudo *sudo);

//LOGIC TOOLS
int 	check_n_line(t_sudo *sudo, int nb, int grid,  int lin);
int 	check_n_column(t_sudo *sudo, int nb, int grid, int col);
int		check_n_square(t_sudo *sudo, int nb, int grid, int lin, int col);
int		check_n(t_sudo *sudo, int nb, int grid, int lin, int col);
int		find_n_in_sqr(t_sudo *sudo, int nb, int grid, int lin, int col);

//SIMPLE STAR
int		clr_strs(t_sudo *sudo);
int		clr_str(t_sudo *sudo, int grid);

//SMART TOOLS
int		slv_sqr_str(t_sudo *sudo, int grid);
int		slv_sqr_strs(t_sudo *sudo);
int		slv_pos_strs(t_sudo *sudo);


//PRINT
void	ft_putchar_color(char c);
void 	print_grid(t_sudo *sudo, int grid);
void 	print_grids(t_sudo *sudo);


#endif
