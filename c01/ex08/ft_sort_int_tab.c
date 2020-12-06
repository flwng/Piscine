/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 15:15:30 by flwang            #+#    #+#             */
/*   Updated: 2020/10/23 15:15:34 by flwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int count;
	int temp;
	int scan;

	count = 0;
	while (count < size)
	{
		scan = count + 1;
		while (scan < size)
		{
			temp = tab[count];
			if (temp > tab[scan])
			{
				temp = tab[scan];
				tab[scan] = tab[count];
				tab[count] = temp;
			}
			scan++;
		}
		count++;
	}
}
