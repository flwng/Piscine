/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:40:26 by mcossu            #+#    #+#             */
/*   Updated: 2020/11/11 19:40:36 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_util.h"

int		is_numeric(char c)
{
	return (c >= '0' && c <= '9');
}

int		ft_atoi(char *str)
{
	int result;

	result = 0;
	while (*str == '0')
		str++;
	while (is_numeric(*str))
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	if (*str)
		return (0);
	return (result);
}

int		ft_ctoi(char c, t_validator *valid)
{
	if (c == valid->empty)
		return (1);
	if (c == valid->obs)
		return (0);
	return (-2);
}

int		is_valid(char c, t_validator *valid)
{
	if (c == valid->empty || c == valid->obs)
		return (1);
	return (0);
}

char	ft_itoc(int nbr, t_validator *valid)
{
	if (nbr == 0)
		return (valid->obs);
	if (nbr == -1)
		return (valid->full);
	return (valid->empty);
}
