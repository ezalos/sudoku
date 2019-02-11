/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 14:32:09 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/07 16:47:56 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sudo.h"
void print_victory(void)
{
	write(1, _RED, 5);
	ft_putstr(" _______   _______   _________   _          _                     _______    _______ \n");
	ft_putstr("(  ____/  (  ___  )  \\__   __/  ( \\        ( \\        |\\     /|  (  ____ )  (  ____ \\\n");
	ft_putstr("| (       | (   ) |     ) (     | (        | (        | )   ( |  | (    )|  | (    \\/\n");
	ft_putstr("| (__     | (___) |     | |     | |        | |        | |   | |  | (____)|  | (__    \n");
	ft_putstr("|  __)    |  ___  |     | |     | |        | |        | |   | |  |     __)  |  __)   \n");
	ft_putstr("| (       | (   ) |     | |     | |        | |        | |   | |  | (\\ (     | (      \n");
	ft_putstr("| )       | )   ( |  ___) (___  | (____/\\  | (____/\\  | (___) |  | ) \\ \\__  | (____/\\\n");
	ft_putstr("|/        |/     \\|  \\_______/  (_______/  (_______/  \(_______)  |/   \\__/  (_______/\n");
	write(1, _RESET, 5);
}
void print_defeat(void)
{
	write(1, _GREEN, 5);
	ft_putstr(" _______               _______    _______    _______    _______    _______ \n");
	ft_putstr("(  ____ \\  |\\     /|  (  ____ \\  (  ____ \\  (  ____ \\  (  ____ \\  (  ____ \\\n");
	ft_putstr("| (    \\/  | )   ( |  | (    \\/  | (    \\/  | (    \\/  | (    \\/  | (    \\/\n");
	ft_putstr("| (_____   | |   | |  | |        | |        | (__      | (_____   | (_____ \n");
	ft_putstr("(_____  )  | |   | |  | |        | |        |  __)     (_____  )  (_____  )\n");
	ft_putstr("      ) |  | |   | |  | |        | |        | (              ) |        ) |\n");
	ft_putstr("/\\____) |  | (___) |  | (____/\\  | (____/\\  | (____/\\  /\\____) |  /\\____) |\n");
	ft_putstr("\\_______)  (_______)  (_______/  (_______/  (_______/  \\_______)  \\_______)\n");
	write(1, _RESET, 5);
}

void print_victory_or_defeat(int on)
{
	if (on)
		print_defeat();
	else
		print_victory();
}

int  main(int ac, char **av)
{
	t_sudo	*sudo;
	int		r_val;
	int		i;

	if (ac != 2)
		return (0);
	if (ONPTION)
		write(1, "\033[2J", 4);//clear screen
	if (!(sudo = read_sudo(av[1])))
		return (-1);
	r_val = brain(sudo);
	if (ONPTION)
	{
		print_grids(sudo);
		write(1, "\033[60;0H", 7);
		print_victory_or_defeat(r_val);
		printf("File was %s\n", av[1]);
	}
	else
	{
		i = -1;
		while (++i < 9)
			printf("%s\n", sudo->sol[0][i]);
	}
	wait_pls();
	return (0);
}
