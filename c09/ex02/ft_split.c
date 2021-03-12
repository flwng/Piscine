/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 17:00:03 by flwang            #+#    #+#             */
/*   Updated: 2020/11/11 17:00:04 by flwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strndup(char *src, int n)
{
	int		i;
	char	*copy;

	if (!src)
		return (NULL);
	i = 0;
	if (!(copy = (char *)malloc((n + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < n)
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

int		separator(char c, char *charset)
{
	int i;

	i = 0;
	if (c == '\0')
		return (1);
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int		n_words(char *str, char *charset)
{
	int i;
	int nbr;

	nbr = 0;
	if (!separator(str[0], charset))
		nbr++;
	i = 1;
	while (str[i] != 0)
	{
		if (!separator(str[i], charset) && (separator(str[i - 1], charset)))
			nbr++;
		i++;
	}
	return (nbr);
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		i;
	int		j;
	int		k;

	split = (char **)malloc((n_words(str, charset) + 1) * sizeof(char *));
	k = 0;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (!separator(str[i + j], charset))
			j++;
		if (j)
		{
			split[k] = ft_strndup(&str[i], j);
			k++;
			i = i + j;
		}
		i++;
	}
	split[k] = 0;
	return (split);
}
