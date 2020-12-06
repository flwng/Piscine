/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usavoia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 11:52:03 by usavoia           #+#    #+#             */
/*   Updated: 2020/11/04 12:48:48 by usavoia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *ret;
	int *tmp;

	if (min >= max)
		return (0);
	if (!(ret = (int*)malloc(sizeof(int) * ((long long)max - min))))
		return (0);
	tmp = ret;
	while (min < max)
		*(tmp++) = min++;
	return (ret);
}
