/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 14:53:18 by mcossu            #+#    #+#             */
/*   Updated: 2020/11/11 19:43:21 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_input.h"
#include "ft_util.h"

#define MERR	0
#define MAPERR	2

int		read_first_line(char *path, int *len, char **first_line)
{
	int		file;
	char	curr;

	if ((file = open(path, O_RDONLY)) < 0)
		return (MAPERR);
	*len = 0;
	while (read(file, &curr, 1) && (curr != '\n'))
		(*len)++;
	close(file);
	if (!(*first_line = (char *)malloc((*len + 1) * sizeof(char))))
		return (0);
	if ((file = open(path, O_RDONLY)) < 0)
		return (MAPERR);
	*len = 0;
	while (read(file, &curr, 1) && curr != '\n')
		(*first_line)[(*len)++] = curr;
	(*first_line)[*len] = 0;
	close(file);
	return (1);
}

int		ft_len_sec(char *path)
{
	int		file;
	int		len;
	int		i;
	int		r_i;
	char	curr;

	if ((file = open(path, O_RDONLY)) < 0)
		return (0);
	len = 0;
	i = 0;
	while ((r_i = read(file, &curr, 1)) > 0 && (curr != '\n' || i == 0))
	{
		if (i == 1)
			len++;
		if (curr == '\n')
			i = 1;
	}
	if (r_i < 0)
		return (0);
	close(file);
	return (len);
}

int		read_sec_line(char *path, int *len)
{
	if (!(*len = ft_len_sec(path)))
		return (MAPERR);
	return (1);
}

int		ft_read_input(char *path, t_validator *valid, int **in_matrix, int j)
{
	int		file;
	int		i;
	char	curr;

	if ((file = open(path, O_RDONLY)) < 0)
		return (0);
	while (read(file, &curr, 1) > 0 && curr != '\n')
		i = 0;
	while (read(file, &curr, 1) > 0)
	{
		if (curr == '\n' && j != valid->line_l)
			return (MAPERR);
		if (curr == '\n')
			i++;
		if (curr == '\n')
			j = 0;
		if (!(is_valid(curr, valid) || curr == '\n') || i > valid->line_nbr)
			return (MAPERR + free_matrix(in_matrix, valid->line_nbr));
		if (curr != '\n' && i < valid->line_nbr)
			in_matrix[i][j++] = ft_ctoi(curr, valid);
	}
	close(file);
	if (i != valid->line_nbr)
		return (MAPERR);
	return (1);
}
