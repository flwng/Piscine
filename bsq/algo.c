/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:33:16 by mcossu            #+#    #+#             */
/*   Updated: 2020/11/11 19:34:06 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"
#include "char_input.h"

int			minval(int r, int c, int **matrix)
{
	int min_val;

	min_val = matrix[r][c];
	if (min_val > matrix[r][c + 1])
		min_val = matrix[r][c + 1];
	if (min_val > matrix[r + 1][c])
		min_val = matrix[r + 1][c];
	return (min_val);
}

int			notzero(int r, int c, int **matrix)
{
	if (matrix[r + 1][c + 1] == 0)
		return (0);
	return (1);
}

t_solver	getval(t_solver *n_solver, int matrix_val, int r, int c)
{
	if (n_solver->max_value < matrix_val)
	{
		n_solver->max_value = matrix_val;
		n_solver->sq_row = r + 1;
		n_solver->sq_col = c + 1;
	}
	return (*n_solver);
}

void		getfirstone(int **matrix, t_solver *solver, t_validator *valid)
{
	int c;
	int r;

	r = 0;
	while (r < valid->line_nbr)
	{
		c = 0;
		while (c < valid->line_l)
		{
			if (matrix[r][c] == 1)
			{
				solver->max_value = 1;
				solver->sq_row = r;
				solver->sq_col = c;
				return ;
			}
			c++;
		}
		r++;
	}
}

t_solver	*solver(int **matrix, t_validator *valid, t_solver *n_solver)
{
	int r;
	int c;
	int min_val;

	min_val = 0;
	r = 0;
	n_solver->max_value = 0;
	getfirstone(matrix, n_solver, valid);
	while (r < valid->line_nbr - 1)
	{
		c = 0;
		while (c < valid->line_l - 1)
		{
			if (notzero(r, c, matrix))
			{
				min_val = minval(r, c, matrix);
				matrix[r + 1][c + 1] = min_val + 1;
				getval(n_solver, matrix[r + 1][c + 1], r, c);
			}
			c++;
		}
		r++;
	}
	return (n_solver);
}
