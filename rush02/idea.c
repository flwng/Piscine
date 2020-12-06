#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>




int main()
{
	int row;
	int col;
	int i;
	int f_des;
	int len;
	char buf[1000];
	char a[3][3] = {{1, 2, 3},
					{4, 5, 6},
					{7, 8, 9}};

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
//main body
	row = 0;
	i = 0;
	while (row < 3)
	{
		col = 0;
		while (col < 3)
		{
			while (a[row][col] != buf[i])
				i++; 
			while (buf[i] == a[row][col] || buf[i] == ' ' || buf[i] == ':')
				i++;
			while (buf[i] != '\n')
			{	
				printf("%c", buf[i]);
				i++;
			}
			col++;
		}
		row++;
	}
}