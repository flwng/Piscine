/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 16:59:17 by flwang            #+#    #+#             */
/*   Updated: 2020/11/11 16:59:21 by flwang           ###   ########.fr       */
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
