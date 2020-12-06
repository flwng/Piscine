/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:37:11 by mcossu            #+#    #+#             */
/*   Updated: 2020/11/11 19:37:20 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVER_H
# define SOLVER_H

# include "char_input.h"

typedef struct	s_solver
{
	int	max_value;
	int	sq_row;
	int	sq_col;
}				t_solver;

t_solver		*solver(int **matrix, t_validator *valid, t_solver *n_solver);
#endif
