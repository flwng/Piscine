/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 11:55:23 by flwang            #+#    #+#             */
/*   Updated: 2020/11/04 11:55:25 by flwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_alpha(char *str)
{
	int i;
	int ritorno;

	i = 0;
	ritorno = 0;
	while (str[i] != '\0')
	{
		if (('@' < str[i] && str[i] < '[') || (96 < str[i] && str[i] < 123))
			i++;
		else
			break ;
	}
	ritorno = 0;
	if (str[i] == '\0')
		ritorno = 1;
	return (ritorno);
}
