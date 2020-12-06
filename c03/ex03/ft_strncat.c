/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 10:41:20 by flwang            #+#    #+#             */
/*   Updated: 2020/10/28 15:15:20 by flwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int len;
	unsigned int i;

	len = 0;
	i = 0;
	while (dest[len] != 0)
	{
		len++;
	}
	while (src[i] != 0 && i < nb)
	{
		dest[len] = src[i];
		len++;
		i++;
	}
	dest[len] = 0;
	return (dest);
}
