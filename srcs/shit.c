/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 05:44:01 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/04 05:44:12 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sudo.h"

int ft_check_columns(char ***array, int i, int grid)
{
	int n;

	n = 0;
	while (array[n][i][0] != grid + 48 && n < 9)
		n++;
	//	printf("Check columns = %d", n);
	if (n == 9)
		return (1);
	else
		return (0);
}

int ft_check_line(char ***array, int j, int grid)
{
	int n;

	n = 0;
	while (array[j][n][0] != grid + 48 && n < 9)
		n++;
	//	printf("Check lines = %d", n);
	if (n == 9)
		return (1);
	else
		return (0);
}


void ft_remplissage_base(char ***array, int sqr[3][3], int y, int x, int grid)
{
	int i;
	int j;


	j = y * 3;
	while (j <= (y * 3) + 2 && j >= y * 3)  // deplacement dans case line
	{
		i = x * 3;
		while (i <= (x * 3) + 2 && i >= x * 3)  // deplacement dans case colonnes
		{
			if (array[j][i][grid] == '*')
			{
				//				printf("y %d x : %d j : %d i : %d grid : %d\n", y, x, j, i, grid);
			if (ft_check_line(array, j, grid) == 1 && ft_check_columns(array, i, grid) == 1 && array[j][i][0] == 48)
			{
				array[j][i][grid] = grid + 48;
				array[j][i][0] = grid + 48;
			}
			}
			i++;
		}
		j++;
	}
}

void ft_check_square(char ***array, int grid)
{
	int j;
	int i;
	int x;
	int y;
	int o;
	int sqr[3][3] = {0,0,0,0,0,0,0,0,0};

	j = 0;
	i = 0;
	x = 0;
	y = 0;
	o = 0;
	while (y <= 2)  // bloc de case lignes
	{
		x = 0;
		while ( x <= 2)  // bloc de case colonnes
		{
			j = y * 3;
			while (j <= (y * 3) + 2 && j >= y * 3)  // deplacement dans case line
			{
				i = x * 3;
				while (i <= (x * 3) + 2 && i >= x * 3)  // deplacement dans case colonnes
				{
					if (array[j][i][grid] == grid + 48)
						sqr[y][x]++;		//Determine quelle case possede deja le nombre grid
					i++;
				}
				j++;
			}
			ft_remplissage_ghost(array, sqr, y, x, grid);
			x++;
		}
		y++;
	}
}

void ft_check_star(char ***array, int grid)
{
	int j;
	int i;
	int x;
	int y;
	int sqr[3][3] = {0,0,0,0,0,0,0,0,0};

	j = 0;
	i = 0;
	x = 0;
	y = 0;
	while (y <= 2)  // bloc de case lignes
	{
		x = 0;
		while ( x <= 2)  // bloc de case colonnes
		{
			j = y * 3;
			while (j <= (y * 3) + 2 && j >= y * 3)  // deplacement dans case line
			{
				i = x * 3;
				while (i <= (x * 3) + 2 && i >= x * 3)  // deplacement dans case colonnes
				{
					if (array[j][i][grid] == '*')
						sqr[y][x]++;		//Determine quelle case possede deja le nombre grid
					i++;
				}
				j++;
			}
			//			printf("Y a t'il un sqr[y][x] = %d ? %d \n", grid, sqr[y][x]);
			if (sqr[y][x] == 1)
				ft_remplissage_base(array, sqr, y, x, grid);
			x++;
		}
		y++;
	}
}

void ft_check_star_all_grids(char ***array, int j, int i)
{
	int grid;

	grid = 1;
	while (grid <= 9)
	{
		if (array[j][i][grid] == '*')
		{
			//			array[j][i][grid] = grid + 48;
			array[j][i][0] = grid + 48;		//Determine quelle case possede deja le nombre grid
		}
		grid++;
	}
}

void ft_check_all_grids(char ***array)
{
	int i;
	int j;
	int o;
	int grid;

	i = 0;
	j = 0;
	o = 0;
	grid = 1;
	while (j <= 8)
	{
		i = 0;
		while (i <= 8)
		{
			while (grid <= 9)
			{
				if (array[j][i][grid] == '*')
					o++;
				grid++;
			}
			if (o == 1)
				ft_check_star_all_grids(array, j, i);
			o = 0;
			grid = 1;
			i++;
		}
		j++;
	}
}

void ft_simplification_star3h(char ***array, int aire, int droite, int grid)
{
	int i;

	i = 0;
	while (i <= 8)
	{
		if ( i / 3 != aire)
			array[droite][i][grid] = ' ';
		i++;
	}
	printf("\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	ft_print_grid(array, grid);
	printf("\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
}

void ft_simplification_star3v(char ***array, int aire, int droite, int grid)
{
	int i;

	i = 0;
	while (i <= 8)
	{
		if ( i / 3 != aire)
			array[i][droite][grid] = ' ';
		i++;
	}
	printf("\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	ft_print_grid(array, grid);
	printf("\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
}

void ft_simplification_star2(char ***array, int sqr[3][3], int y, int x, int grid)
{
	int i;
	int j;
	int str[3][2];
	int n;

	n = 0;
	j = y * 3;
	while (j <= (y * 3) + 2 && j >= y * 3)  // deplacement dans case line
	{
		i = x * 3;
		while (i <= (x * 3) + 2 && i >= x * 3)  // deplacement dans case colonnes
		{
			if (array[j][i][grid] == '*')
			{
				str[n][0]=j;
				str[n][1]=i;
				n++;
			}
			i++;
		}
		j++;
	}
	if (str[1][0] == str[2][0] == str[0][0] && n == 3)
			{
				ft_simplification_star3h(array, x, str[0][0], grid);
			}
			else if (str[1][0] == str[0][0] && n == 2)
			{
				ft_simplification_star3h(array, x, str[0][0], grid);
			}
//			else if (n == 1)

			if (str[1][1] == str[2][1] == str[0][1] && n ==3)
			{
				ft_simplification_star3v(array, y, str[0][1], grid);
			}
			else if (str[1][1] == str[0][1] && n == 2)
			{
				ft_simplification_star3v(array, y, str[0][1], grid);
			}
}


void ft_simplification_star(char ***array, int grid)
{
	int j;
	int i;
	int x;
	int y;
	int sqr[3][3] = {0,0,0,0,0,0,0,0,0};

	j = 0;
	i = 0;
	x = 0;
	y = 0;
	while (y <= 2)  // bloc de case lignes
	{
		x = 0;
		while ( x <= 2)  // bloc de case colonnes
		{
			j = y * 3;
			while (j <= (y * 3) + 2 && j >= y * 3)  // deplacement dans case line
			{
				i = x * 3;
				while (i <= (x * 3) + 2 && i >= x * 3)  // deplacement dans case colonnes
				{
					if (array[j][i][grid] == '*')
						sqr[y][x]++;		//Determine quelle case possede deja le nombre grid
					i++;
				}
				j++;
			}
			if (sqr[y][x] <= 3 && sqr[y][x] > 0)
				ft_simplification_star2(array, sqr, y, x, grid);
			x++;
		}
		y++;
	}
}

int compteur(char ***array)
{
	int o;
	int i;
	int j;

	o = 0;
	i = 0;
	j = 0;
	while (j <= 8)

	{
		i = 0;
		while (i <= 8)
		{
			if (array[j][i][0] != '0')
				o++;
			i++;
		}
		j++;
	}
	return (o);
}
