/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 11:53:37 by flwang            #+#    #+#             */
/*   Updated: 2020/10/28 15:15:42 by flwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int count;
	int index;

	if (to_find[0] == 0)
		return (str);
	index = 0;
	while (str[index])
	{
		count = 0;
		while (str[index + count] == to_find[count])
		{
			if (to_find[count + 1] == 0)
				return (str + index);
			count++;
		}
		index++;
	}
	return (0);
}
