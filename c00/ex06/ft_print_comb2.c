/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 10:52:25 by flwang            #+#    #+#             */
/*   Updated: 2020/10/25 14:27:17 by flwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <unistd.h>

void	printn(int n)
{
	char a;
	char b;

	a = n / 10 + 48;
	b = n % 10 + 48;
	write(1, &a, 1);
	write(1, &b, 1);
}

void	ft_print_comb2(void)
{
	int q;
	int w;

	q = 0;
	while (q <= 99)
	{
		w = q + 1;
		while (w <= 99)
		{
			printn(q);
			write(1, " ", 1);
			printn(w);
			if (q == 98 && w == 99)
				break ;
			else
			{
				write(1, ", ", 2);
			}
			w++;
		}
		q++;
	}
}
