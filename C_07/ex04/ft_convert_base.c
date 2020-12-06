/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usavoia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 16:00:28 by usavoia           #+#    #+#             */
/*   Updated: 2020/11/05 19:04:49 by usavoia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_atoi_base(char *str, char *base);
int		check_base(char *base);
int		ft_strlen(char *str);

void	ft_putnbr(int nb, char *arr, unsigned int len, char **res)
{
	unsigned int nbr_unsigned;

	if (nb < 0)
	{
		nbr_unsigned = (unsigned int)(-1 * nb);
		**res = '-';
		(*res)++;
	}
	else
		nbr_unsigned = (unsigned int)nb;
	if (nbr_unsigned >= len)
	{
		ft_putnbr(nbr_unsigned / len, arr, len, res);
		ft_putnbr(nbr_unsigned % len, arr, len, res);
	}
	else
	{
		**res = (arr[nbr_unsigned]);
		(*res)++;
	}
}

char	*ft_putnbr_base(int nbr, char *base)
{
	int		l;
	int		i;
	int		tmp;
	char	*res;
	char	*tmp_ptr;

	res = 0;
	i = 0;
	l = ft_strlen(base);
	tmp = nbr;
	tmp_ptr = 0;
	while (tmp > 0)
	{
		tmp /= l;
		i++;
	}
	if (l != 0 && l != 1)
	{
		if (!(res = malloc((i * (sizeof(char)) + 1))))
			return (0);
		tmp_ptr = res;
		ft_putnbr(nbr, base, l, &tmp_ptr);
	}
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		dec_val;
	char	*ptr_base_from;
	char	*ptr_base_to;
	char	*res;

	ptr_base_from = base_from;
	ptr_base_to = base_to;
	res = 0;
	if (!(check_base(ptr_base_from)) || !(check_base(ptr_base_to)))
		return (NULL);
	dec_val = ft_atoi_base(nbr, ptr_base_from);
	res = ft_putnbr_base(dec_val, base_to);
	return (res);
}
