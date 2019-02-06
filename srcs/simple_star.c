/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_star.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 09:23:58 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/06 13:07:27 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sudo.h"

int 	check_n_square_hv(t_sudo *sudo, int nb, int grid, int big_lin, int big_col)
{
	int		sml_lin;
	int		sml_col;
	int		fnd_lin;
	int		fnd_col;
	int		H_zer__V_one;

	fnd_lin = -1;
	fnd_col = -1;
	H_zer__V_one = -1;
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
				if (H_zer__V_one == -1 && (fnd_lin >= 0 || fnd_col >= 0))
				{
					if (fnd_lin != big_lin + sml_lin && fnd_col != big_col + sml_col)
						return (0);//bad
					else
					{
						if (fnd_lin == big_lin + sml_lin && fnd_col != big_col + sml_col)
							H_zer__V_one = 1;
						else if (fnd_col == big_col + sml_col && fnd_lin != big_lin + sml_lin)
							H_zer__V_one = 0;
						else
							return (0);
					}
				}
				if (H_zer__V_one == 1)
				{
					if (fnd_lin != big_lin + sml_lin)
						return (0);
				}
				else if(H_zer__V_one == 0)
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
	//if (H_zer__V_one != -1)
		//printf("grid %d | line = %d | col = %d | HV%d\n", grid, fnd_lin, fnd_col, H_zer__V_one);
	if (H_zer__V_one == 1)
		return (fnd_lin + 1);
	else if (H_zer__V_one == 0)
		return (-1 * (fnd_col + 1));
	else
		return (0);
}

int 	delete_aligned_stars(t_sudo *sudo, int grid, int hv, int star, int lin, int col)
{
	int		big_lin;
	int		sml_lin;
	int		big_col;
	int		sml_col;
	int		delete;

	//printf("grid %d lin %d col %d star %d hv %d\n", grid, lin, col, star, hv);
	delete = 0;
	big_lin = -1;
	while (++big_lin < 3)
	{
		big_col = -1;
		while (++big_col < 3)
		{
			if ((big_lin * 3 != lin && hv == 0) || (big_col * 3 != col && hv == 1))
			{
				sml_lin = -1;
				while (++sml_lin < 3)
				{
					sml_col = -1;
					while (++sml_col < 3)
					{
						//printf("~~~grid %d lin %d col %d\n", grid, sml_lin + (big_lin * 3), sml_col + (big_col * 3), star, hv);
						if (hv == 1)
						{
							if (sudo->sol[grid][star][sml_col + (big_col * 3)] == '*')
							{
								//printf("---grid %d lin %d col %d star %d hv %d\n", grid, lin, col, star, hv);
								sudo->sol[grid][star][sml_col + (big_col * 3)] = ' ';
								delete++;
							}
						}
						else
							if (sudo->sol[grid][sml_lin + (big_lin * 3)][star] == '*')
							{
								sudo->sol[grid][sml_lin + (big_lin * 3)][star] = ' ';
								//printf("---grid %d lin %d col %d star %d hv %d\n", grid, lin, col, star, hv);
								delete++;
							}
					}
				}
			}
		}
	}
	if (delete)
	{
		print_grids(sudo);
		write(1, "\033[u", 3);
		ft_putstr("\t\t\t\t\t\t\t\t\t\t\t");
		write(1, _RED, 5);
		ft_putstr("StarDel\t");
		write(1, _RESET, 5);
		if (hv == 1)
		{
			ft_putchar_color((char)(grid + '0'));
			printf("\tline: %d\n", lin);
		}
		else
		{
			ft_putchar_color((char)(grid + '0'));
			printf("\t\t column: %d\n", lin);
		}
		write(1, "\033[s", 3);
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
				if (star < 0)
					delete_aligned_stars(sudo, grid, 0, (star * -1) - 1, lin * 3, col * 3);
				else
					delete_aligned_stars(sudo, grid, 1, (star) - 1, lin * 3, col * 3);
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
