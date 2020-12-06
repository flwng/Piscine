#include <unistd.h>

int main()
{
	char a;
	char b;

	a = 'a';

	while (a <= 'z')
	{
		if (a % 2 == 0)
		{
			b = a - 32;
			write(1, &b, 1);
		}
		else
			write(1, &a, 1);
		a++;
	}
	write(1, "\n", 1);
}
