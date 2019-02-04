/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 01:27:41 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/04 14:33:40 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sudo.h"

void		*malloc_sudo(t_sudo *sudo)
{
	sudo->lin = -1;
	sudo->sld = 0;
	if (!(sudo->sol = (char***)malloc(sizeof(char**) * 10)))
		return (NULL);
	if (!(sudo->sol = (char***)malloc(sizeof(char**) * 10)))
		return (NULL);
	sudo->grd = -1;
	while (++sudo->grd < 10)
	{
		if (!(sudo->sol[sudo->grd] = (char**)malloc(sizeof(char*) * 9)))
			return (NULL);
		sudo->col = -1;
		while (sudo->grd != 0 && ++sudo->col < 9)
		{
			if (!(sudo->sol[sudo->grd][sudo->col] =
				(char*)malloc(sizeof(char) * 10)))
				return (NULL);
			sudo->sol[sudo->grd][sudo->col][9] = 0;
		}
	}
	return (sudo);
}

t_sudo		*read_sudo(char *av)
{
	int		fd;
	char	*line;
	t_sudo	*sudo;

	if (!(sudo = (t_sudo*)malloc(sizeof(t_sudo))))
		return (NULL);
	if (!(malloc_sudo(sudo)))
		return (NULL);
	fd = open(av, O_RDONLY);
	sudo->lin = -1;
	while (get_next_line(fd, &line) == 1 && ++sudo->lin < 9)
	{
		if (!(sudo->sol[0][sudo->lin] = ft_strdup(line)))
			return (NULL);
		sudo->col = -1;
		while (++sudo->col < 9)
			if (sudo->sol[0][sudo->lin][sudo->col] <= '0'
			|| sudo->sol[0][sudo->lin][sudo->col] > '9')
				sudo->sol[0][sudo->lin][sudo->col] = ' ';
		//printf("%s\n", sudo->sol[0][sudo->lin]);
		free(line);
	}
	close(fd);
	return (sudo);
}

int			write_ghosts(t_sudo *s)
{
	s->grd = 0;
	while (++s->grd < 10)
		write_ghost(s, s->grd);
	return (0);
}

int			write_ghost(t_sudo *s, int grd)
{
	s->lin = -1;
	while (++s->lin < 9)
	{
		ft_memset(s->sol[grd][s->lin], ' ', 9);
		s->col = -1;
		while (++s->col < 9)
		{
			if (s->sol[0][s->lin][s->col] == grd + '0')
				s->sol[grd][s->lin][s->col] = grd + '0';
		}
	}
	return (0);
}
