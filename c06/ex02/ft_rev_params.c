/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:20:22 by flwang            #+#    #+#             */
/*   Updated: 2020/11/05 15:20:24 by flwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_params(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i] != 0)
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		main(int argc, char **argv)
{
	int i;

	if (argc < 2)
	{
		return (0);
	}
	i = argc - 1;
	while (i > 0)
	{
		ft_rev_params(argv[i]);
		write(1, "\n", 1);
		i--;
	}
	return (0);
}
