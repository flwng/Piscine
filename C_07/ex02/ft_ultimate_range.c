/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usavoia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 12:49:36 by usavoia           #+#    #+#             */
/*   Updated: 2020/11/05 15:01:53 by usavoia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int ret;
	int *tmp;

	if (min >= max)
	{
		range = 0;
		return (0);
	}
	ret = ((long long)max - min);
	if (!(*range = (int*)malloc(sizeof(int) * ret)))
		return (-1);
	tmp = *range;
	while (min < max)
		*(tmp++) = min++;
	return (ret);
}
