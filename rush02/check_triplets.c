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

void	ft_print_error(char *error)
{
	int i;

	i = 0;
	while (error[i])
	{
		ft_putchar(error[i]);
		i++;
	}
}

int		ft_is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_check_dictionary(char *dictionary)
{
	int i;

	i = 0;
	while (dictionary[i] != 0)
	{
		while (dictionary[i] != ':')
		{
			if (!(ft_is_number(dictionary[i])) && !(dictionary[i] == ' '))
			{
				ft_print_error("Dict Error\n");
				return (0);
			}
			if (ft_is_number(dictionary[i]) && !(ft_is_number(dictionary[i - 1])))
			{
				if (!(dictionary[i - 1] == 0) && !(dictionary[i - 1] == '\n'))
				{
					ft_print_error("Dict Error\n");
					return (0);
				}
			}
			i++;
		}
		while (dictionary[i] != '\n')
			i++;
		i++;
	}
	return (1);
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
		index++;
	}
}

void	findkeyvalue(char matrix_nb, char *buff) //stampa valore nella matrice
{
	int i;
	int flag;

	flag = 0;
	i = 0;
	while (matrix_nb != buff[i])
		i++;
	while (matrix_nb == buff[i] || buff[i] == ' ' || (buff[i] >= 9 && buff[i] <= 13) || buff[i] == ':')
		i++;
	while (buff[i] >= 32 && buff[i] < 127)
	{
		if (buff[i] < 0 || (buff[i] > 32 && buff[i] <= 126))
		{
			ft_putchar(buff[i]);
			flag = 0;
		}
		if ((buff[i] == ' '|| (buff[i] >= 9 && buff[i] <= 13)) && flag == 0 && buff[i + 1] != 0)
		{
			ft_putchar(' ');
			flag = 1;
		}
		i++;
	}
}

int ft_strstr(char *str, char *to_find)
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
	if (str[index] == 0)
		return (0);
	while (str[index + count] == ' ' || (str[index + count] >= 9 && str[index + count] <= 13) || str[index + count] == ':')
		count++;
	while (str[index + count] >= 32 && str[index + count] <= 126)
	{
		ft_putchar(str[index + count]);
		count++;
	}
	return (0);
}


void	ft_convert(int ntrip, char **matrix, char *buff)
{
	int row;
	int col;
	int i;
	int len;
	int iter;
	char *midc;

	row = 0;
	while (row < ntrip)
	{
		col = 0;
		while (col < 3)
		{
			if (matrix[row][col] != 0)
			{
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
					if (row < ntrip - 1 && col == 2 && matrix[row][col - 1] != '0' && matrix[row][col - 2])
					{
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
						if (ft_strstr(buff, midc) == 1)
						{
							if (row != ntrip - 1)
							{
								ft_putchar(',');
								ft_putchar(' ');
							}
						}
						else
							ft_print_error("Dict Error\n");
					}
				}
				else
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
						{
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
								
							}
							col++;
						}
					}
				}
			}
			col++;
		}
		row++;
	}

}


int	main(void)
{
	char	input[] = "1000000000";
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
		write(1, "Failed to create", 16);
	read(f_des, buff, 100000);;
	if (ft_check_dictionary(buff))
		ft_convert(ntrip, matrix, buff);
	return (0);
}