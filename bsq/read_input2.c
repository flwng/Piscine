/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:42:02 by mcossu            #+#    #+#             */
/*   Updated: 2020/11/11 19:42:16 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_input.h"

int		**ft_malloc_matrix(int line_l, int line_nbr)
{
	int **in_matrix;
	int i;

	i = 0;
	if (!(in_matrix = (int **)malloc(sizeof(int *) * (line_nbr + 1))))
		return (0);
	while (i < line_nbr)
	{
		in_matrix[i] = 0;
		i++;
	}
	i = 0;
	while (i < line_nbr)
	{
		if (!(in_matrix[i] = (int *)malloc((line_l + 1) * sizeof(int))))
		{
			free_matrix(in_matrix, i);
			return (0);
		}
		i++;
	}
	return (in_matrix);
}

int		parse_first(char *first, t_validator *valid)
{
	int		i;

	i = 0;
	while (first[i])
		i++;
	if (i < 4)
		return (MAPERR);
	if (!(first[i - 1] != first[i - 2] && first[i - 2] != first[i - 3]
		&& first[i - 1] != first[i - 3]))
		return (MAPERR);
	if ((((first[i - 1] < 32) && (first[i - 1] >= 0)) || first[i - 1] == 127) ||
		(((first[i - 2] < 32) && (first[i - 2] >= 0)) || first[i - 2] == 127) ||
		(((first[i - 3] < 32) && (first[i - 3] >= 0)) || first[i - 3] == 127))
		return (MAPERR);
	valid->empty = first[i - 3];
	valid->obs = first[i - 2];
	valid->full = first[i - 1];
	first[i - 3] = 0;
	if (!(valid->line_nbr = ft_atoi(first)))
		return (MAPERR);
	return (1);
}

int		ft_fit_input(char *path, t_validator *valid, int ***in_matrix)
{
	int		res;
	int		len;
	char	*first;

	len = 0;
	if ((res = read_first_line(path, &len, &first)) == 0)
		return (MERR);
	if (res != 1)
		return (MAPERR);
	if ((res = parse_first(first, valid)) != 1)
		return (res);
	free(first);
	if (!read_sec_line(path, &len) || !len)
		return (MAPERR);
	valid->line_l = len;
	if (!(*in_matrix = ft_malloc_matrix(valid->line_l, valid->line_nbr)))
		return (MERR);
	if ((res = ft_read_input(path, valid, *in_matrix, 0)) != 1)
		return (res);
	return (1);
}

void	read_stdinput(void)
{
	char	temp;
	int		fd;

	fd = open("./std_input.txt", O_RDWR | O_CREAT, 0644);
	while (read(STDIN_FILENO, &temp, 1))
		write(fd, &temp, 1);
	close(fd);
}
