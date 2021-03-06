/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 12:57:26 by cromalde          #+#    #+#             */
/*   Updated: 2020/10/24 16:16:09 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	stampa (int x, int y, char arr[y][x]);

void	ft_putchar(char c);

void	rush(int x, int y)
{
	char	arr[y][x];
	int		b;
	int		h;

	h = 0;
	while (h < y)
	{
		b = 0;
		while (b < x)
		{
			if ((h == 0 && b == 0) || (b == x - 1 && h == y - 1))
				arr[h][b] = '/';
			else if ((h == y - 1 && b == 0) || (b == x - 1 && h == 0))
				arr[h][b] = '\\';
			else if ((h == 0 || h == y - 1) && (b > 0 && b < x - 1))
				arr[h][b] = '*';
			else if ((h != 0 && h != y - 1) && (b == 0 || b == x - 1))
				arr[h][b] = '*';
			else
				arr[h][b] = ' ';
			b++;
		}
		h++;
	}
	stampa(x, y, arr);
}

void	stampa(int x, int y, char arr[y][x])
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (k < y)
	{
		i = 0;
		while (i < x)
		{
			ft_putchar(arr[k][i]);
			i++;
		}
		write(1, "\n", 1);
		k++;
	}
}
