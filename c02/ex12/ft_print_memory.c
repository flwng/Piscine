/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 11:58:05 by flwang            #+#    #+#             */
/*   Updated: 2020/11/04 11:58:07 by flwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	stampa(char c)
{
	write(1, &c, 1);
}

void	addr_hex(void *addr)
{
	char	addr_c[15];
	long	addr_l;
	int		i;

	addr_l = (long)addr;
	i = 0;
	while (addr_l > 0)
	{
		addr_c[i] = addr_l % 16;
		if (addr_c[i] < 10)
			addr_c[i] += '0';
		else
			addr_c[i] += 87;
		addr_l = addr_l / 16;
		i++;
	}
	while (i < 15)
	{
		addr_c[i] = '0';
		i++;
	}
	while (--i >= 0)
		stampa(addr_c[i]);
}

void	linea_hex(char c)
{
	unsigned char	cast_char;
	char			hex1;
	char			hex2;

	cast_char = (unsigned char)c;
	hex1 = cast_char / 16;
	hex2 = cast_char % 16;
	if (hex1 < 10)
		stampa(hex1 + '0');
	else
		stampa(hex1 + 87);
	if (hex2 < 10)
		stampa(hex2 + '0');
	else
		stampa(hex2 + 87);
}

void	stampa_linea(void *addr, int size)
{
	int		i;
	int		spazi;
	char	*addr_c;

	addr_c = (char *)addr;
	i = 0;
	while (i < size)
	{
		linea_hex(addr_c[i++]);
		if (i % 2 == 0)
			stampa(' ');
	}
	spazi = ((16 - size) * 2) + (19 - size) / 2;
	while (--spazi > 0)
		stampa(' ');
	i = -1;
	while (++i < size)
	{
		if (addr_c[i] >= 32 && addr_c[i] <= 126)
			stampa(addr_c[i]);
		else
			stampa('.');
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int offset;
	unsigned int num_char;

	num_char = 16;
	offset = 0;
	while (size > 0)
	{
		if (size < 16)
		{
			num_char = size;
			size = 0;
		}
		else
			size -= 16;
		addr_hex(addr + offset);
		stampa(':');
		stampa(' ');
		stampa_linea(addr + offset, num_char);
		stampa('\n');
		offset += 16;
	}
	return (addr);
}
