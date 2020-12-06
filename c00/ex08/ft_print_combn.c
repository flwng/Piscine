/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 11:40:26 by flwang            #+#    #+#             */
/*   Updated: 2020/10/25 19:47:24 by flwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putchar(char c)
{
	write(1, &c, 1);
}

void	print(int index, int size, int arr[size])
{
	while (index < size)
	{
		putchar(arr[index] + '0');
		index++;
	}
	if (arr[0] != 9 - size + 1)
	{
		putchar(',');
		putchar(' ');
	}
}

void	stampa(int n, int arr[n])
{
	int i;
	int	stmp;

	i = 0;
	stmp = 0;
	while (i < n - 1)
	{
		if (arr[i] < arr[i + 1])
			stmp = 1;
		else
		{
			stmp = 0;
			break ;
		}
		i++;
	}
	if (stmp == 1)
	{
		i = 0;
		print(i, n, arr);
	}
}

void	creaciclo(int n, int k, int arr[n])
{
	if (k < n - 1)
	{
		arr[k] = k;
		while (arr[k] <= 9)
		{
			if (!((arr[0] <= 9 - n + 1)))
				break ;
			else
			{
				creaciclo(n, k + 1, arr);
				arr[k]++;
			}
		}
	}
	else
	{
		arr[k] = k;
		while (arr[k] <= 9)
		{
			stampa(n, arr);
			arr[k]++;
		}
	}
}

void	ft_print_combn(int n)
{
	int arr[n];
	int a;

	a = '0';
	if (n == 1)
	{
		while (a <= '9')
		{
			putchar(a);
			if (a != '9')
			{
				write(1, ", ", 2);
			}
			a++;
		}
	}
	if (n < 10 && n > 0)
	{
		creaciclo(n, 0, arr);
	}
	else
	{
		return ;
	}
}
