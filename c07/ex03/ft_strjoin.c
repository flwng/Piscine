/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 16:59:25 by flwang            #+#    #+#             */
/*   Updated: 2020/11/11 16:59:27 by flwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char			*ft_strcat(char *dst, char *src)
{
	while (*src)
		*(dst++) = *(src++);
	return (dst);
}

char			*check(char *ret)
{
	if (!(ret = malloc(sizeof(char))))
		return (0);
	else
		return (ret);
}

char			*ft_strjoin(int size, char **strs, char *sep)
{
	char			*ret;
	char			*tmp;
	unsigned int	strs_len;
	long long		i;

	ret = 0;
	strs_len = 0;
	if (!size)
		check(ret);
	i = 0;
	while (i < size)
		strs_len += ft_strlen(strs[i++]);
	if (!(ret = (char *)malloc((strs_len + (size - 1) * ft_strlen(sep)) + 1)))
		return (0);
	tmp = ret;
	i = 0;
	while (i < size)
	{
		tmp = ft_strcat(tmp, strs[i++]);
		if (size != i)
			tmp = ft_strcat(tmp, sep);
	}
	*tmp = 0;
	return (ret);
}
