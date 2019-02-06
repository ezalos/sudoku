/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sudoku.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 12:33:11 by gtaja             #+#    #+#             */
/*   Updated: 2018/09/08 12:33:14 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_check_row(int **tab, int y, int no)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (tab[y][i] == no)
			return (0);
		i++;
	}
	return (1);
}

int		ft_check_column(int **tab, int x, int no)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (tab[i][x] == no)
			return (0);
		i++;
	}
	return (1);
}

int		ft_check_block(int **tab, int x, int y, int no)
{
	int i;
	int j;
	int end_x;
	int end_y;

	i = (x / 3) * 3;
	end_x = i + 3;
	while (i < end_x)
	{
		j = (y / 3) * 3;
		end_y = j + 3;
		while (j < end_y)
		{
			if (tab[j][i] == no)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_can_place(int **tab, int x, int y, int no)
{
	return (ft_check_row(tab, y, no) &&
			ft_check_column(tab, x, no) &&
			ft_check_block(tab, x, y, no));
}
