/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:35:34 by flwang            #+#    #+#             */
/*   Updated: 2020/11/02 19:13:21 by flwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb, char *arr, unsigned int len)
{
	unsigned int nbr_unsigned;

	if (nb < 0)
	{
		nbr_unsigned = (unsigned int)(-1 * nb);
		ft_putchar('-');
	}
	else
		nbr_unsigned = (unsigned int)nb;
	if (nbr_unsigned >= len)
	{
		ft_putnbr(nbr_unsigned / len, arr, len);
		ft_putnbr(nbr_unsigned % len, arr, len);
	}
	else
		ft_putchar(arr[nbr_unsigned]);
}

int		ft_strlen(char *arr)
{
	unsigned int len;

	len = 0;
	while (*arr)
	{
		len++;
		arr++;
	}
	return (len);
}

int		is_valid(char *str)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			else if (str[i] == '+' || str[i] == '-')
				return (0);
			else if (str[j] == '+' || str[j] == '-')
				return (0);
			else if (str[i] <= 32 || str[j] <= 32)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int l;

	l = ft_strlen(base);
	if (l != 0 && l != 1 && is_valid(base) == 1)
		ft_putnbr(nbr, base, l);
}
