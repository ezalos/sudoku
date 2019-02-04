/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 01:24:40 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/04 19:54:48 by ldevelle         ###   ########.fr       */
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
#  define _RED			"\x1b[31m"
#  define _GREEN		"\x1b[32m"
#  define _YELLOW		"\x1b[33m"
#  define _BLUE			"\x1b[34m"
#  define _MAGENTA		"\x1b[35m"
#  define _CYAN			"\x1b[36m"			//need 5 spaces
#  define _RESET		"\x1b[0m"
#  define _BROWN		"\x1b[38;2;238;205;163m" //need 16 spaces
#  define _PINK			"\x1b[38;2;239;100;100m"
#  define _PURPLE		"\x1b[38;2;101;78;163m"
#  define _ORANGE		"\x1b[38;2;155;75;43m"
#  define _TURQUOISE	"\x1b[38;2;68;140;121m"
# endif

typedef struct			s_sudo
{
	char				***sol;
	int					lin;
	int					col;
	int					grd;
	int					sld;
	int					bas;
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
int		rm_star(t_sudo *sudo, int grid);

//LOGIC TOOLS
int 	check_n_line(t_sudo *sudo, int nb, int grid,  int lin);
int 	check_n_column(t_sudo *sudo, int nb, int grid, int col);
int		check_n_square(t_sudo *sudo, int nb, int grid, int lin, int col);
int		check_n(t_sudo *sudo, int nb, int grid, int lin, int col);
int		find_n_in_sqr(t_sudo *sudo, int nb, int grid, int lin, int col);

//SIMPLE STAR
int		clr_strs(t_sudo *sudo);
int		clr_str(t_sudo *sudo, int grid);
int 	delete_aligned_stars(t_sudo *sudo, int grid, int hv, int star, int lin, int col);
int 	check_n_square_hv(t_sudo *sudo, int nb, int grid, int lin, int col);

//SMART TOOLS
int		slv_sqr_str(t_sudo *sudo, int grid);
int		slv_sqr_strs(t_sudo *sudo);
int		slv_pos_strs(t_sudo *sudo);

//DELETE
int		delete_stars_on_point(t_sudo *sudo, int lin, int col);
int		delete_stars_on_lin(t_sudo *sudo, int grid, int lin, int col);
int		delete_stars_on_col(t_sudo *sudo, int grid, int lin, int col);
int		delete_stars(t_sudo *sudo, int grid, int lin, int col);

//PRINT
void	ft_putchar_color(char c);
void 	print_grid(t_sudo *sudo, int grid);
void 	print_grids(t_sudo *sudo);


#endif
