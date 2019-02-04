/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_star.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 09:23:58 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/04 17:57:36 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sudo.h"

int 	check_n_square_hv(t_sudo *sudo, int nb, int grid, int big_lin, int big_col)
{
	int		sml_lin;
	int		sml_col;
	int		fnd_lin;
	int		fnd_col;
	int		hv;

	fnd_lin = -1;
	fnd_col = -1;
	hv = -1;
	if (nb < 10)
		nb = nb + '0';
	big_lin = ((big_lin / 3) * 3);
	big_col = ((big_col / 3) * 3);
	sml_lin = -1;
	while (++sml_lin < 3)
	{
		sml_col = -1;
		while (++sml_col < 3)
			if (sudo->sol[grid][big_lin + sml_lin][big_col + sml_col] == nb)
			{
				if (hv == -1 && (fnd_lin >= 0 || fnd_col >= 0))
				{
					if (fnd_lin != big_lin + sml_lin || fnd_col != big_col + sml_col)
						return (0);//bad
					else
					{
						if (fnd_lin == big_lin + sml_lin)
							hv = 0;
						else if (fnd_col != big_col + sml_col)
							hv = 1;
					}
				}
				if (hv == 1)
				{
					if (fnd_lin != big_lin + sml_lin)
						return (0);
				}
				else if(hv == 0)
				{
					if (fnd_col != big_col + sml_col)
						return (0);
				}
				if (fnd_lin == -1 || fnd_col == -1)
				{
					fnd_lin = big_lin + sml_lin;
					fnd_col = big_col + sml_col;
				}
			}
	}
	if (hv == 0)
		return (fnd_lin + 1);
	else
		return (-1 * (fnd_col + 1));
}

int 	delete_aligned_stars(t_sudo *sudo, int grid, int hv, int star, int lin, int col)
{
	int		l;
	int		l_;
	int		c;
	int		c_;

	lin = ((lin / 3) * 3);
	col = ((col / 3) * 3);
	l = -1;
	while (++l < 3)
	{
		c = -1;
		while (++c < 3)
		{
			if (l != lin || c != col)
			{
				l_ = -1;
				while (++l_ < 3)
				{
					c_ = -1;
					while (++c_ < 3)
					{
						if (sudo->sol[grid][l_ + l][c_ + c] == '*')
							sudo->sol[grid][l_ + l][c_ + c] = ' ';
					}
				}
			}
		}
	}
	return (0);
}

int		clr_str(t_sudo *sudo, int grid)
{
	int		star;
	int		lin;
	int		col;

	lin = -1;
	while (++lin < 3)
	{
		col = -1;
		while (++col < 3)
		{
			star = check_n_square_hv(sudo, '*', grid, lin * 3, col * 3);
			if (star)
			{
				//printf("grid : %d | *** : %d | lin : %d | col : %d\n", grid, star, lin, col);
				if (star > 0)
					delete_aligned_stars(sudo, grid, 0, star - 1, lin, col);
				else
					delete_aligned_stars(sudo, grid, 1, (star * -1) - 1, lin, col);
			}
		}
	}

	return (0);
}

int		clr_strs(t_sudo *sudo)
{
	int		grid;

	grid = 0;
	while (++grid < 10)
		clr_str(sudo, grid);
	return (0);
}
