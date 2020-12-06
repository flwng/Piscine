#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int ft_strlen(char *str)
{
    int len;
    
    len = 0;
    while (*str)
    {
        len++;
        str++;
    }
    return (len);
}

int	ft_count_triplets(char *str)// verifica quante triplette sono presenti nel numero in input
{
	int	a;
	int	triplets;

	a = ft_strlen(str);
	if (a > 0)// conta le triplette
	{
		if ((a % 3) == 0)
			triplets = (a / 3);
		else
			triplets = (a / 3) + 1;
		return (triplets);
	}
	return (0);
}


void	ft_set_matrix(char *str, int j, char **matrix)//inserisce nella matrice le triplette
{
	int	i;
	int	filler;
	int l;
	int index;

	filler = j - 1;
	while (filler >= 0)
	{
	    i = 0;
		while(i < 2)
	    {
			matrix[filler][i] = '0';
			i++;
	    }
		filler--;
	}
    filler = j - 1;
    l = ft_strlen(str) - 1;
    
	while (filler >= 0)
	{
		i = 2;
		while (i >= 0)
		{
			matrix[filler][i] = str[l];
			i--;
			l--;
		}
		filler--;
	}
	index = 0;
	while (index < 3)
	{
		//printf("%c", matrix[1][index]);
		index++;
	}
}

void	findkeyvalue(char matrix_nb, char *buff) //stampa valore nella matrice
{
	int i;

	i = 0;
	while (matrix_nb != buff[i])
		i++;
	while (matrix_nb == buff[i] || buff[i] == ' ' || (buff[i] >= 9 && buff[i] <= 13) || buff[i] == ':')
		i++;
	while (buff[i] >= 32 && buff[i] <= 126)
	{
		ft_putchar(buff[i]);
		i++;
	}
}

void ft_strstr(char *str, char *to_find)
{
	int count;
	int index;

	index = 0;
	while (str[index])
	{
		count = 0;
		while (str[index + count] == to_find[count])
		{
			count++;
		}
		if (to_find[count] == 0 && to_find[count - 1] == str[index + count - 1])
			break ;
		index++;
	}
	while (str[index + count] == ' ' || (str[index + count] >= 9 && str[index + count] <= 13) || str[index + count] == ':')
		count++;
	while (str[index + count] >= 32 && str[index + count] <= 126)
	{
		ft_putchar(str[index + count]);
		count++;
	}
}


void	ft_big_money(int ntrip, char *midc, int row, char *buff)
{
	int iter;
	int	len;

	iter = 0;
	len = ((ntrip - row - 1) * 3) + 1;
	midc = malloc(len);
	midc[len] = 0;
	midc[0] = '1';
	iter = 1;
	while (iter < len)
	{
		midc[iter] = '0';
		iter++;
	}
	ft_strstr(buff, midc);
	ft_putchar(',');
	ft_putchar(' ');
}

void	ft_create_tens(char *midc, int col, int ntrip, char *buff, char **matrix, int row)
{
	int len;
	int iter;

	iter = 0;
	midc[1] = matrix[row][col + 1];
	ft_strstr(buff, midc);
	if (row != ntrip - 1)
	{
		ft_putchar(' ');
		len = ((ntrip - row - 1) * 3) + 1;
		midc = malloc(len);
		midc[len] = 0;
		midc[0] = '1';
		iter = 1;
		while (iter < len)
		{
			midc[iter] = '0';
			iter++;
		}
		ft_strstr(buff, midc);
		ft_putchar(',');
		ft_putchar(' ');
		col++;
	}
}

void	ft_tens(char *midc, char **matrix, int row, int col, char *buff, int ntrip)
{
	if (matrix[row][col] != '0')
	{
		midc = malloc(2);
		midc[0] = matrix[row][col];
		if (midc[0] > '1')
		{
			midc[1] = '0';
			ft_strstr(buff, midc);
			ft_putchar('-');
		}
		else
			ft_create_tens(midc, col, ntrip, buff, matrix, row);
	}
}

void	ft_conv_manager(char **matrix, int col, int row, char *buff, int ntrip)
{
	char *midc;

	if (col != 1)
	{
		if (matrix[row][col] != '0')
		{
			findkeyvalue(matrix[row][col], buff);
			if (!(row == ntrip - 1 && col == 2))
				ft_putchar(' ');
			if (col == 0)
			{
				midc = "100";
				ft_strstr(buff, midc);
				ft_putchar(' ');
			}
		}
		if (row < ntrip - 1 && col == 2 && matrix[row][col - 1] != 48 && matrix[row][col - 2 != 48])// mette million billion thousand ecc...
			ft_big_money(ntrip, midc, row, buff);
	}
		else// decine
			ft_tens(midc, matrix, row, col, buff, ntrip);
}

void	ft_convert(int ntrip, char **matrix, char *buff)
{
	int row;
	int col;

	row = 0;
	while (row < ntrip)
	{
		col = 0;
		while (col < 3)
		{
			if (matrix[row][col] != 0)
			{
				ft_conv_manager(matrix, col, row, buff, ntrip);
			}
			col++;
		}
		row++;
	}
}


int	main(void)
{
	char	input[] = "10001";
	int ntrip;
	char buff[100000];
	int f_des;
	char **matrix;
	int i;

	ntrip = ft_count_triplets(input);
	matrix = (char **)malloc(ntrip * sizeof(char*));
	i = 0;
	while (i < ntrip)
	{
		matrix[i] = (char *)malloc(3 * sizeof(char));
		i++;
	}
	ft_set_matrix(input, ntrip, matrix);
	f_des = open("numbers.dict", O_RDWR);
	if (f_des == -1)
		printf("Failed to create");
	read(f_des, buff, 100000);
	ft_convert(ntrip, matrix, buff);
	
	
	return (0);
}