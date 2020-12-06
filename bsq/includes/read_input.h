/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:39:51 by mcossu            #+#    #+#             */
/*   Updated: 2020/11/11 19:39:57 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_INPUT_H
# define READ_INPUT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "char_input.h"
# include "ft_util.h"
# include "ft_free.h"
# define MERR	0
# define MAPERR	2

int		read_first_line(char *path, int *len, char **first_line);
int		read_sec_line(char *path, int *len);
int		**ft_malloc_matrix(int line_l, int line_nbr);
int		ft_fit_input(char *path, t_validator *valid, int ***in_matrix);
int		parse_first(char *first, t_validator *valid);
int		ft_read_input(char *path, t_validator *valid, int **in_matrix, int j);
void	read_stdinput();
#endif
