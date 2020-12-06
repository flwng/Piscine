/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 14:10:36 by flwang            #+#    #+#             */
/*   Updated: 2020/10/23 14:11:13 by flwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int count;
	int temp;

	count = 0;
	while (count < size)
	{
		temp = tab[count];
		tab[count] = tab[size - 1];
		tab[size - 1] = temp;
		count++;
		size--;
	}
}
