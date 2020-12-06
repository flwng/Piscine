#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
	char *buff;
	char temp;
	char *strstr;
	int i;
	int k;
	int fd;

	i = 0;
	fd = open("./std_input.txt", O_RDWR | O_CREAT, 0644);
	while (read(STDIN_FILENO, &temp, 1) > 0)
		write(fd, &temp, 1);
	close (fd);
	i = 0;
	fd = open("./std_input.txt", O_RDONLY);
	while (read(fd, buff, 1) > 0)
		i++;
	buff = malloc(i + 1);
	close(fd);
	fd = open("./std_input.txt", O_RDONLY);
	read(fd, buff, i);
	printf("%s", buff);
}