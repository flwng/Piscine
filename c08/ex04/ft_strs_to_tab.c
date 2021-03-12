/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 18:51:48 by flwang            #+#    #+#             */
/*   Updated: 2020/11/09 18:53:23 by flwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int					get_size(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char				*ft_strdup(char *src)
{
	char	*res;
	int		i;

	i = 0;
	if (!(res = malloc(get_size(src) + 1)))
		return (0);
	while (src[i])
	{
		res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int				i;
	t_stock_str		*t_str;

	if (!(t_str = malloc(sizeof(struct s_stock_str) * (ac + 2))))
		return (0);
	i = 0;
	while (i < ac)
	{
		t_str[i].size = get_size(av[i]);
		t_str[i].str = av[i];
		t_str[i].copy = ft_strdup(av[i]);
		i++;
	}
	t_str[i].str = 0;
	return (t_str);
}
