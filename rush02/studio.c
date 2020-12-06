#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>


/* char	*ft_strstr(char *buf, char *n)
{
	int count;
	int index;
	int i;

	index = 0;
	i= 0;
	while (buf[index])
	{
		count = 0;
		while (buf[index + count] == n[count] && buf[index + count] != '\n')
		{
			if (n[count + 1] == 0)
			{
				
			}
			count++;
		}
		index++;
	}
	return (0);
} */

void ft_find10pow(char *buf, char *n)
{
	int index;
	int count;
	
}


int main(int argc, char **argv)
{
	int f_des;
	char buf[1000];
	int i;
	int j;
	int nb;
	int temp;
	int size;
	char *n;
	int iter;
	int len;
	char *str;

//open file
	f_des = open("numbers.dict", O_RDONLY);

	if (f_des == -1)
	{
		printf("Failed to create");
	}
//read all file
	read(f_des, buf, 1000);
	buf[999] = 0;

//close file
	close(f_des);

// test numbers00

//ft_strlen
	len = 0;
	while (argv[1][len])
		len++;

//main body
	j = 0;
	iter = 1;
	while (argv[1][j])
	{
		i = 0;
		while (argv[1][j] != buf[i])
			i++;
		while (buf[i] == argv[1][j] || buf[i] == ' ' || buf[i] == ':')
			i++;
		while (buf[i] != '\n')
		{	
			printf("%c", buf[i]);
			i++;
		}

// per trovare i terzini valori
		if (j != 2)
		{
			n = malloc(sizeof(char) * len);
			n[0] = '1';
			while (iter < len)
			{
				n[iter] = '0';
				iter++;
			}
			n[iter] = '\0';
		}
		
		str = ft_strstr(buf, n);
		printf("%s", str);
		j++;
	}

/*	while (buf[i] != n)
	{
		i++;
	}
	while (buf[i] == n || buf[i] == ' ' || buf[i] == ':')
	{
		i++;
	}
	while (buf[i] != '\n')
	{	
		printf("%c", buf[i]);
		i++;
	}
*/
	return (0);
}
