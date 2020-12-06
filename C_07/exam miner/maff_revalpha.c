#include <unistd.h>

int main()
{
	char a;
	char b;

	a = 'z';
	while (a >= 'a')
	{
		if (a % 2 == 1)
		{
			b = a - 32;
			write(1, &b, 1);
		}
		else
			write(1, &a, 1);
		a--;
	}
}
