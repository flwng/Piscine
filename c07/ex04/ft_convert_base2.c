/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usavoia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 16:05:36 by usavoia           #+#    #+#             */
/*   Updated: 2020/11/05 16:05:47 by usavoia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_base(char *base)
{
	char	*check;
	int		i;

	check = base;
	if (*base == 0 || (base + 1) == 0)
		return (0);
	while (*check)
	{
		if (*check == '+' || *check == '-'
				|| *check == ' ' || *check <= 31)
			return (0);
		i = 1;
		while (*(check + i))
		{
			if (*(check + i) == *check)
				return (0);
			i++;
		}
		check++;
	}
	return (1);
}

int		ft_strlen(char *str)
{
	char	*strptr;
	int		i;

	strptr = str;
	i = 0;
	while (*strptr != 0)
	{
		i++;
		strptr++;
	}
	return (i);
}

char	*cerca_in_base(char *base, char *to_find)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (*to_find == base[i])
			return (base + i);
		i++;
	}
	return (0);
}

int		ft_atoi_base(char *str, char *base)
{
	unsigned int	ret;
	int				neg;
	char			*ptr;

	ret = 0;
	neg = 1;
	if (check_base(base))
	{
		ptr = str;
		while (*ptr == ' ' || (*ptr >= 9 && *ptr <= 13))
			ptr++;
		while (*ptr == '-' || *ptr == '+')
		{
			if (*ptr == '-')
				neg *= -1;
			ptr++;
		}
		while (cerca_in_base(base, ptr))
		{
			ret *= ft_strlen(base);
			ret += (unsigned int)(cerca_in_base(base, ptr) - base);
			ptr++;
		}
	}
	return (int)(ret * neg);
}
