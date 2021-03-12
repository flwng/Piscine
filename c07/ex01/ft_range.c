/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 16:59:09 by flwang            #+#    #+#             */
/*   Updated: 2020/11/11 16:59:13 by flwang           ###   ########.fr       */
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
