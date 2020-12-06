/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:35:45 by mcossu            #+#    #+#             */
/*   Updated: 2020/11/11 19:35:53 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
# define FT_PRINT_H

# include "char_input.h"
# include "ft_util.h"
# include <unistd.h>

void	print_sol(int **matrix, t_validator *valid);
void	print_error(int err);
#endif
