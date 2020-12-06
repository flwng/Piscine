/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_input.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:35:12 by mcossu            #+#    #+#             */
/*   Updated: 2020/11/11 19:35:21 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAR_INPUT_H
# define CHAR_INPUT_H

typedef struct	s_validator
{
	int		line_l;
	int		line_nbr;
	char	empty;
	char	obs;
	char	full;
}				t_validator;
#endif
