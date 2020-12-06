/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 12:43:11 by flwang            #+#    #+#             */
/*   Updated: 2020/10/29 15:05:34 by flwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *arr, unsigned int n)
{
	while (arr[n])
	{
		n++;
	}
	return (n);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int d;
	unsigned int s;
	unsigned int i;

	d = 0;
	s = 0;
	i = 0;
	d = ft_strlen(dest, d);
	s = ft_strlen(src, s);
	if (size <= d)
		s += size;
	else
		s += d;
	while (d + 1 < size && src[i])
	{
		dest[d] = src[i];
		d++;
		i++;
	}
	dest[d] = 0;
	return (s);
}
