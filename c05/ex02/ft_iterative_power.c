/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 09:18:19 by flwang            #+#    #+#             */
/*   Updated: 2020/11/05 09:18:52 by flwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int pow;

	pow = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (--power)
		pow *= nb;
	return (pow);
}
