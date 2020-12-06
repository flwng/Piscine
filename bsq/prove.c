/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:41:04 by mcossu            #+#    #+#             */
/*   Updated: 2020/11/11 19:41:29 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_input.h"
#include "solver.h"
#include "ft_util.h"
#include "ft_print.h"

void	find_sol(t_solver *solve, int **matrix)
{
	int i;
	int j;

	i = solve->sq_row;
	while (i > solve->sq_row - solve->max_value)
	{
		j = solve->sq_col;
		while (j > solve->sq_col - solve->max_value)
		{
			matrix[i][j] = -1;
			j--;
		}
		i--;
	}
}

void	initsolve(int **matrix, t_validator *valid, t_solver *solve)
{
	solver(matrix, valid, solve);
	if (solve->max_value != 0)
	{
		find_sol(solve, matrix);
		print_sol(matrix, valid);
		free_matrix(matrix, valid->line_nbr);
	}
	else
	{
		print_sol(matrix, valid);
		free_matrix(matrix, valid->line_nbr);
	}
}

void	solve_all(t_solver *solve, t_validator *valid, int argc, char **argv)
{
	int	c;
	int	err;
	int	**matrix;

	c = 1;
	if (argc > 1)
		while (c < argc)
		{
			if ((err = ft_fit_input(argv[c], valid, &matrix)) != 1)
				print_error(err);
			else
				initsolve(matrix, valid, solve);
			if (c + 1 != argc)
				write(1, "\n", 1);
			c++;
		}
	else
	{
		read_stdinput();
		if (ft_fit_input("./std_input.txt", valid, &matrix))
			initsolve(matrix, valid, solve);
	}
}

int		main(int argc, char **argv)
{
	t_validator	*valid;
	t_solver	*solve;

	if (!(solve = (t_solver *)malloc(sizeof(t_solver))))
		return (0);
	solve->max_value = 0;
	if (!(valid = (t_validator *)malloc(sizeof(t_validator))))
		return (0);
	solve_all(solve, valid, argc, argv);
	free(valid);
	free(solve);
}
