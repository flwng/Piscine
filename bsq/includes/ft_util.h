/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:37:49 by mcossu            #+#    #+#             */
/*   Updated: 2020/11/11 19:37:58 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTIL_H
# define FT_UTIL_H

# include "char_input.h"

int		ft_atoi(char *str);
int		ft_translate(char c, t_validator *valid);
int		is_valid(char c, t_validator *valid);
int		ft_ctoi(char c, t_validator *valid);
char	ft_itoc(int nbr, t_validator *valid);
#endif
