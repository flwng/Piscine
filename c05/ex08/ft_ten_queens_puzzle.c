/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 09:22:37 by flwang            #+#    #+#             */
/*   Updated: 2020/11/05 09:22:39 by flwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_queens(int *queens)
{
	int i;
	int j;

	i = 0;
	while (i < 10)
	{
		j = queens[i] + 48;
		write(1, &j, 1);
		i++;
	}
	write(1, "\n", 1);
}

int		check(int *queens, int index)
{
	int i;
	int j;

	if (index == 0)
		return (1);
	i = 0;
	while (i < index)
	{
		j = i + 1;
		while (j <= index)
		{
			if (queens[i] == queens[j])
				return (0);
			if (queens[j] - queens[i] == i - j ||
					queens[j] - queens[i] == j - i)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	solve(int *queens, int index, int i, int *res)
{
	while (i < 10)
	{
		queens[index] = i;
		if (check(queens, index))
		{
			if (index == 9)
			{
				print_queens(queens);
				*res += 1;
			}
			else
				solve(queens, index + 1, 0, res);
		}
		i++;
	}
}

int		ft_ten_queens_puzzle(void)
{
	int i;
	int res;
	int queens[10];

	res = 0;
	i = 0;
	while (i < 10)
		queens[i++] = 0;
	solve(queens, 0, 0, &res);
	return (res);
}
