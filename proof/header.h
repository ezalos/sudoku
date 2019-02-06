/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 10:59:19 by gtaja             #+#    #+#             */
/*   Updated: 2018/09/08 10:59:23 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

int			ft_strlen(char *str);
void		ft_putchar(char c);
int			ft_fill_tab(int **tab, char **argv);
void		ft_show_tab(int **tab, char *result);
int			ft_can_place(int **tab, int x, int y, int no);

#endif
