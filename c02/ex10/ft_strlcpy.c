/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 11:57:35 by flwang            #+#    #+#             */
/*   Updated: 2020/11/04 11:57:37 by flwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int size_src;
	unsigned int i;

	size_src = 0;
	i = 0;
	while (src[size_src++] != '\0')
	{
	}
	if (size <= 0)
	{
	}
	else if (size == 1)
	{
		dest[0] = '\0';
	}
	else
	{
		while (i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (size_src - 1);
}
