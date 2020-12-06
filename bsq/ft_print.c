/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:39:00 by mcossu            #+#    #+#             */
/*   Updated: 2020/11/11 19:39:09 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

#define MERR	0
#define MAPERR	2

void	print_sol(int **matrix, t_validator *valid)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < valid->line_nbr)
	{
		j = 0;
		while (j < valid->line_l)
		{
			c = ft_itoc(matrix[i][j], valid);
			write(1, &c, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	print_error(int err)
{
	if (err == MAPERR)
		write(2, "map error\n", 10);
}
